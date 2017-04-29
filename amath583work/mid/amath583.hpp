#ifndef AMATH583_HPP
#define AMATH583_HPP

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>

#include "Timer.hpp"
#include "Matrix.hpp"
#include "Vector.hpp"
#include "COO.hpp"
#include "AOSMatrix.hpp"
#include "CSCMatrix.hpp"
#include "CSRMatrix.hpp"

Vector readVector(std::istream &inputStream);
Vector readVector(std::string inputFilename);

void writeVector(const Vector &x, std::ostream &outputStream);
void writeVector(const Vector &x, std::string outputFilename);

Matrix readMatrix(std::istream &inputStream);
Matrix readMatrix(std::string inputFilename);

COOMatrix readCOOMatrix(std::istream &inputStream);
COOMatrix readCOOMatrix(std::string inputFilename);

AOSMatrix readAOSMatrix(std::istream &inputStream);
AOSMatrix readAOSMatrix(std::string inputFilename);

CSCMatrix readCSCMatrix(std::istream &inputStream);
CSCMatrix readCSCMatrix(std::string inputFilename);

Matrix readMatrix(std::istream &inputStream);
Matrix readMatrix(std::string inputFilename);

void matvec(const Matrix& A, const Vector& x, Vector& y);
Vector operator* (const Matrix& A, const Vector& x);

#endif
