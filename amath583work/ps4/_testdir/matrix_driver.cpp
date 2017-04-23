#include <iostream>
#include "Matrix.hpp"

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

  cout << "A =" << endl;
  for (int i=0; i < A.numRows(); i++)
  {
    for (int j=0; j < A.numCols(); j++)
    {
      cout << A(i,j) << " ";
    }
    cout << endl;
  }

  cout << endl << "Computing A*A*A" << endl;
  Matrix B(2,2);
  B = A * A * A;

  cout << "A*A =" << endl;
  for (int i=0; i < B.numRows(); i++)
  {
    for (int j=0; j < B.numCols(); j++)
    {
      cout << B(i,j) << " ";
    }
    cout << endl;
  }
  return 0;

}
