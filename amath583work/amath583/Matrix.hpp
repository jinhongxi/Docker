//
// This file is part of the course materials for AMATH483/583 at the University of Washington,
// Spring 2017
//
// Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
// https://creativecommons.org/licenses/by-nc-sa/4.0/
//
// Author: Andrew Lumsdaine
//
#if !defined(__MATRIX_HPP)
#define __MATRIX_HPP

#include <vector>
#include <string>
#include <iostream>
#include "Vector.hpp"

#if !defined(SLOWMATRIX)
class Matrix {
public:
  explicit Matrix(size_t M, size_t N) : iRows(M), jCols(N), arrayData(iRows*jCols) {}
  explicit Matrix(size_t M, size_t N, double init) : iRows(M), jCols(N), arrayData(iRows*jCols, init) {}

        double &operator()(size_t i, size_t j)       { return arrayData[i*jCols + j]; }
  const double &operator()(size_t i, size_t j) const { return arrayData[i*jCols + j]; }

  size_t numRows() const { return iRows; }
  size_t numCols() const { return jCols; }

private:
  size_t iRows, jCols;
  std::vector<double> arrayData;
};
#else
class Matrix {
public:
  Matrix(size_t rows, size_t cols) :
    iRows(rows), jCols(cols), arrayData(iRows, std::vector<double>(jCols)) {}
  Matrix(size_t rows, size_t cols, double init) :
    iRows(rows), jCols(cols), arrayData(iRows, std::vector<double>(jCols), init) {}

  double &operator()(size_t i, size_t j) { return arrayData[i][j]; }
  const double &operator()(size_t i, size_t j) const { return arrayData[i][j]; }

  size_t numRows() const { return iRows; }
  size_t numCols() const { return jCols; }

private:
  size_t iRows, jCols;
  std::vector<std::vector<double> > arrayData;
};
#endif


Matrix operator*(const Matrix& A, const Matrix &B);
Matrix operator+(const Matrix& A, const Matrix &B);
Matrix operator-(const Matrix& A, const Matrix &B);
double frobeniusNorm(const Matrix& A);
void basicMultiply(const Matrix& A, const Matrix &B, Matrix& C);
void basicThreadedMultiply(const Matrix& A, const Matrix&B, Matrix&C);
void hoistedMultiply(const Matrix& A, const Matrix &B, Matrix& C);
void tiledMultiply2x2(const Matrix& A, const Matrix&B, Matrix&C);
void hoistedTiledMultiply2x2(const Matrix& A, const Matrix&B, Matrix&C);
void blockedTiledMultiply2x2(const Matrix& A, const Matrix&B, Matrix&C);
void tiledMultiply2x4(const Matrix& A, const Matrix&B, Matrix&C);
void tiledMultiply4x2(const Matrix& A, const Matrix&B, Matrix&C);
void tiledMultiply4x4(const Matrix& A, const Matrix&B, Matrix&C);
void copyBlockedTiledMultiply2x2(const Matrix& A, const Matrix&B, Matrix&C);
void hoistedBlockedTiledMultiply2x2(const Matrix& A, const Matrix&B, Matrix&C);
void hoistedCopyBlockedTiledMultiply2x2(const Matrix& A, const Matrix&B, Matrix&C);
void hoistedCopyBlockedTiledMultiply2x2AVX(const Matrix& A, const Matrix&B, Matrix&C);
void hoistedCopyBlockedTiledMultiply4x4(const Matrix& A, const Matrix&B, Matrix&C);
void hoistedCopyBlockedTiledMultiply4x4AVX(const Matrix& A, const Matrix&B, Matrix&C);
double oneNorm(const Matrix& A);
double infinityNorm(const Matrix& A);
double frobeniusNorm(const Matrix& A);
void zeroize(Matrix& C);
void randomize(Matrix &A);
void piscetize(Matrix& A, size_t xpoints, size_t ypoints);
void writeMatrix(const Matrix& A, const std::string& filename);
void streamMatrix(const Matrix&A);
void streamMatrix(const Matrix&A, std::ostream& outputFile);


Vector operator*(const Matrix& A, const Vector& x);
void basicMultiplyMV(const Matrix& A, const Vector &x, Vector& y);

#endif // __MATRIX_HPP
