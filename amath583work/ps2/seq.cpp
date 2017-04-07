#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

void showSeq(int n, string outputFilename)
{
    if (string(outputFilename) == "") for (int m = 0; m < n; ++m) cout << m << endl;
    else
    {
        ofstream outputfile;
        
        outputfile.open(outputFilename.c_str());
        for (int m = 0; m < n; ++m) outputfile << m << endl;
        outputfile.close();
    }
}

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
            cout << "Error -1: N undeclared" << endl;
            return -1;
        }
        else if (N <= 0)
        {
            cout << "Error -2: Invalid number N" << endl;
            return -2;
        }
        
        if (argc == 2)
        {
            showSeq(N, outputFilename);
            return 0;
        }
        else
        {
            for (int i = 2; i < argc; ++i)
            {
	      if (string(argv[i]) == "-o" && (argc <= i + 1 || string(argv[i + 1]) == "]"))
                {
                    cout << "Error -3: outputfile undeclared" << endl;
                    return -3;
                }
                else if (string(argv[i]) == "-o")
                {
                    outputFilename = argv[i + 1];
                    showSeq(N, outputFilename);
                    return 0;
                }
            }
            cout << "Error -4: flag undeclared" << endl;
            return -4;
        }
    }
    return 0;
}
