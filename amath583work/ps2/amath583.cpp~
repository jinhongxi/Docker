#include "amath583.h"

using namespace std;

vector<double> readVector(istream &inputStream)
{
    if (!inputStream.good()) exit(-3);
    
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

vector<double> readVector(string inputFilename)
{
    ifstream inputStream(inputFilename.c_str());
    if (!inputStream.good()) exit(-3);
    
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

void writeVector(const vector<double> &x, ostream &outputStream)
{
    if (!outputStream.good()) exit(-3);
    
    for (int i = 0; i < x.size(); ++i) outputStream << x[i] << endl;
}

void writeVector(const vector<double> &x, string outputFilename)
{
    ofstream outputStream(outputFilename.c_str());
    
    if (!outputStream.good()) exit(-3);
    
    for (int i = 0; i < x.size(); ++i) outputStream << x[i] << endl;
}

vector<double> randomVector(int n)
{
    vector<double> num(n);
    
    for (int i = 0; i < n; ++i) num[i] = (double)rand() / (double)RAND_MAX;
    
    return num;
}

double twoNorm(const vector<double> &x)
{
    double sum = 0.0;
    
    for (int i = 0; i < x.size(); ++i) sum += x[i] * x[i];
    
    return sqrt(sum);
}

double dot583(const vector<double> &x, const vector<double> &y)
{
    if (x.size() != y.size()) exit(-1);
    
    double sum = 0.0;
    
    for (int i = 0; i < x.size(); ++i) sum += x[i] * y[i];
    
    return sum;
}
