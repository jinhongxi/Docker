//
// This file is part of the course materials for AMATH483/583 at the University of Washington,
// Spring 2017
//
// Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
// https://creativecommons.org/licenses/by-nc-sa/4.0/
//

#if !defined(MATRIX_HPP)
#define MATRIX_HPP

#include <vector>

class Matrix {
public: 
  Matrix(int M, int N) : iRows(M), jCols(N), arrayData(iRows*jCols) {}

  double &operator()(int i, int j) { return arrayData[i*jCols + j]; }
  
  int numRows() { return iRows; }
  int numCols() { return jCols; }

private:
  int iRows, jCols;
  std::vector<double> arrayData;
};

#endif // MATRIX_HPP
