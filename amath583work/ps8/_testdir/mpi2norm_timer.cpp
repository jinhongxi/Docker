#include <iostream>
#include <string>
#include <mpi.h>
#include <cmath>
#include "Vector.hpp"
#include "Timer.hpp"


double mpiTwoNorm(Vector &x0)
{
    size_t len = x0.numRows() / MPI::COMM_WORLD.Get_size();
    MPI::COMM_WORLD.Bcast(&len, 1, MPI::UNSIGNED_LONG, 0);
    
    Vector x(len);
    MPI::COMM_WORLD.Scatter(&x0(0), len, MPI::DOUBLE, &x(0), len, MPI::DOUBLE, 0);
    
    double prod = dot(x, x), norm = 0.0;
    MPI::COMM_WORLD.Reduce(&prod, &norm, 1, MPI::DOUBLE, MPI::SUM, 0);

    norm = std::sqrt(norm);
    
    return norm;
}


int main(int argc, char* argv[])
{
    size_t len = 0;
    if (argc >= 2) len = std::stol(argv[1]);
    else len = 1024;
    
    MPI::Init();
    size_t myrank = MPI::COMM_WORLD.Get_rank();
    size_t mysize = MPI::COMM_WORLD.Get_size();
    
    size_t len0 = 0;
    if (myrank == 0)
    {
        len0 = len * mysize;
        std::cout << "process\tsize\tseq_t\tpar_t\tdiff" << std::endl;
    }
    
    Vector x0(len0);
    randomize(x0);

    Timer T;
    T.start();
    double norm = mpiTwoNorm(x0);
    T.stop();
    double t = T.elapsed();
    
    if (myrank == 0)
    {
      T.start();
      double norm0 = twoNorm(x0);
      T.stop();
      double t0 = T.elapsed();
      
      std::cout << mysize << "\t" << len0 << "\t" << t0 << "\t" << t << "\t" << std::abs(norm0 - norm) << std::endl;
    }
    
    MPI::Finalize();
    
    return 0;
}
