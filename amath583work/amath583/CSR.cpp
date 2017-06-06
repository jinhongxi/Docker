//
// This file is part of the course materials for AMATH483/583 at the University
// of Washington,
// Spring 2017
//
// Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0
// International License
// https://creativecommons.org/licenses/by-nc-sa/4.0/
//
// Author: Andrew Lumsdaine
//
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

#include "CSR.hpp"
#include "Vector.hpp"

Vector operator*(const CSRMatrix& A, const Vector& x) {
  assert(A.numCols() == x.numRows());

  Vector y(A.numRows(), 0.0);
  matvec(A, x, y);

  return y;
}

void matvec(const CSRMatrix& A, const Vector& x, Vector& y) { A.matvec(x, y); }

void piscetize(CSRMatrix& A, size_t xpoints, size_t ypoints) {
  assert(A.numRows() == A.numCols());
  assert(xpoints * ypoints == A.numRows());

  A.clear();
  A.openForPushBack();

  for (size_t j = 0; j < xpoints; j++) {
    for (size_t k = 0; k < ypoints; k++) {
      size_t jrow = j * ypoints + k;

      if (j != 0) {
        size_t jcol = (j - 1) * ypoints + k;
        A.push_back(jrow, jcol, -1.0);
      }
      if (k != 0) {
        size_t jcol = j * ypoints + (k - 1);
        A.push_back(jrow, jcol, -1.0);
      }

      A.push_back(jrow, jrow, 4.0);

      if (k != ypoints - 1) {
        size_t jcol = j * ypoints + (k + 1);
        A.push_back(jrow, jcol, -1.0);
      }
      if (j != xpoints - 1) {
        size_t jcol = (j + 1) * ypoints + k;
        A.push_back(jrow, jcol, -1.0);
      }
    }
  }
  A.closeForPushBack();
}

void writeMatrix(const CSRMatrix& A, const std::string& filename) {
  std::ofstream outputFile(filename);
  streamMatrix(A, outputFile);
  outputFile.close();
}

void streamMatrix(const CSRMatrix& A) { A.streamMatrix(std::cout); }

void streamMatrix(const CSRMatrix& A, std::ostream& outputFile) { A.streamMatrix(outputFile); }
