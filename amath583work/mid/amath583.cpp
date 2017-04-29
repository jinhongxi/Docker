#include "amath583.hpp"

using namespace std;


Vector readVector(istream &inputStream)
{
    if (!inputStream.good())
    {
        cout << "Error -3: failed to open the file" << endl;
        exit(-3);
    }
    
    char header[20], trailer[20];
    inputStream.getline(header, 20);
    if (strcmp(header, "AMATH 583 VECTOR") != 0)
    {
        cout << "Error -1: wrong header (AMATH 583 VECTOR required)" << endl;
        exit(-1);
    }
    
    int n; // numRows
    inputStream >> n;
    
    if (n < 0)
    {
        cout << "Error -2: negative integer" << endl;
        exit(-2);
    }
    
    // BEGIN CHANGE: FROM HW 2
    Vector vec(n);
    for (int i = 0; i < n; ++i) inputStream >> vec(i);
    // END CHANGE: FROM HW 2
    
    inputStream.ignore();
    inputStream.getline(trailer, 20);
    if (strcmp(trailer, "THIS IS THE END") != 0)
    {
        cout << "Error -1: wrong trailer (THIS IS THE END required)" << endl;
        exit(-1);
    }
    
    return vec;
}


Vector readVector(string inputFilename)
{
    ifstream inputStream(inputFilename.c_str());
    if (!inputStream.good())
    {
        cout << "Error -3: failed to open the file" << endl;
        exit(-3);
    }
    
    char header[20], trailer[20];
    inputStream.getline(header, 20);
    if (strcmp(header, "AMATH 583 VECTOR") != 0)
    {
        cout << "Error -1: wrong header (AMATH 583 VECTOR required)" << endl;
        exit(-1);
    }
    
    int n; // numRows
    inputStream >> n;
    
    if (n < 0)
    {
        cout << "Error -2: negative integer" << endl;
        exit(-2);
    }
    
    // BEGIN CHANGE: FROM HW 2
    Vector vec(n);
    for (int i = 0; i < n; ++i) inputStream >> vec(i);
    // END CHANGE: FROM HW 2
    
    inputStream.ignore();
    inputStream.getline(trailer, 20);
    if (strcmp(trailer, "THIS IS THE END") != 0)
    {
        cout << "Error -1: wrong trailer (THIS IS THE END required)" << endl;
        exit(-1);
    }
    
    inputStream.close();
    
    return vec;
}


void writeVector(const Vector &x, ostream &outputStream)
{
    if (!outputStream.good())
    {
        cout << "Error -3: failed to build the file" << endl;
        exit(-3);
    }
    
    outputStream << "AMATH 583 VECTOR" << endl << x.numRows() << endl;
    for (int i = 0; i < x.numRows(); ++i) outputStream << x(i) << endl;
    outputStream << "THIS IS THE END" << endl;
}


void writeVector(const Vector &x, string outputFilename)
{
    ofstream outputStream(outputFilename.c_str());
    
    if (!outputStream.good())
    {
        cout << "Error -3: failed to build the file" << endl;
        exit(-3);
    }
    
    outputStream << "AMATH 583 VECTOR" << endl << x.numRows() << endl;
    for (int i = 0; i < x.numRows(); ++i) outputStream << x(i) << endl;
    outputStream << "THIS IS THE END" << endl;
    
    outputStream.close();
}


// BEGIN CHANGE
Matrix readMatrix(istream &inputStream)
{
    if (!inputStream.good())
    {
        cout << "Error -3: failed to open the file" << endl;
        exit(-3);
    }
    
    int rows = 0, cols = 0, non0 = 0; // numRows, numCols, numNonZeros
    
    char header[25], trailer[25];
    inputStream.getline(header, 25);
    if (strcmp(header, "AMATH 583 DENSE MATRIX") == 0 || strcmp(header, "AMATH 583 MATRIX") == 0)
    {
        inputStream >> rows >> cols;
        non0 = rows * cols;
    }
    else if (strcmp(header, "AMATH 583 SPARSE MATRIX") == 0)
    {
        inputStream >> rows >> cols >> non0;
    }
    else
    {
        cout << "Error -1: wrong header (AMATH 583 DENSE/SPARSE MATRIX required)" << endl;
        exit(-1);
    }
    
    if (rows < 0 || cols < 0 || non0 < 0)
    {
        cout << "Error -2: negative integer" << endl;
        exit(-2);
    }
    
    Matrix mat(rows, cols);
    if (non0 != rows * cols)
    {
        zeroizeMatrix(mat);
        int r, c;
        for (int i = 0; i < non0; ++i) inputStream >> r >> c >> mat(r, c);
    }
    else
    {
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c) inputStream >> mat(r, c);
        }
    }
    
    inputStream.ignore();
    inputStream.getline(trailer, 20);
    if (strcmp(trailer, "THIS IS THE END") != 0)
    {
        cout << "Error -1: wrong trailer (THIS IS THE END required)" << endl;
        exit(-1);
    }
    
    return mat;
}


