#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using std::cin;
using std::exit;
using std::getline;
using std::string;
using std::vector;


vector<double> readVector()
{
  int int_input;
  string string_input;

  getline(cin,string_input);
  if (string_input.compare("AMATH 583 VECTOR") != 0) exit(-1);

  cin >> int_input;
  if (int_input < 0) exit(-2);

  vector<double> double_input(int_input);
  for (int i=0; i < int_input; i++)
    cin >> double_input[i];

  getline(cin,string_input); // This grabs the '\n' left by cin'
  getline(cin,string_input);

  if (string_input.compare("THIS IS THE END") != 0) exit(-1);

  return double_input;
}
