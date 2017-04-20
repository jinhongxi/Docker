//
// This file is part of the course materials for AMATH483/583 at the University of Washington,
// Spring 2017
//
// Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
// https://creativecommons.org/licenses/by-nc-sa/4.0/
//
// Author: Andrew Lumsdaine
// 

#if !defined(VECTOR_HPP)
#define VECTOR_HPP

#include <vector>

class Vector {
public:
  Vector(int M) : iRows(M), arrayData(M) {}

  // ----------------------------------------------------------------
  // Your operator()() goes here!


  // ----------------------------------------------------------------

  int numRows() const { return arrayData.size(); }

private:
  int iRows;
  std::vector<double> arrayData;  
};

double oneNorm(const Vector& v);
double twoNorm(const Vector& v);
double infinityNorm(const Vector& v);
Vector operator+(const Vector& x, const Vector& y);
Vector operator-(const Vector& x, const Vector& y);
void zeroize(Vector& v);
void randomize(Vector& v);

#endif // VECTOR_HPP