Matrix readMatrix(string inputFilename)
{
    ifstream inputStream(inputFilename.c_str());
    if (!inputStream.good())
    {
        cout << "Error -3: failed to open the file" << endl;
        exit(-3);
    }
    
    int rows = 0, cols = 0, non0 = 0; // numRows, numCols, numNonZeros
    
    char header[25], trailer[25];
    inputStream.getline(header, 25);
    if (strcmp(header, "AMATH 583 DENSE MATRIX") == 0 || strcmp(header, "AMATH 583 MATRIX") == 0)
    {
        inputStream >> rows >> cols;
        non0 = rows * cols;
    }
    else if (strcmp(header, "AMATH 583 SPARSE MATRIX") == 0)
    {
        inputStream >> rows >> cols >> non0;
    }
    else
    {
        cout << "Error -1: wrong header (AMATH 583 DENSE/SPARSE MATRIX required)" << endl;
        exit(-1);
    }
    
    if (rows < 0 || cols < 0 || non0 < 0)
    {
        cout << "Error -2: negative integer" << endl;
        exit(-2);
    }
    
    Matrix mat(rows, cols);
    if (non0 != rows * cols)
    {
        zeroizeMatrix(mat);
        int r, c;
        for (int i = 0; i < non0; ++i) inputStream >> r >> c >> mat(r, c);
    }
    else
    {
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c) inputStream >> mat(r, c);
        }
    }
    
    inputStream.ignore();
    inputStream.getline(trailer, 20);
    if (strcmp(trailer, "THIS IS THE END") != 0)
    {
        cout << "Error -1: wrong trailer (THIS IS THE END required)" << endl;
        exit(-1);
    }
    
    inputStream.close();
    
    return mat;
}


COOMatrix readCOOMatrix(istream &inputStream)
{
    if (!inputStream.good())
    {
        cout << "Error -3: failed to open the file" << endl;
        exit(-3);
    }
    
    int rows = 0, cols = 0, non0 = 0; // numRows, numCols, numNonZeros
    
    char header[25], trailer[25];
    inputStream.getline(header, 25);
    if (strcmp(header, "AMATH 583 DENSE MATRIX") == 0 || strcmp(header, "AMATH 583 MATRIX") == 0)
    {
        inputStream >> rows >> cols;
        non0 = rows * cols;
    }
    else if (strcmp(header, "AMATH 583 SPARSE MATRIX") == 0)
    {
        inputStream >> rows >> cols >> non0;
    }
    else
    {
        cout << "Error -1: wrong header (AMATH 583 DENSE/SPARSE MATRIX required)" << endl;
        exit(-1);
    }
    
    if (rows < 0 || cols < 0 || non0 < 0)
    {
        cout << "Error -2: negative integer" << endl;
        exit(-2);
    }
    
    COOMatrix mat(rows, cols);
    
    if (non0 != rows * cols)
    {
        int r, c, val;
        for (int i = 0; i < non0; ++i)
        {
            inputStream >> r >> c >> val;
            mat.push_back(r, c, val);
        }
    }
    else
    {
        int val;
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                inputStream >> val;
                mat.push_back(r, c, val);
            }
        }
    }
    
    inputStream.ignore();
    inputStream.getline(trailer, 20);
    if (strcmp(trailer, "THIS IS THE END") != 0)
    {
        cout << "Error -1: wrong trailer (THIS IS THE END required)" << endl;
        exit(-1);
    }
    
    return mat;
}


