#include <iostream>
#include <string>
#include <mpi.h>


int main(int argc, char* argv[])
{
    MPI::Init();
    
    int token     = 0;
    size_t rounds = 1;
    
    if (argc >= 2) rounds = std::stol(argv[1]);
    size_t rounds0 = rounds;
    
    int myrank = MPI::COMM_WORLD.Get_rank();
    int mysize = MPI::COMM_WORLD.Get_size();
    
    while (rounds--)
    {
        if (myrank == 0)
        {
            std::cout << myrank << ": sending  " << token << std::endl;
            MPI::COMM_WORLD.Send(&token, 1, MPI::INT, 1, 321);
            if (rounds  == rounds0) MPI::COMM_WORLD.Recv(&token, 1, MPI::INT, 1, 321);
            else MPI::COMM_WORLD.Recv(&token, 1, MPI::INT, mysize - 1, 321);
            std::cout << myrank << ": received " << token << std::endl;
            ++token;
        } else if (myrank < mysize)
        {
            MPI::COMM_WORLD.Recv(&token, 1, MPI::INT, myrank - 1, 321);
            std::cout << myrank << ": received " << token << std::endl;
            ++token;
            std::cout << myrank << ": sending  " << token << std::endl;
            if (myrank == mysize - 1) MPI::COMM_WORLD.Send(&token, 1, MPI::INT, 0, 321);
            else MPI::COMM_WORLD.Send(&token, 1, MPI::INT, myrank + 1, 321);
            
        } else break;
    }
    
    MPI::Finalize();
    
    return 0;
}
