#include "Timer.hpp"
#include "Vector.hpp"
#include <iostream>
#include <mpi.h>
#include <thread>
#include <future>
#include <mutex>
#include <cmath>


void ptn_worker(const Vector& x, size_t begin, size_t end, double& partial)
{
  std::mutex x_mutex;
  double worker = 0.0;
  for (size_t i = begin; i < end; ++i)
    {
      if (i < x.numRows()) worker += x(i) * x(i);
    }
  {
    std::lock_guard<std::mutex> x_guard(x_mutex);
    partial += worker;
  }
}


double partitionedTwoNorm(const Vector& x, size_t partitions)
{
  double norm = 0.0;

  std::vector<std::thread> threads;
  for (size_t i = 0; i < partitions; ++i)
    {
      size_t begin = i * x.numRows() / partitions;
      size_t end = (i+1) * x.numRows() / partitions;
      threads.push_back(std::thread(ptn_worker, std::cref(x), begin, end, std::ref(norm)));
    }
  for (size_t i = 0; i < partitions; ++i) threads[i].join();

  return std::sqrt(norm);
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
    mpi = partitionedTwoNorm(lx, 2);
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
