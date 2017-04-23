#include <iostream>
#include <functional>
#include "Matrix.hpp"
#include "Timer.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  double clock = 3.1E9;
  double scalar[2] = {clock * 8 / 12, clock * 8 / 20};
  
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
  cout << "hoisted " << clock << " AVX2 20 " << scalar[1] << " " << 2*scalar[1] << " " << 4*scalar[1] << " " << 8*scalar[1] << " " << flops << endl;
  
  T.start();
  for (int i = 0; i < runs; ++i)  hoistedCopyBlockedTiledMultiply2x2(A, B, C);
  T.stop();
  zeroizeMatrix(C);
  flops = 2.0 * 1.e3 * runs * (size * size * size) / T.elapsed();
  
  cout << "copyblockhoisted " << clock << " AVX2 12 " << scalar[0] << " " << 2*scalar[0] << " " << 4*scalar[0] << " " << 8*scalar[0] << " " << flops << endl;
  cout << "copyblockhoisted " << clock << " AVX2 20 " << scalar[1] << " " << 2*scalar[1] << " " << 4*scalar[1] << " " << 8*scalar[1] << " " << flops << endl;
  

  return 0;
}