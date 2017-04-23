#include <iostream>
using namespace std;
#include "Timer.hpp"

int main()
{
  long N = 1024L;

  double a = 3.14, b = 3.14159, c = 0.0, d = 0.0;

  Timer T;
  T.start();
  for (long i = 0; i < N*N*N; ++i)
    {
      c += a * b;
    }
  T.stop();
  cout << "No output (" << T.elapsed() << " ms)" << endl;
  
  T.start();
  for (long i = 0; i < N*N*N; ++i)
    {
      d += a * b;
    }
  T.stop();
  cout << "Output d = " << d << " (" << T.elapsed() << " ms)" << endl;
  
  return 0;
}
