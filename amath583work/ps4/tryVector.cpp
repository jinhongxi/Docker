#include <iostream>
#include "Matrix.hpp"
#include "Vector.hpp"

using namespace std;

void matvec(const Matrix& A, const Vector& x, Vector& y);
Vector operator* (const Matrix& A, const Vector& x);

int main()
{
    Matrix A(2,3);
    cout << "A = [";
    for (int i = 0; i < A.numRows(); ++i)
    {
        if (i != 0) cout << "     ";
        for (int j = 0; j < A.numCols(); ++j)
        {
            A(i, j) = i * A.numCols() + j + 1;
            cout << " " << A(i, j);
        }
        if (i == A.numRows() - 1) cout << " ]";
        cout << endl;
    }
    
    Vector x(3);
    cout << "x = [";
    for (int i = 0; i < x.numRows(); ++i)
    {
        x(i) = i + 1;
        cout << " " << x(i);
    }
    cout << " ].T" << endl;
    
    Vector y(2);
    zeroize(y);
    matvec_inner(A, x, y);
    cout << "y = [";
    for (int i = 0; i < y.numRows(); ++i)
    {
        cout << " " << y(i);
    }
    cout << " ] (inner)" << endl;
    
    zeroize(y);
    matvec_outer(A, x, y);
    cout << "y = [";
    for (int i = 0; i < y.numRows(); ++i)
    {
        cout << " " << y(i);
    }
    cout << " ] (outer)" << endl;
    
    zeroize(y);
    matvec_student(A, x, y);
    cout << "y = [";
    for (int i = 0; i < y.numRows(); ++i)
    {
        cout << " " << y(i);
    }
    cout << " ] (student)" << endl;
    
    return 0;
}
