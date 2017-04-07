#include "amath583.h"

using namespace std;

int main(int argc, char *argv[])
{
    int n = 0;
    
    if (argc < 2 || string(argv[1]) == "0") n = rand();
    else n = atoi(argv[1]);

    vector<double> x = randomVector(n);
    sort(x.begin(), x.end());
    double n1 = twoNorm(x);
    sort(x.rbegin(), x.rend());
    double n2 = twoNorm(x);
    cout << n1 << " " << n2 << " " << (n1 - n2) << endl;
    
    return 0;
}
