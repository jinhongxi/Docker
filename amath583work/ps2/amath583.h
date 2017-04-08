#ifndef AMATH583_H
#define AMATH583_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
    
std::vector<double> readVector(std::istream &inputStream);
std::vector<double> readVector(std::string inputFilename);
    
void writeVector(const std::vector<double> &x, std::ostream &outputStream);
void writeVector(const std::vector<double> &x, std::string outputFilename);

std::vector<double> randomVector(int n);

double twoNorm(const std::vector<double> &x);

double dot583(const std::vector<double> &x, const std::vector<double> &y);

#endif
