#include "amath583.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc == 2)
    {
        AOSMatrix A = readAOSMatrix(argv[1]);
        Vector x = readVector(cin);
        Vector y = A * x;
        writeVector(y, cout);
    }
    else if (argc == 3)
    {
        AOSMatrix A = readAOSMatrix(argv[1]);
        Vector x = readVector(argv[2]);
        Vector y = A * x;
        writeVector(y, cout);
    }
    else if (argc == 4)
    {
        AOSMatrix A = readAOSMatrix(argv[1]);
        Vector x = readVector(argv[2]);
        Vector y = A * x;
        writeVector(y, argv[3]);
    }
    else cout << "Usage: " << argv[0] << " matrixFile [ vectorInputFile ] [ vectorOutputFile ]" << endl;
    
    return 0;
}
