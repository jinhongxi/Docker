#include <future>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

using namespace std;

double x = 0.0;
mutex x_mutex;

double partial_x(size_t begin, size_t end, double h)
{
    double partial_x = 0.0;
    for (size_t i = begin; i < end; ++i) partial_x += 4.0 / (1.0 + i*i*h*h);
    return partial_x;
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