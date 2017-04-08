#include "amath583.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2 || string(argv[1]) == "0")
    {
        cout << "Usage: " << argv[0] << " N" << endl;
        return 0;
    }
    
    int N = atoi(argv[1]);
    if (N <= 0)
    {
        cout << "error -2: invalid number N" << endl;
        return -2;
    }

    vector<double> num = randomVector(N);
    for (int i = 0; i < N; ++i) cout << num[i] << endl;
    
    return 0;
}
