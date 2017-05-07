#include <iostream>
#include "Vector.hpp"

using std::cout;
using std::endl;

int main()
{
  cout << "Setting Matrix A(0,0) = 1, A(0,1) = 2, A(1,0) = 3, A(1,1) = 4" << endl;
  Matrix A(2,2);
  A(0,0) = 1.0;
  A(0,1) = 2.0;
  A(1,0) = 3.0;
  A(1,1) = 4.0;

  cout << endl << "Setting Vector x(0) = 1, x(0) = 2" << endl;
  Vector x(2);
  x(0) = 1;
  x(1) = 2;

  cout << endl << "Calling task_matvec(A,x,y,1): " << endl;
  Vector y(2);
  zeroize(y);
  task_matvec(A,x,y,1);

  for (int i=0; i < y.numRows(); i++)
  {
    cout << y(i) << endl;
  }
  return 0;

}
