#include <iostream>
#include "Matrix.hpp"

using namespace std;

int main()
{
    Matrix A(3,3);
    randomizeMatrix(A);
    for (int i = 0; i < A.numRows(); ++i)
    {
        for (int j = 0; j < A.numCols(); ++j)
        {
            cout << " " << A(i,j);
        }
        cout << ";" << endl;
    }
  return 0;
}
