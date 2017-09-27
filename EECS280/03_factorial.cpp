# include <iostream>

/* REQUIRES: x >= 0
 * MODIFIES: nothing
 * EFFECTS: returns factorial n! by recursive implementation
 * NOTE: multiplications performed = x (only in recursive cases)
 *       max stack frames = x + 1 (linear space) */
int fact_re(int x) {
  if (x > 1) {return x * fact_re(x - 1);} // recursive case
  // not tail-recursive: multiplication need to be done after recursive func
  else {return 1; } // base case
}


/* REQUIRES: x >= 0
 * MODIFIES: nothing
 * EFFECTS: returns factorial n! by iterative implementation
 * NOTE: multiplications performed = x
 *       max stack frames = 2 (const space) */
int fact_it(int x) {
  int result = 1;
  for (int i = 1; i <= x; ++i) {
    result *= i;
  }
  return result;
}


/* REQUIRES: x >= 0
 * MODIFIES: nothing
 * EFFECTS: returns factorial n! by tail-recursive implementation
 * NOTE: tail-recursive can be optimized by g++
 *       changed from linear space to const space
 */
int fact_result = 1; // make a shared object to loop 'fact_ta'

int fact_ta(int x) {
  if (x == 1) {return fact_result;} // base case
  else {
    fact_result *= x;
    return fact_ta(x - 1); // tail call
    // tail recursive, no work need to be done after recursive func
  }
}


int main(void) {
  std::cout << fact_re(10) << " (recursive)" << std::endl;
  std::cout << fact_it(10) << " (iterative)" << std::endl;
  std::cout << fact_ta(10) << " (tail recursive)" << std::endl;
  return 0;
}
