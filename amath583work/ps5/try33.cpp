#include <future>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
#include <cmath>
#include "Vector.hpp"

std::mutex x_mutex;

void ptn_worker(const Vector& x, size_t begin, size_t end, double& partial)
{
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
        threads.push_back(std::thread(ptn_worker, x, i * x.numRows() / partitions, (i+1) * x.numRows() / partitions, std::ref(norm)));
    for (size_t i = 0; i < partitions; ++i) threads[i].join();
    
    return sqrt(norm);
}

int main(int argc, char* argv[])
{
    size_t N = 1024 * 1024;
    size_t numblocks = 4;
    
    Vector x(N);
    zeroize(x);
    randomize(x);
    double norm0 = twoNorm(x);
    double norm2 = partitionedTwoNorm(x, numblocks);
    
    std::cout << "norm ~ " << norm2 << std::endl;
    std::cout << "norm = " << norm0 << std::endl;
    return 0;
}