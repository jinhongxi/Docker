#include <iostream>
#include <string>

using namespace std; 

int main(int argc, char* argv[])
{
  if (argc < 2)
    {
      cout << "Usage: " << argv[0] << " N [ -o outputfile]" << endl;
      return 0;
    }
  
  int N = stoi(argv[1]);

  cout << N << endl;
  return 0;
}
