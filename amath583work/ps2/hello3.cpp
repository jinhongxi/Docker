#include <iostream>
#include <cassert>

#define NDEBUG

using namespace std;

int main()
{
  assert(1 == 0 && "This is never true");
  cout << "Hello World" << endl;
  return 0;
}
