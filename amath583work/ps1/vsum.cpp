#include <iostream>
#include <string.h>
#include <vector>

int main()
{
  int n;
  char header[20], trailer[20];

  std::cin.getline(header, 20);
  if (strcmp(header, "AMATH 583 VECTOR") != 0) return -1;
  std::cin >> n;
  if (n < 0) return -2;
  std::vector<double> num(n);
  double sum = 0.0;
  for (int i = 0; i < n; ++i)
    { std::cin >> num[i]; sum += num[i]; }
  std::cin.ignore();
  std::cin.getline(trailer, 20);
  if (strcmp(trailer, "THIS IS THE END") != 0) return -1;  
  std::cout << sum << std::endl;
  
  return 0;
}
