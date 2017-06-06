#include "Grid.hpp"
#include "mpiStencil.hpp"
#include <mpi.h>
#include <cmath>


Grid operator*(const mpiStencil& A, const Grid& x)
{
  Grid y(x);

  for (size_t i = 1; i < x.numX() - 1; ++i) {
    for (size_t j = 1; j < x.numY() - 1; ++j) {
      y(i, j) = x(i, j) - (x(i - 1, j) + x(i + 1, j) + x(i, j - 1) + x(i, j + 1)) / 4.0;
    }
  }

  size_t myrank = MPI::COMM_WORLD.Get_rank();
  size_t mysize = MPI::COMM_WORLD.Get_size();
  MPI::Datatype lineType = MPI::DOUBLE.Create_contiguous(y.numY());
  lineType.Commit();

  Grid top(1, y.numY());
  Grid bottom(1, y.numY());
  
  if (myrank > 0) {
    MPI::COMM_WORLD.Send(&x(0, 0), 1, lineType, myrank - 1, 233);
    MPI::COMM_WORLD.Recv(&top(0, 0), 1, lineType, myrank - 1, 666);
  }
  if (myrank < mysize - 1) {
    MPI::COMM_WORLD.Send(&x(x.numX() - 1, 0), 1, lineType, myrank + 1, 666);
    MPI::COMM_WORLD.Recv(&bottom(0, 0), 1, lineType, myrank + 1, 233);
  }

  if (myrank > 0) {
    for (size_t j = 1; j < x.numY() - 1; ++j)
      y(0, j) = x(0, j) - (top(0, j) + x(1, j) + x(0, j - 1) + x(0, j + 1)) / 4.0;
  }
  if (myrank < mysize - 1) {
    for (size_t j = 1; j < x.numY() - 1; ++j)
      y(x.numX() - 1, j) = x(x.numX() - 1, j) - (x(x.numX() - 2, j) + bottom(0, j) + x(x.numX() - 1, j - 1) + x(x.numX() - 1, j + 1)) / 4.0;
  }
  
  return y;
}
