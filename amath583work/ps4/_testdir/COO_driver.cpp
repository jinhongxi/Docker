#include <iostream>
#include "COO.hpp"
#include "Vector.hpp"

using std::cout;
using std::endl;

int main()
{
  cout << "Setting 2x2 Matrix A(0,0) = 1, A(0,1) = 2, A(1,0) = 3, A(1,1) = 4 in COO format" << endl;
  COOMatrix A(2,2);
  A.push_back(0,0,1.0);
  A.push_back(0,1,2.0);
  A.push_back(1,0,3.0);
  A.push_back(1,1,4.0);

  A.streamMatrix(cout);

  cout << endl << "Setting 2x1 Vector x(0) = 1, x(0) = 2" << endl;
  Vector x(2);
  x(0) = 1;
  x(1) = 2;

  cout << endl << "Computing transpose(A)*x" << endl;
  Vector y(2);
  A.trMatvec(x,y);

  cout << "transpose(A)*x =" << endl;
  for (int i=0; i < y.numRows(); i++)
  {
    cout << y(i) << endl;
  }
  return 0;

}
