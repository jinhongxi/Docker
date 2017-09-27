# include <iostream>

/* REQUIRES: x, y (values)
 * MODIFIES: nothing
 * EFFECTS: nothing
 * NOTE: regular parameters past in by values, NOT by objects
 *       stack = 3 (x, y, temp) */
void swap(int x, int y) {
  int temp = x;
  x = y;
  y = temp;
}


/* REQUIRES: x, y (references)
 * MODIFIES: x, y
 * EFFECTS: swaps the values of x & y
 * NOTE: parameters past in by references are past in by objects
 * stack = 3 (x, y, temp) */
void paws(int& x, int& y) {
  int temp = x;
  x = y;
  y = temp;
}


// stack = 2 (a, b)
// max memory used at one time = 3
// max stack frames = 2 (main, swap / paws)
int main(void) {
  int a = 3;
  int b = 7;
  std::cout << a << ", " << b << std::endl;
  swap(a, b); // pass in values
  std::cout << a << ", " << b << " (past by values)" << std::endl;
  paws(a, b); // pass in references
  std::cout << a << ", " << b << " (past by references)" << std::endl;
  return 0;
}
