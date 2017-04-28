#ifndef CSCMATRIX_HPP
#define CSCMATRIX_HPP

#include <cassert>
#include <vector>
#include <iostream>
#include <fstream>

#include "Vector.hpp"


class CSCMatrix {
public:
    CSCMatrix(int M, int N): iRows(M), jCols(N) {}
    
    void openForPushBack() { is_open = true; }
    void closeForPushBack() { is_open = false; }
    void push_back(int i, int j, double val){
        assert(i < iRows && i >= 0);
        assert(j < jCols && j >= 0);
        
        rowIndices.push_back(i);
        colIndices.push_back(j);
        arrayData.push_back(val);
    }
    
    void clear() {
        rowIndices.clear();
        colIndices.clear();
        arrayData.clear();
    }
    
    void reserve(int n) {
        assert(n >= 0);
        
        rowIndices.reserve(n);
        colIndices.reserve(n);
        arrayData.reserve(n);
    }
    
    int numRows() const { return iRows; }
    int numCols() const { return jCols; }
    int numNonzeros() const { return arrayData.size(); }
    
    void matvec(const Vector& x, Vector& y) const {
        for (int k = 0; k < arrayData.size(); ++k) {
            y(rowIndices[k]) += arrayData[k] * x(colIndices[k]);
        }
    }
    
    void streamMatrix(std::ostream& outputFile) const {
        
        outputFile << "AMATH 583 CSCMATRIX" << std::endl;
        outputFile << iRows << " " << jCols << std::endl;
        
        // Write data
        for (int i = 0; i < arrayData.size(); ++i) {
            outputFile << rowIndices[i] << " ";
            outputFile << colIndices[i] << " ";
            outputFile << arrayData[i] << " ";
            outputFile << std::endl;
        }
        
        // Write tailer
        outputFile << "THIS IS THE END" << std::endl;
    }
    
private:
    int iRows, jCols;
    bool is_open;
    std::vector<int> rowIndices, colIndices;
    std::vector<double> arrayData;
};


Vector operator*(const CSCMatrix& A, const Vector& x);
void matvec(const CSCMatrix& A, const Vector& x, Vector& y);
void piscetize(CSCMatrix& A, int xpoints, int ypoints);
void writeMatrix(const CSCMatrix& A, const std::string& filename);
void streamMatrix(const CSCMatrix& A);
void streamMatrix(const CSCMatrix& A, std::ostream& outputFile);

#endif
