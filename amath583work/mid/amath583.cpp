#include "amath583.hpp"

using namespace std;

Vector readVector(string inputFilename)
{
    ifstream inputStream;
    if (inputFilename == "cin") inputStream = cin;
    else
    {
        inputStream.open(inputFilename.c_str());
        if (!inputStream.good()) 
        {
           cout << "error -3: failed to open " << inputFilename << endl;
           exit(-3);
        }
    }
    
    char header[20], trailer[20];
    inputStream.getline(header, 20);
    if (strcmp(header, "AMATH 583 VECTOR") != 0)
    {
        cout << "error -1: wrong header" << endl;
        exit(-1);
    }
    
    int n;
    inputStream >> n;
    
    if (n < 0)
    {
        cout << "error -2: invalid number" << endl;
        exit(-2);
    }
    Vector num(n);
    for (int i = 0; i < n; ++i) inputStream >> num(i);
    
    inputStream.ignore();
    inputStream.getline(trailer, 20);
    if (strcmp(trailer, "THIS IS THE END") != 0)
    {
        cout << "error -1: wrong trailer" << endl;
        exit(-1);
    }
    
    inputStream.close();
    
    return num;
}

void writeVector(const Vector &x, string outputFilename)
{
    ofstream outputStream;
    if (outputFilename == "cout") outputStream = cout;
    else
    {
        outputStream.open(outputFilename.c_str());
        if (!outputStream.good())
        {
             cout << "error -3: failed to built " << outputFilename << endl;
            exit(-3);
        }
    }
    
    for (int i = 0; i < x.numRows(); ++i) outputStream << x(i) << endl;
    
    outputStream.close();
}