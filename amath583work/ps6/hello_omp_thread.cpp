//
// This file is part of the course materials for AMATH483/583 at the University of Washington,
// Spring 2017
//
// Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
// https://creativecommons.org/licenses/by-nc-sa/4.0/
//
// Author: Andrew Lumsdaine
//
//
#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>
#include <omp.h>


std::string getenv_to_string(const char *in) {
  char *gotten = std::getenv(in);
  if (NULL == gotten) {
    return std::string("");
  } else {
    return std::string(gotten);
  }
}


std::string getenv(const std::string& in) {
  return getenv_to_string(in.c_str());
}


int omp_thread_count() {
  int n = 0;
#pragma omp parallel reduction(+:n)
  n += 1;
  return n;
}


int main() {

  std::string envName = "OMP_NUM_THREADS";
  std::cout << envName << "        = " << getenv(envName) << std::endl;

  std::cout << "hardware_concurrency() = " << std::thread::hardware_concurrency() << std::endl;
  std::cout << "omp_get_max_threads()  = " << omp_get_max_threads() << std::endl;
  std::cout << "omp_get_num_threads()  = " << omp_get_num_threads() << std::endl;
  std::cout << "omp_thread_count()     = " << omp_thread_count() << std::endl;

  return 0;
}
