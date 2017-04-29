#ifndef AOSMATRIX_HPP
#define AOSMATRIX_HPP

#include <cassert>
#include <vector>
#include <iostream>
#include <fstream>

#include "Vector.hpp"


class AOSMatrix {
public:
    AOSMatrix(int M, int N): iRows(M), jCols(N) {}
    
    void push_back(int i, int j, double val){
        assert(i < iRows && i >= 0);
        assert(j < jCols && j >= 0);
        
        Element elem = {i, j, val};
        arrayData.push_back(elem);
    }
    
    void clear() {
        arrayData.clear();
    }
    
    void reserve(int n) {
        assert(n >= 0);
        
        arrayData.reserve(n);
    }
    
    int numRows() const { return iRows; }
    int numCols() const { return jCols; }
    int numNonzeros() const { return arrayData.size(); }
    
    void matvec(const Vector& x, Vector& y) const {
        for (int k = 0; k < arrayData.size(); ++k) {
            y(arrayData[k].row) += arrayData[k].val * x(arrayData[k].col);
        }
    }
    
    void streamMatrix(std::ostream& outputFile) const {
        
        outputFile << "AMATH 583 AOSMATRIX" << std::endl;
        outputFile << iRows << " " << jCols << std::endl;
        
        // Write data
        for (int i = 0; i < arrayData.size(); ++i) {
            outputFile << arrayData[i].row << " ";
            outputFile << arrayData[i].col << " ";
            outputFile << arrayData[i].val << " ";
            outputFile << std::endl;
        }
        
        // Write tailer
        outputFile << "THIS IS THE END" << std::endl;
    }
    
private:
    class Element {
    public:
        int row, col;
        double val;
    };
    
    int iRows, jCols;
    std::vector<Element> arrayData;
};


Vector operator*(const AOSMatrix& A, const Vector& x);
void matvec(const AOSMatrix& A, const Vector& x, Vector& y);
void piscetize(AOSMatrix& A, int xpoints, int ypoints);
void writeMatrix(const AOSMatrix& A, const std::string& filename);
void streamMatrix(const AOSMatrix& A);
void streamMatrix(const AOSMatrix& A, std::ostream& outputFile);

#endif
