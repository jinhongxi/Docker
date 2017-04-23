#ifndef AMATH583_HPP
#define AMATH583_HPP

#include "Vector.hpp"
#include "Matrix.hpp"
#include <cassert>

void matvec(const Matrix& A, const Vector& x, Vector& y);
Vector operator* (const Matrix& A, const Vector& x);

#endif