COOMatrix readCOOMatrix(string inputFilename)
{
    ifstream inputStream(inputFilename.c_str());
    if (!inputStream.good())
    {
        cout << "Error -3: failed to open the file" << endl;
        exit(-3);
    }
    
    int rows = 0, cols = 0, non0 = 0; // numRows, numCols, numNonZeros
    
    char header[25], trailer[25];
    inputStream.getline(header, 25);
    if (strcmp(header, "AMATH 583 DENSE MATRIX") == 0 || strcmp(header, "AMATH 583 MATRIX") == 0)
    {
        inputStream >> rows >> cols;
        non0 = rows * cols;
    }
    else if (strcmp(header, "AMATH 583 SPARSE MATRIX") == 0)
    {
        inputStream >> rows >> cols >> non0;
    }
    else
    {
        cout << "Error -1: wrong header (AMATH 583 DENSE/SPARSE MATRIX required)" << endl;
        exit(-1);
    }
    
    if (rows < 0 || cols < 0 || non0 < 0)
    {
        cout << "Error -2: negative integer" << endl;
        exit(-2);
    }
    
    COOMatrix mat(rows, cols);
    
    if (non0 != rows * cols)
    {
        int r, c, val;
        for (int i = 0; i < non0; ++i)
        {
            inputStream >> r >> c >> val;
            mat.push_back(r, c, val);
        }
    }
    else
    {
        int val;
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                inputStream >> val;
                mat.push_back(r, c, val);
            }
        }
    }
    
    inputStream.ignore();
    inputStream.getline(trailer, 20);
    if (strcmp(trailer, "THIS IS THE END") != 0)
    {
        cout << "Error -1: wrong trailer (THIS IS THE END required)" << endl;
        exit(-1);
    }
    
    inputStream.close();
    
    return mat;
}


AOSMatrix readAOSMatrix(istream &inputStream)
{
    if (!inputStream.good())
    {
        cout << "Error -3: failed to open the file" << endl;
        exit(-3);
    }
    
    int rows = 0, cols = 0, non0 = 0; // numRows, numCols, numNonZeros
    
    char header[25], trailer[25];
    inputStream.getline(header, 25);
    if (strcmp(header, "AMATH 583 DENSE MATRIX") == 0 || strcmp(header, "AMATH 583 MATRIX") == 0)
    {
        inputStream >> rows >> cols;
        non0 = rows * cols;
    }
    else if (strcmp(header, "AMATH 583 SPARSE MATRIX") == 0)
    {
        inputStream >> rows >> cols >> non0;
    }
    else
    {
        cout << "Error -1: wrong header (AMATH 583 DENSE/SPARSE MATRIX required)" << endl;
        exit(-1);
    }
    
    if (rows < 0 || cols < 0 || non0 < 0)
    {
        cout << "Error -2: negative integer" << endl;
        exit(-2);
    }
    
    AOSMatrix mat(rows, cols);
    
    if (non0 != rows * cols)
    {
        int r, c, val;
        for (int i = 0; i < non0; ++i)
        {
            inputStream >> r >> c >> val;
            mat.push_back(r, c, val);
        }
    }
    else
    {
        int val;
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                inputStream >> val;
                mat.push_back(r, c, val);
            }
        }
    }
    
    inputStream.ignore();
    inputStream.getline(trailer, 20);
    if (strcmp(trailer, "THIS IS THE END") != 0)
    {
        cout << "Error -1: wrong trailer (THIS IS THE END required)" << endl;
        exit(-1);
    }
    
    return mat;
}


AOSMatrix readAOSMatrix(string inputFilename)
{
    ifstream inputStream(inputFilename.c_str());
    if (!inputStream.good())
    {
        cout << "Error -3: failed to open the file" << endl;
        exit(-3);
    }
    
    int rows = 0, cols = 0, non0 = 0; // numRows, numCols, numNonZeros
    
    char header[25], trailer[25];
    inputStream.getline(header, 25);
    if (strcmp(header, "AMATH 583 DENSE MATRIX") == 0 || strcmp(header, "AMATH 583 MATRIX") == 0)
    {
        inputStream >> rows >> cols;
        non0 = rows * cols;
    }
    else if (strcmp(header, "AMATH 583 SPARSE MATRIX") == 0)
    {
        inputStream >> rows >> cols >> non0;
    }
    else
    {
        cout << "Error -1: wrong header (AMATH 583 DENSE/SPARSE MATRIX required)" << endl;
        exit(-1);
    }
    
    if (rows < 0 || cols < 0 || non0 < 0)
    {
        cout << "Error -2: negative integer" << endl;
        exit(-2);
    }
    
    AOSMatrix mat(rows, cols);
    
    if (non0 != rows * cols)
    {
        int r, c, val;
        for (int i = 0; i < non0; ++i)
        {
            inputStream >> r >> c >> val;
            mat.push_back(r, c, val);
        }
    }
    else
    {
        int val;
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                inputStream >> val;
                mat.push_back(r, c, val);
            }
        }
    }
    
    inputStream.ignore();
    inputStream.getline(trailer, 20);
    if (strcmp(trailer, "THIS IS THE END") != 0)
    {
        cout << "Error -1: wrong trailer (THIS IS THE END required)" << endl;
        exit(-1);
    }
    
    inputStream.close();
    
    return mat;
}


