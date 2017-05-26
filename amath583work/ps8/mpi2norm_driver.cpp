#include <iostream>
#include <string>
#include <mpi.h>
#include <cmath>
#include "Vector.hpp"


int main(int argc, char* argv[])
{
    size_t len = 0;
    if (argc >= 2) len = std::stol(argv[1]);
    
    MPI::Init();
    size_t myrank = MPI::COMM_WORLD.Get_rank();
    size_t mysize = MPI::COMM_WORLD.Get_size();
    
    Vector x(len);
    
    size_t len0 = 0;
    if (myrank == 0)
    {
        len0 = len * mysize;
        std::cout << "\tglobal\tmpi\tdiff" << std::endl;
    }
    
    Vector x0(len0);
    randomize(x0);
    MPI::COMM_WORLD.Scatter(&x0, len, MPI::DOUBLE, &x, len, MPI::DOUBLE, 0);
    
    double prod = dot(x, x), norm = 0.0;
    MPI::COMM_WORLD.Reduce(&prod, &norm, 1, MPI::DOUBLE, MPI::SUM, 0);
    
    if (myrank == 0) std::cout << mysize << "\t" << twoNorm(x0) << "\t" << std::sqrt(norm) << "\t" << std::abs(twoNorm(x0) - std::sqrt(norm)) << std::endl;
    
    MPI::Finalize();
    
    return 0;
}
