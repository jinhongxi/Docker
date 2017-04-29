#ifndef CSCMATRIX_HPP
#define CSCMATRIX_HPP

#include <cassert>
#include <vector>
#include <iostream>
#include <fstream>

#include "Vector.hpp"


class CSCMatrix {
public:
    // BEGIN CHANGE
    CSCMatrix(int M, int N): iRows(M), jCols(N), colIndices(jCols + 1, 0) {}
    
    void openForPushBack() { is_open = true; }
    void closeForPushBack() {
        is_open = false;
        std::vector<int> rowCpy = rowIndices;
        for (int i = 0; i < jCols; ++i) colIndices[i + 1] += colIndices[i];
        for (int i = jCols; i > 0; --i)
        {
            colIndices[i] = colIndices[i - 1];
        }
        colIndices[0] = 0;
    }
    void push_back(int i, int j, double val){
        assert(i < iRows && i >= 0);
        assert(j < jCols && j >= 0);
        assert(is_open);
        
        std::vector<int>::iterator pt1 = rowIndices.begin();
        std::vector<double>::iterator pt2 = arrayData.begin();
        for (int r = 0; r < j; ++r)
        {
            pt1 += colIndices[r];
            pt2 += colIndices[r];
        }
        rowIndices.insert(pt1, i);
        arrayData.insert(pt2, val);
        ++colIndices[j];
    }
    // END CHANGE
    
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
    
    //BEGIN CHANGE
    void matvec(const Vector& x, Vector& y) const {
        for (int j = 0; j < jCols; ++j) {
            for (int i = colIndices[j]; i < colIndices[j + 1]; ++i) {
                y(rowIndices[i]) += arrayData[i] * x(j);
            }
        }
    }
    
    void streamMatrix(std::ostream& outputFile) const {
        
        outputFile << "AMATH 583 CSCMATRIX" << std::endl;
        outputFile << iRows << " " << jCols << std::endl;
        
        // Write data
        for (int j = 0; j < jCols; ++j) {
            for (int i = colIndices[j]; i < colIndices[j + 1]; ++i) {
                outputFile << rowIndices[i] << " ";
                outputFile << j << " ";
                outputFile << arrayData[i] << " ";
                outputFile << std::endl;
            }
        }
        
        // Write tailer
        outputFile << "THIS IS THE END" << std::endl;
    }
    // END CHANGE
    
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