CSCMatrix readCSCMatrix(istream &inputStream)
{
    if (!inputStream.good())
    {
        cout << "Error -3: failed to open the file" << endl;
        exit(-3);
    }
    
    int rows = 0, cols = 0, non0 = 0; // numRows, numCols, numNonZeros
    
    char header[25], trailer[25];
    inputStream.getline(header, 25);
    if (strcmp(header, "AMATH 583 DENSE MATRIX") == 0 || strcmp(header, "AMATH 583 MATRIX") == 0)
    {
        inputStream >> rows >> cols;
        non0 = rows * cols;
    }
    else if (strcmp(header, "AMATH 583 SPARSE MATRIX") == 0)
    {
        inputStream >> rows >> cols >> non0;
    }
    else
    {
        cout << "Error -1: wrong header (AMATH 583 DENSE/SPARSE MATRIX required)" << endl;
        exit(-1);
    }
    
    if (rows < 0 || cols < 0 || non0 < 0)
    {
        cout << "Error -2: negative integer" << endl;
        exit(-2);
    }
    
    CSCMatrix mat(rows, cols);
    mat.openForPushBack();
    
    if (non0 != rows * cols)
    {
        int r, c, val;
        for (int i = 0; i < non0; ++i)
        {
            inputStream >> r >> c >> val;
            mat.push_back(r, c, val);
        }
    }
    else
    {
        int val;
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                inputStream >> val;
                mat.push_back(r, c, val);
            }
        }
    }
    mat.closeForPushBack();
    
    inputStream.ignore();
    inputStream.getline(trailer, 20);
    if (strcmp(trailer, "THIS IS THE END") != 0)
    {
        cout << "Error -1: wrong trailer (THIS IS THE END required)" << endl;
        exit(-1);
    }
    
    return mat;
}


CSCMatrix readCSCMatrix(string inputFilename)
{
    ifstream inputStream(inputFilename.c_str());
    if (!inputStream.good())
    {
        cout << "Error -3: failed to open the file" << endl;
        exit(-3);
    }
    
    int rows = 0, cols = 0, non0 = 0; // numRows, numCols, numNonZeros
    
    char header[25], trailer[25];
    inputStream.getline(header, 25);
    if (strcmp(header, "AMATH 583 DENSE MATRIX") == 0 || strcmp(header, "AMATH 583 MATRIX") == 0)
    {
        inputStream >> rows >> cols;
        non0 = rows * cols;
    }
    else if (strcmp(header, "AMATH 583 SPARSE MATRIX") == 0)
    {
        inputStream >> rows >> cols >> non0;
    }
    else
    {
        cout << "Error -1: wrong header (AMATH 583 DENSE/SPARSE MATRIX required)" << endl;
        exit(-1);
    }
    
    if (rows < 0 || cols < 0 || non0 < 0)
    {
        cout << "Error -2: negative integer" << endl;
        exit(-2);
    }
    
    CSCMatrix mat(rows, cols);
    mat.openForPushBack();
    
    if (non0 != rows * cols)
    {
        int r, c, val;
        for (int i = 0; i < non0; ++i)
        {
            inputStream >> r >> c >> val;
            mat.push_back(r, c, val);
        }
    }
    else
    {
        int val;
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                inputStream >> val;
                mat.push_back(r, c, val);
            }
        }
    }
    mat.closeForPushBack();
    
    inputStream.ignore();
    inputStream.getline(trailer, 20);
    if (strcmp(trailer, "THIS IS THE END") != 0)
    {
        cout << "Error -1: wrong trailer (THIS IS THE END required)" << endl;
        exit(-1);
    }
    
    inputStream.close();
    
    return mat;
}
// END CHANGE


void matvec(const Matrix& A, const Vector& x, Vector& y)
{
    for (int i = 0; i < A.numRows(); ++i)
    {
        for (int j = 0; j < x.numRows(); ++j)
        {
            y(i) += A(i, j) * x(j);
        }
    }
}


Vector operator* (const Matrix& A, const Vector& x)
{
    // BEGIN CHANGE: FROM HW 4
    if (A.numCols() != x.numRows())
    {
        cout << "Error -4: unmatched dimensions" << endl;
        exit(-4);
    }
    // END CHANGE: FROM HW 4
    
    Vector y(A.numRows());
    for (int i = 0; i < y.numRows(); ++i) y(i) = 0.0;
    
    matvec(A, x, y);
    
    return y;
}
