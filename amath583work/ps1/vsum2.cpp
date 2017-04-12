#include "vector.h"

int main()
{
  std::vector<double>num = readVector();

  double sum = 0.0;
  for (int i = 0; i < num.size(); ++i) sum += num[i];
  std::cout << sum << std::endl;

  return 0;
}
