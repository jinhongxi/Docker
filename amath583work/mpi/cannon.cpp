
#include <mpi.h>
#include <cmath>
#include "Matrix.hpp"

void cannonMultiplyMV(const Matrix& A, const Matrix& B, Matrix& C) {
  size_t mysize = MPI::COMM_WORLD.Get_size();

  // Set up grid topology and a grid (Cartesian) communicator
  int dims[2] = { (int) std::sqrt(mysize), (int) std::sqrt(mysize) };
  bool periods[2] = { true, true };

  MPI::Cartcomm gridComm = MPI::COMM_WORLD.Create_cart(2, dims, periods, true);
  size_t myrank = gridComm.Get_rank();

  int mycoords[2]; 
  gridComm.Get_coords(myrank, 2, mycoords);

  int northRank, eastRank, westRank, southRank;
  gridComm.Shift(0, -1, westRank,  eastRank);
  gridComm.Shift(1, -1, southRank, northRank);
  
  // Move A and B where they need to be to start
  int shiftSource, shiftDest; 
  gridComm.Shift(0, -mycoords[0], shiftSource, shiftDest);
  gridComm.Sendrecv_replace(const_cast<double*>(&A(0,0)), A.numRows()*A.numCols(), 
			    MPI::DOUBLE, shiftDest, 314, shiftSource, 314);

  gridComm.Shift(1, -mycoords[1], shiftSource, shiftDest);
  gridComm.Sendrecv_replace(const_cast<double*>(&B(0,0)), B.numRows()*B.numCols(), 
			    MPI::DOUBLE, shiftDest, 314, shiftSource, 315);


  // Main loop
  for (int k = 0; k < dims[0]; ++k) { 
    hoistedCopyBlockedTiledMultiply2x2(A, B, C); // Local block matmat

    gridComm.Sendrecv_replace(const_cast<double*>(&A(0,0)), A.numRows()*A.numCols(), 
			      MPI::DOUBLE, westRank,  316, eastRank,  316);
    gridComm.Sendrecv_replace(const_cast<double*>(&B(0,0)), B.numRows()*A.numCols(), 
			      MPI::DOUBLE, northRank, 317, southRank, 317);
  }

  // Restore A and B to initial distribution
  gridComm.Shift(0, +mycoords[0], shiftSource, shiftDest);
  gridComm.Sendrecv_replace(const_cast<double*>(&A(0,0)), A.numRows()*A.numCols(), 
			    MPI::DOUBLE, shiftDest, 318, shiftSource, 318);

  gridComm.Shift(1, +mycoords[1], shiftSource, shiftDest);
  gridComm.Sendrecv_replace(const_cast<double*>(&B(0,0)), B.numRows()*B.numCols(), 
			    MPI::DOUBLE, shiftDest, 319, shiftSource, 319);

  gridComm.Free();
}
