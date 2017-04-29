#ifndef CSRMATRIX_HPP
#define CSRMATRIX_HPP

#include <cassert>
#include <vector>
#include <iostream>
#include <fstream>

#include "Vector.hpp"


class CSRMatrix {
public:
    CSRMatrix(int M, int N): iRows(M), jCols(N), rowIndices(iRows + 1, 0) {}
    
    void openForPushBack() { is_open = true; }
    void closeForPushBack() {
        is_open = false;
        for (int i = 0; i < iRows; ++i) rowIndices[i + 1] += rowIndices[i];
        for (int i = iRows; i > 0; --i) rowIndices[i] = rowIndices[i - 1];
        rowIndices[0] = 0;
    }
    void push_back(int i, int j, double val){
        assert(i < iRows && i >= 0);
        assert(j < jCols && j >= 0);
        assert(is_open);
        
        ++rowIndices[i];
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
        for (int i = 0; i < iRows; ++i) {
            for (int j = rowIndices[i]; j < rowIndices[i + 1]; ++j) {
                y(i) += arrayData[j] * x(colIndices[j]);
            }
        }
    }
    
    void streamMatrix(std::ostream& outputFile) const {
        
        outputFile << "AMATH 583 CSRMATRIX" << std::endl;
        outputFile << iRows << " " << jCols << std::endl;
        
        // Write data
        for (int i = 0; i < iRows; ++i) {
            for (int j = rowIndices[i]; j < rowIndices[i + 1]; ++j) {
                outputFile << i << " ";
                outputFile << colIndices[j] << " ";
                outputFile << arrayData[j] << " ";
                outputFile << std::endl;
            }
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


Vector operator*(const CSRMatrix& A, const Vector& x);
void matvec(const CSRMatrix& A, const Vector& x, Vector& y);
void piscetize(CSRMatrix& A, int xpoints, int ypoints);
void writeMatrix(const CSRMatrix& A, const std::string& filename);
void streamMatrix(const CSRMatrix& A);
void streamMatrix(const CSRMatrix& A, std::ostream& outputFile);

#endif
