#include <iostream>
#include "CSR.hpp"

using std::cout;
using std::endl;

int main()
{
  cout << "Setting Matrix A such that A(0,0) = 1, A(0,1) = 2, A(1,0) = 3, A(1,1) = 0" << endl;

  CSRMatrix A(2,2);
  A.openForPushBack();
  A.push_back(0,0,1.0);
  A.push_back(0,1,2.0);
  A.push_back(1,0,3.0);
  A.closeForPushBack();

  cout << "Setting Vector x = [1, 2]^T" << endl;
  Vector x(2);
  x(0) = 1.0;
  x(1) = 2.0;

  Vector y(2);
  zeroize(y);
  cout << endl << "Calling ompMatvec(A,x,y)" << endl;
  ompMatvec(A,x,y);
  cout << "Result y is" << endl;

  for (unsigned int i=0; i < y.numRows(); i++)
  {
    cout << y(i) << endl;
  }

  return 0;

}
