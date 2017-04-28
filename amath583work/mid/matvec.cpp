#include "amath583.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " matrixFile [ cin / vectorInputFile ] [ cout / vectorOutputFile ]" << endl;
        return 0;
    }
    else
    {
        Vector mat = readVector(string(argv[1]));
    }
    /*else if (string(argv[2]) == "cin")
    {
        cout << "Reading from cin" << endl;
        double sum = 0.0;
        vector<double> num = readVector(cin);
        for (int i = 0; i < num.size(); ++i)
        {
            cout << num[i] << endl;
            sum += num[i];
        }
        cout << sum << endl;
    }
    else
    {
        double sum = 0.0;
        ifstream inputStream(argv[1]);
        if (inputStream.good())
        {
            cout << "Reading from " << argv[1] << endl;
            vector<double> num = readVector(inputStream);
            for (int i = 0; i < num.size(); ++i)
            {
                cout << num[i] << endl;
                sum += num[i];
            }
            cout << sum << endl;
        }
        else
        {
            cout << "error -3: failed to open " << argv[1] << endl;
            return -3;
        }
    }*/
    
    return 0;
}