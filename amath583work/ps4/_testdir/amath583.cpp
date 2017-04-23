//
// This file is part of the course materials for AMATH483/583 at the University of Washington,
// Spring 2017
//
// Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
// https://creativecommons.org/licenses/by-nc-sa/4.0/
//
// Author: Andrew Lumsdaine
// 
#include "Vector.cpp"
#include "Matrix.hpp"
#include <cassert>

void matvec(const Matrix& A, const Vector& x, Vector& y) {
    for (int i = 0; i < A.numRows(); ++i)
    {
        for (int j = 0; j < x.numRows(); ++j)
        {
            y(i) += A(i, j) * x(j);
        }
    }
}


Vector operator* (const Matrix& A, const Vector& x) {
    assert(A.numCols() == x.numRows());
    
    Vector y(A.numRows());
    for (int i = 0; i < y.numRows(); ++i) y(i) = 0.0;
    
    matvec(A, x, y);
    
    return y;
}
