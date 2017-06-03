#include <iostream>
#include <mpi.h>
#include "Grid.hpp"
#include "mpiStencil.hpp"
#include "Final.hpp"


int main(int argc, char* argv[]) {
  size_t xsize              = 128, ysize = 128;
  size_t max_iters          = xsize;
  double tol                = 1.E-4;

  if (argc >= 2) xsize = ysize = std::stol(argv[1]);
  if (argc >= 3) max_iters     = std::stol(argv[2]);
  if (argc >= 4) tol           = std::stol(argv[3]);

  MPI::Init();
  size_t myrank = MPI::COMM_WORLD.Get_rank();
  size_t mysize = MPI::COMM_WORLD.Get_size();

  size_t xglobal = xsize, yglobal = ysize;
  xsize /= mysize;
  MPI::Datatype gridType = MPI::DOUBLE.Create_contiguous(xsize * ysize);
  gridType.Commit();
  
  Grid X0(xsize, ysize), X1(xsize, ysize);

  if (myrank == 0) {
    Grid X0global(xglobal, yglobal), X1global(xglobal, yglobal);
    for (size_t i = 1; i < xglobal + 1; ++i)
      X1global(0, i) = X0global(0, i) = 1.0;
    
    MPI::COMM_WORLD.Scatter(&X0global(0, 0), 1, gridType, &X0(0, 0), 1, gridType, 0);
    MPI::COMM_WORLD.Scatter(&X1global(0, 0), 1, gridType, &X1(0, 0), 1, gridType, 0);
  } else {
    MPI::COMM_WORLD.Scatter(NULL, 1, gridType, &X0(0, 0), 1, gridType, 0);
    MPI::COMM_WORLD.Scatter(NULL, 1, gridType, &X1(0, 0), 1, gridType, 0);
  }

  mpiStencil A;
  ir(A, X1, X0, max_iters, 1.e-6);

  MPI::Finalize();
  
  return 0;
}
