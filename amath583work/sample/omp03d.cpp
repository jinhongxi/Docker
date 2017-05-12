/*
 * Purpose: Estimate definite integral (or area under curve) using trapezoidal 
 *          rule.
 *
 * Input:   a, b, n
 * Output:  estimate of integral from a to b of f(x)
 *          using n trapezoids.
 *
 * Usage:   ./omp03d <number of threads>
 *
 * Notes:   
 *   1.  The function f(x) is hardwired.
 *   2.  In this version, each thread explicitly computes the integral
 *       over its assigned subinterval, a critical directive is used
 *       for the global sum.
 *   3.  This version assumes that n is evenly divisible by the 
 *       number of threads
 *
 * IPP:  Section 5.2.1 (pp. 216 and ff.)
 */

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

#ifdef _OPENMP
#include <omp.h>
#endif

void Usage(char* prog_name);
double f(double x);    /* Function we're integrating */

int main(int argc, char* argv[]) {

   double  global_result = 0.0;  /* Store result in global_result */
   double  a, b;                 /* Left and right endpoints      */
   int     n;                    /* Total number of trapezoids    */
   int     thread_count;
   int     i;

   if (argc != 2) Usage(argv[0]);
   thread_count = strtol(argv[1], NULL, 10);

   std::cout << "Enter a, b, and n\n";
   std::cin >> a >> b >> n;

   if (n % thread_count != 0) Usage(argv[0]);

   double h = (b-a)/n;
   global_result += 0.5*(f(a) + f(b));
#  pragma omp parallel for num_threads(thread_count) \
          reduction(+: global_result)
   for (i = 1; i < n; ++i)
   {
     double xi = a + i*h;
     global_result += f(xi);
   }
   global_result *= h;

   std::cout << "With n = " << n << " trapezoids, our estimate\n";
   std::cout << "of the integral from " << a << " to " << b;
   std::cout << " = " << std::setprecision(14) << global_result << "\n";

   return 0;
}  /* main */

/*--------------------------------------------------------------------
 * Function:    Usage
 * Purpose:     Print command line for function and terminate
 * In arg:      prog_name
 */
void Usage(char* prog_name) {

	std::cerr << "usage: " << prog_name << " <number of threads>\n";
	std::cerr << "   number of trapezoids must be evenly divisible by\n";
	std::cerr << "   number of threads\n";

	exit(0);

}  /* Usage */

/*------------------------------------------------------------------
 * Function:    f
 * Purpose:     Compute value of function to be integrated
 * Input arg:   x
 * Return val:  f(x)
 */
double f(double x) {
   double return_val;

   return_val = x*x;
   return return_val;
}  /* f */

