#include "amath583.h"

using namespace std;

vector<double> readVector(istream &inputStream)
{
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
    vector<double> num(n);
    for (int i = 0; i < n; ++i) inputStream >> num[i];
    
    inputStream.ignore();
    inputStream.getline(trailer, 20);
    if (strcmp(trailer, "THIS IS THE END") != 0)
    {
        cout << "error -1: wrong trailer" << endl;
        exit(-1);
    }
    
    return num;
}

std::vector<double> randomVector(int n)
{
    vector<double> num(n);
    for (int i = 0; i < n; ++i) num[i] = (double)rand() / rand();
    return num;
}
