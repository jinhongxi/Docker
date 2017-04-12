#include "amath583.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2 || string(argv[1]) == "0")
    {
        cout << "Usage: " << argv[0] << " N (float)" << endl;
        return 0;
    }
    
    int n = atoi(argv[1]);
    if (n <= 0)
    {
        cout << "error -2: invalid number N" << endl;
        return -2;
    }
    
    vector<double> x = randomVector(n);
    sort(x.begin(), x.end());
    double n1 = twoNorm(x);
    sort(x.rbegin(), x.rend());
    double n2 = twoNorm(x);
    cout << n1 << " " << n2 << " " << (n1 - n2) << endl;
    
    if (argc >= 3 && (string(argv[2]) == "float" || string(argv[2]) == "f" || string(argv[2]) == "fl"))
    {
        vector<float> y = dtof(x);
        sort(y.begin(), y.end());
        double m1 = twoNorm(y);
        sort(y.rbegin(), y.rend());
        double m2 = twoNorm(y);
        cout << m1 << " " << m2 << " " << (m1 - m2) << " (Floating-Point)" <<  endl;
    }
    
    return 0;
}
