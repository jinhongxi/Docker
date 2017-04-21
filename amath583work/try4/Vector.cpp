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
    for (int j = 0; j < x.numRows(); ++j)
    {
        for (int i = 0; i < A.numRows(); ++i) y(i) += A(i, j) * x(j);
    }
}


void matvec_outer(const Matrix& A, const Vector& x, Vector& y) {
    for (int i = 0; i < A.numRows(); ++i)
    {
        for (int j = 0; j < x.numRows(); ++j) y(i) += A(i, j) * x(j);
    }
}


void matvec_student(const Matrix& A, const Vector& x, Vector& y) {
    /*vector<double> xTemp(x.numRows());
    
    for (int j = 0; j < xTemp.size(); ++j) xTemp[j] = x(j);
    
    for (int i = 0; i < A.numRows(); ++i)
    {
        for (int j = 0; j < xTemp.size(); ++j) y(i) += A(i, j) * xTemp[j];
    }
    
    xTemp.clear();*/
    vector<double> xTemp;
    
    for (int j = 0; j < xTemp.size(); ++j) xTemp.push_back(x(j));
    
    for (int i = 0; i < A.numRows(); ++i)
    {
        for (int j = 0; j < xTemp.size(); ++j) y(i) += A(i, j) * xTemp[j];
    }
    
    xTemp.clear();
}






















