#include <iostream>
#include "Matrix.hpp"
#include "Vector.hpp"

using std::cout;
using std::endl;

int main()
{
  cout << "Setting 2x2 Matrix A(0,0) = 1, A(0,1) = 2, A(1,0) = 3, A(1,1) = 4" << endl;
  Matrix A(2,2);
  A(0,0) = 1.0;
  A(0,1) = 2.0;
  A(1,0) = 3.0;
  A(1,1) = 4.0;

  cout << endl << "Setting 2x1 Vector x(0) = 1, x(0) = 2" << endl;
  Vector x(2);
  x(0) = 1;
  x(1) = 2;

  cout << "x =" << endl;
  for (int i=0; i < x.numRows(); i++)
  {
    cout << x(i) << endl;
  }

  cout << endl << "Computing A*x" << endl;
  Vector y(2);
  y = A*x;

  cout << "A*x =" << endl;
  for (int i=0; i < y.numRows(); i++)
  {
    cout << y(i) << endl;
  }
  return 0;

}
