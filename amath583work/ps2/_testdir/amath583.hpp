#ifndef AMATH583_HPP
#define AMATH583_HPP

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <ctime>
    
std::vector<double> readVector(std::istream &inputStream);
std::vector<double> readVector(std::string inputFilename);
    
void writeVector(const std::vector<double> &x, std::ostream &outputStream);
void writeVector(const std::vector<double> &x, std::string outputFilename);

std::vector<double> randomVector(int n);

double twoNorm(const std::vector<double> &x);
float twoNorm(const std::vector<float> &x);

double dot583(const std::vector<double> &x, const std::vector<double> &y);
float dot583(const std::vector<float> &x, const std::vector<float> &y);

std::vector<float> dtof(const std::vector<double> &x);
std::vector<double> ftod(const std::vector<float> &x);

#endif
