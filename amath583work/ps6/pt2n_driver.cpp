#include <iostream>
#include <thread>
#include <omp.h>
#include "Vector.hpp"
#include "Timer.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " N [ numRuns ]" << endl;
    }
    else
    {
        size_t N = 32;
        if (stoul(argv[1]) <= 0)
            cout << "Invalid size N, set to default: 32" << endl;
        else N = stoul(argv[1]);
        
        long runs = 4L*1048L*1048L/(N*N) + 2;
        if (argc < 3 || stoul(argv[2]) <= 0)
            cout << "Invalid number of run times, set to default: 4L*1048L*1048L/(N*N)+2" << endl;
        else runs = stoul(argv[2]);
        
        Vector x(N);
        randomize(x);
        
        double norm0 = 0.0, norm2 = 0.0;
        
        Timer T;
        T.start();
        for (long i = 0; i < runs; ++i) norm0 = twoNorm(x);
        T.stop();
        double t0 = T.elapsed();
        
        T.start();
        for (long i = 0; i < runs; ++i) norm2 = ompTwoNorm(x);
        T.stop();
        double t = T.elapsed();
        
        zeroize(x);
        
        cout << N << " " << t0 << " " << t << " " << t0 / t << " " << norm2 - norm0 << endl;
    }
    
    return 0;
}
