# include <iostream>

/* REQUIRES: x >= n
 * MODIFIES: nothing
 * EFFECTS: count from x down to n */
void count(int x, int n) {
  std::cout << x << std::endl;
  if (x > n) {count(x - 1, n); } // call the function itself
  else {return; } // base case
}


int main(void) {
  count(10, 1);
  return 0;
}
