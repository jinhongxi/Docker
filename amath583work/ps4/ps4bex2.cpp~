#include <iostream>
#include <functional>
#include <cmath>
#include "Vector.cpp"
#include "COO.cpp"
#include "Timer.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  double clock = 3.1E9;
  double scalar[2] = {clock * 8 / 12, clock * 2 / 7};
  
  int size = 64;
  long runs = 8L * 1048L * 1048L * 1048L / (size * size * size) + 2;
  Matrix A(size, size), B(size, size), C(size, size);
  randomizeMatrix(A);
  randomizeMatrix(B);
  randomizeMatrix(C);

  Timer T;
  T.start();
  for (int i = 0; i < runs; ++i)  hoistedTiledMultiply2x2(A, B, C);
  T.stop();
  zeroizeMatrix(C);
  double flops = 2.0 * 1.e3 * runs * (size * size * size) / T.elapsed();
  
  cout << "Routine Clock CPUID Loop-ops Scalar 2-wide 4-wide 4-wide-fma Achieved" << endl;
  cout << "hoisted " << clock << " AVX2 12 " << scalar[0] << " " << 2*scalar[0] << " " << 4*scalar[0] << " " << 8*scalar[0] << " " << flops << endl;
  
  long l = 32L*8192L;
  int sql = sqrt((double) l);
  runs = 4L * 1048L * 1048L * 1048L / (l * l) + 2;
  COOMatrix D(l, l);
  Vector x(l), y(l);
  piscetize(D, sql, sql);
  randomize(x);
  randomize(y);
  
  T.start();
  for (int i = 0; i < runs; ++i) D.matvec(x, y);
  T.stop();
  zeroize(y);
  flops = l * l / T.elapsed();
  
  cout << "coo " << clock << " AVX2 7 " << scalar[1] << " " << 2*scalar[1] << " " << 4*scalar[1] << " " << 8*scalar[1] << " " << flops << endl;
  

  return 0;
}
