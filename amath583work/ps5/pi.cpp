#include <future>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
#include "Matrix.hpp"
#include "Vector.hpp"

using namespace std;

double inner_dot(const Matrix& A, const Vector& x, unsigned long i, double init)
{
    for (unsigned long j = 0; j < A.numCols(); ++j)
        init += A(i, j) * x(j);
    return init;
}

void task_matvec(const Matrix& A, const Vector& x, const Vector& y)
{
    vector<future<double> > futs(A.numRows());
    for (unsigned long i = 0; i < A.numRows(); ++i)
        futs[i] = async(inner_dot, A, x, i, 0.0);
    for (unsigned long i = 0; i < A.numRows(); ++i)
        y(i) = futs[i].get();
}

int main(int argc, char* argv[])
{
    size_t N = 1024*1024;
    size_t numThreads = 4;
    double h = 1.0/(double)N;
    size_t threadSize = N / numThreads;
    
    vector<future<double> > partial_sums;
    
    for (size_t i = 0; i < numThreads; ++i)
        partial_sums.push_back(async(launch::async | launch::deferred, partial_x, i*threadSize, (i+1)*threadSize, h));
    
    for (size_t i = 0; i < numThreads; ++i)
        x += h * partial_sums[i].get();
    
    cout << "x ~ " << x << endl;
    return 0;
}