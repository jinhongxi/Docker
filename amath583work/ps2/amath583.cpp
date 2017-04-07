#include "amath583.h"

using namespace std;

vector<double> readVector(istream &inputStream)
{
    char header[20], trailer[20];
    inputStream.getline(header, 20);
    if (strcmp(header, "AMATH 583 VECTOR") != 0) exit(-1);
    
    int n;
    inputStream >> n;
    
    if (n < 0) exit(-2);
    vector<double> num(n);
    for (int i = 0; i < n; ++i) inputStream >> num[i];
    
    inputStream.ignore();
    inputStream.getline(trailer, 20);
    if (strcmp(trailer, "THIS IS THE END") != 0) exit(-1);
    
    return num;
}
