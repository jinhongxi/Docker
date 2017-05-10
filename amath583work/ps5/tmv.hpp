#ifndef TMV_HPP
#define TMV_HPP

#include "Matrix.hpp"
#include "Vector.hpp"
#include <vector>

void matvec_helper(const Matrix& A, const Vector& x, Vector& y, size_t begin, size_t end);
void task_matvec(const Matrix& A, const Vector& x, Vector& y, size_t partitions);

#endif