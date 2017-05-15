#include <iostream>
#include "Vector.hpp"

using std::cout;
using std::endl;

int main()
{
  cout << "Setting Vector x = [1, 2]^T" << endl;
  Vector x(2);
  x(0) = 1.0;
  x(1) = 2.0;

  cout << endl << "Calling ompTwoNorm(x): ";
  cout << ompTwoNorm(x) << endl;

  return 0;

}
