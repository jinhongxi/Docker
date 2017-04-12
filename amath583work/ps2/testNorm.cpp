#include "amath583.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  if (argc < 2 || string(argv[1]) == "0")
    {
      cout << "Usage: " << argv[0] << " N" << endl;
      return 0;
    }

  int n = atoi(argv[1]);
  if (n <= 0)
    {
      cout << "error -2: invalid number N" << endl;
      return -2;
    }

  vector<double> x(n);
  x[0] = 1;
  for (int i = 1; i < n; ++i) x[i]= (double) 1 / n;
  sort(x.begin(),x.end());
  double N1 = twoNorm(x);
  reverse(x.begin(), x.end());
  double N2 = twoNorm(x);
  cout << N1 << " " << N2 << " " << N1 - N2 << endl;

  return 0;
}
