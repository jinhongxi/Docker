#include <iostream>

int main()
{
  int n;
  std::cin >> n;

  if (n < 0) return -2;

  std::cout << "AMATH 583 VECTOR" << std::endl << n << std::endl;
  for (int i = 0; i < n; ++i) std::cout << i << std::endl;
  std::cout << "THIS IS THE END" << std::endl;
  return 0;
}
