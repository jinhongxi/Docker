#include "CSRMatrix.hpp"
#include "Vector.hpp"

Vector operator*(const CSRMatrix& A, const Vector& x) {
    assert(A.numCols() == x.numRows());
    
    Vector y(A.numRows());
    zeroize(y);
    matvec(A, x, y);
    
    return y;
}

void matvec(const CSRMatrix& A, const Vector& x, Vector& y) {
    A.matvec(x, y);
}


void piscetize(CSRMatrix& A, int xpoints, int ypoints) {
    assert(A.numRows() == A.numCols());
    assert(xpoints*ypoints == A.numRows());
    
    A.clear();
    
    for (int j = 0; j < xpoints; j++) {
        for (int k = 0; k < ypoints; k++) {
            int jrow = j*ypoints + k;
            
            if (j != 0) {
                int jcol = (j-1)*ypoints + k;
                A.push_back(jrow, jcol, -1.0);
            }
            if (k != 0) {
                int jcol = j*ypoints + (k-1);
                A.push_back(jrow, jcol, -1.0);
            }
            
            A.push_back(jrow, jrow, 4.0);
            
            if (k != ypoints-1) {
                int jcol = j*ypoints + (k+1);
                A.push_back(jrow, jcol, -1.0);
            }
            if (j != xpoints-1) {
                int jcol = (j+1)*ypoints + k;
                A.push_back(jrow, jcol, -1.0);
            }
        }
    }
}


void writeMatrix(const CSRMatrix& A, const std::string& filename) {
    std::ofstream outputFile(filename);
    streamMatrix(A, outputFile);
    outputFile.close();
}

void streamMatrix(const CSRMatrix&A) {
    A.streamMatrix(std::cout);
}

void streamMatrix(const CSRMatrix&A, std::ostream& outputFile) {
    A.streamMatrix(outputFile);
}
