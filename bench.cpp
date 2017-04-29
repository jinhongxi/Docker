#include "amath583.hpp"

#include <cassert>
#include <cmath>
#include <iostream>
#include <functional>

using namespace std;


void runBenchmark_sparse(int num, long maxsize)
{
    cout << "N\tN*N\tTime\tFlops\tTperX"  << endl;
    for (long i = 16; i <= maxsize; i *= 4)
    {
        long numruns = 4L*1048L*1048L*1048L/(i*i) + 2;
        double flops = i * i;
        double t = 0.0;
        
        int xpoints = std::sqrt((double) i);
        assert(xpoints*xpoints == i);
        Vector x(i), y(i);
        randomize(x);
        randomize(y);
        
        switch (num)
        {
            case 2:
            {
                COOMatrix A(i, i);
                piscetize(A, xpoints, xpoints);
                
                Timer T;
                T.start();
                for (int j = 0; j < numruns; ++j) A.matvec(x, y);
                T.stop();
                t = T.elapsed();
                break;
            }
            case 3:
            {
                AOSMatrix A(i, i);
                piscetize(A, xpoints, xpoints);
                
                Timer T;
                T.start();
                for (int j = 0; j < numruns; ++j) A.matvec(x, y);
                T.stop();
                t = T.elapsed();
                break;
            }
            case 4:
            {
                CSCMatrix A(i, i);
                piscetize(A, xpoints, xpoints);
                
                Timer T;
                T.start();
                for (int j = 0; j < numruns; ++j) A.matvec(x, y);
                T.stop();
                t = T.elapsed();
                break;
            }
            case 5:
            {
                CSRMatrix A(i, i);
                piscetize(A, xpoints, xpoints);
                
                Timer T;
                T.start();
                for (int j = 0; j < numruns; ++j) A.matvec(x, y);
                T.stop();
                t = T.elapsed();
                break;
            }
            default: exit(-2);
        }
        
        zeroize(y);
        
        
        cout << i << "\t" << i * i << "\t" << t << "\t" << flops / t << "\t" << t/((double)numruns)  << endl;
    }
}


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " coo / aos / csc / csr" << endl;
        return 0;
    }
    
    if (string(argv[1]) == "coo")
        runBenchmark_sparse(2, 32L*8192L);
    else if (string(argv[1]) == "aos")
        runBenchmark_sparse(3, 32L*8192L);
    else if (string(argv[1]) == "csc")
        runBenchmark_sparse(4, 32L*8192L);
    else if (string(argv[1]) == "csr")
        runBenchmark_sparse(5, 32L*8192L);
    else
    {
        cout << "Error -2: invalid input" << endl;
        return -2;
    }
    
    return 0;
}
