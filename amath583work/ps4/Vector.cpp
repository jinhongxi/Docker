//
// This file is part of the course materials for AMATH483/583 at the University of Washington,
// Spring 2017
//
// Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
// https://creativecommons.org/licenses/by-nc-sa/4.0/
//
// Author: Andrew Lumsdaine
//

#include <cassert>
#include <cmath>
#include <random>
#include <functional>
#include "Vector.hpp"

using namespace std;

double oneNorm(const Vector& v) {
  double d = 0.0;
  for (int i = 0; i < v.numRows(); ++i)
    d += std::abs(v(i));
  return d;
}


double twoNorm(const Vector& v) {
  double d = 0.0;
  for (int i = 0; i < v.numRows(); ++i)
    d += v(i)*v(i);
  return std::sqrt(d);
}


double infinityNorm(const Vector& v) {
  double d = 0.0;
  for (int i = 0; i < v.numRows(); ++i)
    d = std::max(d, std::abs(v(i)));
  return d;
}


Vector operator+(const Vector& x, const Vector& y) {
  assert(x.numRows() == y.numRows());

  Vector z(x.numRows());
  for (int i = 0; i < x.numRows(); ++i) {
    z(i) = x(i) + y(i);
  }
  return z;
}


Vector operator-(const Vector& x, const Vector& y) {
  assert(x.numRows() == y.numRows());

  Vector z(x.numRows());
  for (int i = 0; i < x.numRows(); ++i) {
    z(i) = x(i) - y(i);
  }
  return z;
}


void zeroize(Vector& v) {
  for (int i = 0; i < v.numRows(); ++i) {
    v(i) = 0.0;
  }
}


void randomize(Vector& v) {
  static std::default_random_engine generator;
  static std::uniform_real_distribution<double> distribution(2.0, 32.0);
  static auto dice = bind(distribution, generator);

  for (int i = 0; i < v.numRows(); ++i) {
    v(i) = dice();
  }
}


void matvec_inner(const Matrix& A, const Vector& x, Vector& y) {
    zeroize(y);
    for (int j = 0; j < x.numRows(); ++j)
    {
        for (int i = 0; i < A.numRows(); ++i)
        {
            y(i) += A(i, j) * x(j);
        }
    }
}


void matvec_outer(const Matrix& A, const Vector& x, Vector& y) {
    zeroize(y);
    for (int i = 0; i < A.numRows(); ++i)
    {
        for (int j = 0; j < x.numRows(); ++j)
        {
            y(i) += A(i, j) * x(j);
        }
    }
}


void matvec_student(const Matrix& A, const Vector& x, Vector& y) {
    zeroize(y);
    vector<double> buffer = {0.0, 0.0, 0.0};
    for (int i = 1; i < A.numRows(); i += 3)
    {
        for (int j = 1; j < x.numRows(); j += 3)
        {
            if (j + 1 != x.numRows()) buffer = {x(j-1), x(j), x(j+1)};
            else buffer = {x(j-1), x(j), 0.0};
            y(i) += A(i, j - 1) * buffer[0] + A(i, j) * buffer[1] + A(i, j + 1) * buffer[2];
            y(i - 1) += A(i - 1, j - 1) * buffer[0] + A(i - 1, j) * buffer[1] + A(i - 1, j + 1) * buffer[2];
            if (i + 1 != A.numRows()) y(i + 1) += A(i + 1, j - 1) * buffer[0] + A(i + 1, j) * buffer[1] + A(i + 1, j + 1) * buffer[2];
        }
    }
}
