#include <iostream>
#include "Vector.hpp"

using namespace std;

int main()
{
    Vector A(3);
    randomize(A);
    for (int i = 0; i < 3; ++i)
    {
        cout << " " << A(i);
    }
    cout << endl;
    return 0;
}
