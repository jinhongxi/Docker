//
// This file is part of the course materials for AMATH483/583 at the University of Washington,
// Spring 2017
//
// Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
// https://creativecommons.org/licenses/by-nc-sa/4.0/
//
// Author: Andrew Lumsdaine
//

#include "Timer.hpp"
#include "Vector.hpp"
#include <iostream>
#include <mpi.h>
#include <cmath>


double mpiTwoNorm(const Vector& lx)
{
  double rho = dot(lx, lx), sigma = 0;
  MPI::COMM_WORLD.Allreduce(&rho, &sigma, 1, MPI::DOUBLE, MPI::SUM);
  return std::sqrt(sigma);
}


int main(int argc, char* argv[])
{
  MPI::Init();

  size_t myrank = MPI::COMM_WORLD.Get_rank();
  size_t mysize = MPI::COMM_WORLD.Get_size();
  size_t losize = 1;
  int val;

  if (argc == 1)
    losize = 1024;
  else if (argc == 2)
  {
    val = std::stoi(argv[1]);
    if (val <= 0)
    {
      std::cout << "Length of vector needs to be positive" << std::endl;
      return 1;
    }
    losize = val;
  }

  size_t glsize = losize * mysize;
  int target = 1024*1024*1024;
  int num_runs = target/glsize;

  double mpi = 0;
  double seq = 0;

  Vector lx(losize);
  Timer T;
  double t_seq=0.0;
  double t_mpi=1.0;

  if (0 == myrank) {
    Vector gx = Vector(glsize);
    randomize(gx);
    MPI::COMM_WORLD.Scatter(&gx(0), losize, MPI::DOUBLE,
			    &lx(0), losize, MPI::DOUBLE, 0);
    T.start();
    for (int i=0; i < num_runs; i++)
      seq = std::sqrt(dot(gx, gx));
    T.stop();
    t_seq = T.elapsed()/num_runs;

  } else {
    MPI::COMM_WORLD.Scatter(NULL, losize, MPI::DOUBLE,
			    &lx(0), losize, MPI::DOUBLE, 0);
  }


  T.start();
  for (int i=0; i < num_runs; i++)
    mpi = mpiTwoNorm(lx);
  T.stop();
  t_mpi = T.elapsed()/num_runs;

  if (0 == myrank) {
    std::cout << "#\tglobal\tseq time\tmpi time\tspeed\tdifference" << std::endl;
    std::cout << mysize << "\t";
    std::cout << glsize << "\t";
    std::cout << t_seq << "\t";
    std::cout << t_mpi << " \t";
    std::cout << t_seq/t_mpi << "\t";
    std::cout << std::abs(mpi-seq) << std::endl;
  }


  MPI::Finalize();
  return 0;
}
