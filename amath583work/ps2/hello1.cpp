#include <iostream>
#include <cassert>

using namespace std;

int main()
{
  assert(1 == 1 && "This is true");
  assert(1 == 0 && "This is never true");
  cout << "Hello World" << endl;
  return 0;
}
