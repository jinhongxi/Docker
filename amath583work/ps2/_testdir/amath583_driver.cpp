#include <iostream>
#include <vector>
#include "amath583.hpp"

using std::cout;
using std::endl;
using std::vector;

int main()
{
  double sum;
  vector<double> v1(2);
  v1[0] = 1.0;
  v1[1] = 2.0;
  vector<double> v2(1);
  v2[0] = 3.0;

  cout << dot583(v1,v2) << endl;

  return 0;

}
