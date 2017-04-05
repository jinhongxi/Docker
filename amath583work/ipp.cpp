#include <iostream>
using namespace std;

int main(int argv, char *argc[])
{
  int i = 0;

  cout << "i is initially " << i << endl;
  cout << "the pre-incremented value of i is " << ++i << endl;
  cout << "i is now " << i << endl;
  cout << "the post-incremented value of i is " << i++ << endl;
  cout << "i is now " << i << endl;
  i = i + 1;
  cout << "i = i + 1 gives " << i << endl;
  i += 1;
  cout << "i += 1 gives " << i << endl;
  
  return 0;
}
