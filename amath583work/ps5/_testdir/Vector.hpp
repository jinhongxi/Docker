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
#include "Matrix.hpp"

class Vector {
public:
  Vector(int M) : iRows(M), arrayData(iRows) {}

    double &operator()(int i)       { return arrayData[i]; }
    const double &operator()(int i) const { return arrayData[i]; }

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


void matvec(const Matrix& A, const Vector& x, Vector& y);
Vector operator* (const Matrix& A, const Vector& x);
void matvec_inner(const Matrix& A, const Vector& x, Vector& y);
void matvec_outer(const Matrix& A, const Vector& x, Vector& y);
void matvec_student(const Matrix& A, const Vector& x, Vector& y);


void ptn_worker(const Vector& x, std::size_t begin, std::size_t end, double& partial);
double partitionedTwoNorm(const Vector& x, std::size_t partitions);

double rtn_worker(const Vector& x, std::size_t begin, std::size_t end, std::size_t level);
double recursiveTwoNorm(const Vector& x, std::size_t levels);

void matvec_helper(const Matrix& A, const Vector& x, Vector& y, std::size_t begin, std::size_t end);
void task_matvec(const Matrix& A, const Vector& x, Vector& y, std::size_t partitions);

#endif // VECTOR_HPP
