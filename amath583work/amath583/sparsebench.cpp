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

#include "COO.hpp"
#include "Matrix.hpp"
#include "Timer.hpp"
#include "Vector.hpp"
#include <cassert>
#include <cmath>
#include <fstream>
#include <functional>
#include <iostream>

using namespace std;

double benchmark_dense(size_t M, size_t N, size_t K, long numruns, function<void(const Matrix&, const Vector&, Vector&)>);
void runBenchmark_dense(function<void(const Matrix&, const Vector&, Vector&)> f, long maxsize);

double benchmark_sparse(size_t M, size_t N, size_t K, long numruns, function<void(const COOMatrix&, const Vector&, Vector&)>);
void runBenchmark_sparse(function<void(const COOMatrix&, const Vector&, Vector&)> f, long maxsize);

void matvec_dense(const Matrix& A, const Vector& x, Vector& y) {
  for (size_t i = 0; i < A.numRows(); ++i) {
    for (size_t j = 0; j < A.numCols(); ++j) {
      y(i) = A(i, j) * x(j);
    }
  }
}

void matvec_sparse(const COOMatrix& A, const Vector& x, Vector& y) { A.matvec(x, y); }

size_t main(size_t argc, char* argv[]) {
  if (argc != 2) return -1;

  if (string(argv[1]) == "dense")
    runBenchmark_dense(matvec_dense, 32L * 8192L);
  else if (string(argv[1]) == "sparse")
    runBenchmark_sparse(matvec_sparse, 32L * 8192L);
  else
    return -2;

  return 0;
}

void runBenchmark_dense(function<void(const Matrix&, const Vector&, Vector&)> f, long maxsize) {
  cout << "N\tN*N\tTime\tFlops\tTperX" << endl;
  for (long i = 16; i <= maxsize; i *= 4) {
    long   numruns = 4L * 1048L * 1048L * 1048L / (i * i) + 4;
    double t       = benchmark_dense(i, i, i, numruns, f);
    cout << i << "\t" << i * i << "\t" << t << "\t" << 2.0 * 1.e3 * numruns * i * i / t << "\t" << t / ((double)numruns) << endl;
  }
}

double benchmark_dense(size_t M, size_t N, size_t K, long numruns, function<void(const Matrix&, const Vector&, Vector&)> f) {
  size_t xpoints = std::sqrt((double)M);
  assert(xpoints * xpoints == M);

  Matrix A(M, M);
  Vector x(M), y(M);
  piscetize(A, xpoints, xpoints);
  randomize(x);
  randomize(y);

  Timer T;
  T.start();
  for (size_t i = 0; i < numruns; ++i) {
    f(A, x, y);
  }
  T.stop();

  zeroize(y);

  return T.elapsed();
}

void runBenchmark_sparse(function<void(const COOMatrix&, const Vector&, Vector&)> f, long maxsize) {
  cout << "N\tN*N\tTime\tFlops\tTperX" << endl;
  for (long i = 16; i <= maxsize; i *= 4) {
    long   numruns = 4L * 1048L * 1048L * 1048L / (i * i) + 2;
    double t       = benchmark_sparse(i, i, i, numruns, f);
    cout << i << "\t" << i * i << "\t" << t << "\t" << 2.0 * 1.e3 * numruns * i * i / t << "\t" << t / ((double)numruns) << endl;
  }
}

double benchmark_sparse(size_t M, size_t N, size_t K, long numruns, function<void(const COOMatrix&, const Vector&, Vector&)> f) {
  size_t xpoints = std::sqrt((double)M);
  assert(xpoints * xpoints == M);

  COOMatrix A(M, M);
  Vector    x(M), y(M);
  piscetize(A, xpoints, xpoints);
  randomize(x);
  randomize(y);

  Timer T;
  T.start();
  for (size_t i = 0; i < numruns; ++i) {
    f(A, x, y);
  }
  T.stop();

  zeroize(y);

  return T.elapsed();
}
