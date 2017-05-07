#include <iostream>
#include <string>
#include "Vector.hpp"
#include "Timer.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    size_t N = 1024*1024;
    size_t numThreads = 4;
    
    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " [ N ] [ numThreads ]" << endl;
    }
    
    if (argc < 2 || string(argv[1]) == "0" || stod(argv[1]) <= 0)
        cout << "Invalid size N, set to default: 1024*1024" << endl;
    else N = stod(argv[1]);
    
    if (argc < 3 || string(argv[2]) == "0" || stod(argv[2]) <= 0)
        cout << "Invalid number of threads, set to default: 4" << endl;
    else numThreads = stod(argv[2]);
    
    Vector x(N);
    randomize(x);
    
    Timer T;
    T.start();
    double norm0 = twoNorm(x);
    T.stop();
    double t0 = 1000*T.elapsed();
    
    T.start();
    double norm2 = partitionedTwoNorm(x, numThreads);
    T.stop();
    double t = 1000*T.elapsed();
    
    zeroize(x);
    
    cout << N << " " << t0 << " " << t << " " << t0 / t << " " << norm2 - norm0 << endl;
    return 0;
}