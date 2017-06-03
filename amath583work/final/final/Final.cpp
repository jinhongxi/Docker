#include "Final.hpp"
#include "Grid.hpp"
#include "mpiStencil.hpp"
#include <mpi.h>
#include <cmath>
#include <iostream>


double mpiDot(const Grid& X, const Grid& Y)
{
  double sum = 0.0;
  for (size_t i = 0; i < X.numX(); ++i) {
    for (size_t j = 0; j < X.numY(); ++j) {
      sum += X(i, j) * Y(i, j);
    }
  }

  double dot = 0.0;
  MPI::COMM_WORLD.Allreduce(&sum, &dot, 1, MPI::DOUBLE, MPI::SUM);
  
  return dot;
}


size_t ir(const mpiStencil& A, Grid& x, const Grid& b, size_t max_iter, double tol)
{
  for (size_t iter = 0; iter < max_iter; ++iter) {
    Grid   r   = b - A * x;
    double rho = mpiDot(r, r);
    if (MPI::COMM_WORLD.Get_rank() == 0)
      std::cout << "||r|| = " << std::sqrt(rho) << std::endl;
    if (std::sqrt(rho) < tol) return iter;
    x += r;
  }
  return max_iter;
}


size_t cg(const mpiStencil& A, Grid& x, const Grid& b, size_t max_iter, double tol)
{
  Grid   r   = b - A * x, p(b);
  double rho = mpiDot(r, r), rho_1 = 0.0;
  for (size_t iter = 0; iter < max_iter; ++iter) {

    if (MPI::COMM_WORLD.Get_rank() == 0)
      std::cout << "||r|| = " << std::sqrt(rho) << std::endl;

    if (iter == 0) {
      p = r;
    } else {
      double beta = (rho / rho_1);
      p           = r + beta * p;
    }

    Grid   q     = A * p;
    double alpha = rho / mpiDot(p, q);

    x += alpha * p;

    rho_1 = rho;
    r -= alpha * q;
    rho = mpiDot(r, r);

    if (rho < tol) return iter;
  }
  return max_iter;
}
