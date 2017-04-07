#include "amath583.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " N [ -o outputfile]" << endl;
        return 0;
    }
    else
    {
        int N = atoi(argv[1]);
        string outputFilename = "";
        
        if (N == 0 && string(argv[1]) != "0")
        {
            cout << "error -1: N undeclared" << endl;
            return -1;
        }
        else if (N <= 0)
        {
            cout << "error -2: invalid number N" << endl;
            return -2;
        }
        
        if (argc == 2)
        {
            vector<double> num = randomVector(N);
            for (int i = 0; i < N; ++i) cout << num[i] << endl;
            return 0;
        }
        else
        {
            for (int i = 2; i < argc; ++i)
            {
                if (string(argv[i]) == "-o" && (argc <= i + 1 || string(argv[i + 1]) == "]"))
                {
                    cout << "error -3: outputfile undeclared" << endl;
                    return -3;
                }
                else if (string(argv[i]) == "-o")
                {
                    outputFilename = argv[i + 1];
                    vector<double> num = randomVector(N);
                    return 0;
                }
            }
            cout << "error -4: flag undeclared" << endl;
            return -4;
        }
    }
    
    return 0;
}
