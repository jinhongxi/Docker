#include "vector.h"

std::vector<double> readVector()
{
  char header[20], trailer[20];
  std::cin.getline(header, 20);
  if (strcmp(header, "AMATH 583 VECTOR") != 0) exit(-1);

  int n;
  std::cin >> n;

  if (n < 0) exit(-2);
  std::vector<double> num(n);
  for (int i = 0; i < n; ++i) std::cin >> num[i];

  std::cin.ignore();
  std::cin.getline(trailer, 20);
  if (strcmp(trailer, "THIS IS THE END") != 0) exit(-1);

  return num;
}
