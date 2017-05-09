#include "Vector.hpp"
#include <vector>
#include <mutex>
#include <thread>

using namespace std;

void matvec_helper(const Matrix& A, const Vector& x, Vector& y, size_t begin, size_t end)
{
    mutex y_mutex;
    double helper = 0.0;
    vector<double> xTemp(x.numRows());
    for (int j = 0; j < x.numRows(); ++j) xTemp[j] = x(j);
    
    for (size_t i = begin; i < end; ++i) 
    {
        if (i < A.numRows())
        {
            for (int j = 0; j < x.numRows(); ++j) 
                helper += A(i, j) * xTemp[j];
            {
                lock_guard<mutex> y_guard(y_mutex);
                y(i) = helper;
            }
            helper = 0.0;
        }
    }
    xTemp.clear();
}

void task_matvec(const Matrix& A, const Vector& x, Vector& y, size_t partitions)
{
    vector<thread> threads;
    for (size_t i = 0; i < partitions; ++i)
        threads.push_back(thread(matvec_helper, A, x, ref(y), i * x.numRows() / partitions, (i+1) * x.numRows() / partitions));
    for (size_t i = 0; i < partitions; ++i) threads[i].join();
}