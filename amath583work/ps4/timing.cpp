#include <iostream>
using namespace std;
#include "Timer.hpp"

int main()
{
  long loops = 1024L*1024L*1024L;
  cout << "loops = " << loops << endl;

  Timer T;
  T.start();
  for (long i = 0; i < loops; ++i)  ;
  T.stop();
  cout << "[;] " << T.elapsed() << " ms" << endl;

  int j = 0;
  T.start();
  for (long i = 0; i < loops; ++i) j = i;
  T.stop();
  cout << "[" << j << "] " << T.elapsed() << " ms" << endl;

  j = 0;
  T.start();
  for (long i = 0; i < loops; ++i) j += 1;
  T.stop();
  cout << "[" << j  << "] " << T.elapsed() << " ms" << endl;

  T.start();
  for (long i = 0; i < loops; ++i) j *= 1;
  T.stop();
  cout << "[" << j << "] " << T.elapsed() << " ms" << endl;
  
  return 0;
}
