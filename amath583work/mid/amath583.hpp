#ifndef AMATH583_HPP
#define AMATH583_HPP

#include "Matrix.hpp"
#include "Vector.hpp"
#include "COO.hpp"
#include "Timer.hpp"
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>

Vector readVector(std::string inputFilename);

void writeVector(const Vector &x, std::string outputFilename);

#endif
