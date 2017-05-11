#include <iostream>
#include <string>
#include "Matrix.hpp"
#include "Vector.hpp"
#include "Timer.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " N [ numThreads ]" << endl;
    }
    else
    {
        size_t N = 0;
        size_t numThreads = 4;
        
        if (stoul(argv[1]) <= 0)
            cout << "Invalid size N" << endl;
        else N = stoul(argv[1]);
        
        if (argc < 3 || stoul(argv[2]) <= 0)
            cout << "Invalid number of threads, set to default: 4" << endl;
        else numThreads = stoul(argv[2]);
        
        long runs = 8L*1048L*1048L/(N*N*N) + 2;
        
        Vector x(N);
        randomize(x);
        
        Matrix A(N, N);
        randomizeMatrix(A);
        
        Vector y(N);
        Vector y0(N);
        
        Timer T;
        T.start();
        for (long i = 0; i < runs; ++i) matvec(A, x, y0);
        T.stop();
        double t0 = T.elapsed();
        
        T.start();
        for (long i = 0; i < runs; ++i) task_matvec(A, x, y, numThreads);
        T.stop();
        double t = T.elapsed();
        
        cout << N << " " << t0 << " " << t << " " << t0 / t << " " << twoNorm(y)-twoNorm(y0) << endl;
    }
    
    return 0;
}
