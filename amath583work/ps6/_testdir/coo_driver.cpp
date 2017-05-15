#include <iostream>
#include <thread>
#include <omp.h>
#include <cmath>
#include "COO.hpp"
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
        
        COOMatrix A(N, N);
        int xpoints = sqrt((double) N);
        piscetize(A, xpoints, xpoints);
        Vector x(N);
        randomize(x);
        Vector y0(N);
        Vector y2(N);
        
        int numThreads = 0;
#pragma omp parallel reduction(+:numThreads)
        numThreads += 1;
        
        Timer T;
        T.start();
        for (long i = 0; i < runs; ++i) matvec(A, x, y0);
        T.stop();
        double t0 = T.elapsed();
        
        T.start();
        for (long i = 0; i < runs; ++i) ompMatvec(A, x, y2);
        T.stop();
        double t = T.elapsed();
        
        zeroize(x);
        zeroize(y0);
        zeroize(y2);
        
        cout << thread::hardware_concurrency() << " " << numThreads << " ";
        cout << N << " " << t0 << " " << t << " " << t0 / t << " " << twoNorm(y0) - twoNorm(y2) << endl;
    }
    
    return 0;
}
