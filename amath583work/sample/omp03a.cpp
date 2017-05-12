/*
 * Purpose: Estimate definite integral (or area under curve) using trapezoidal 
 *          rule.
 *
 * Input:   a, b, n
 * Output:  estimate of integral from a to b of f(x)
 *          using n trapezoids.
 *
 * Usage:   ./omp03a <number of threads>
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
#include "omp.h"
#endif

void Usage(char* prog_name);
double f(double x);    /* Function we're integrating */
void Trap(double a, double b, int n, double* global_result_p);

int main(int argc, char* argv[]) {
   double  global_result = 0.0;  /* Store result in global_result */
   double  a, b;                 /* Left and right endpoints      */
   int     n;                    /* Total number of trapezoids    */
   int     thread_count;

   if (argc != 2) Usage(argv[0]);
   thread_count = strtol(argv[1], NULL, 10);

   std::cout << "Enter a, b, and n\n";
   std::cin >> a >> b >> n;

   if (n % thread_count != 0) Usage(argv[0]);
#  pragma omp parallel num_threads(thread_count) 
   Trap(a, b, n, &global_result);

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

/*------------------------------------------------------------------
 * Function:    Trap
 * Purpose:     Use trapezoidal rule to estimate definite integral
 * Input args:  
 *    a: left endpoint
 *    b: right endpoint
 *    n: number of trapezoids
 * Output arg:
 *    integral:  estimate of integral from a to b of f(x)
 */
void Trap(double a, double b, int n, double* global_result_p) {
   double  h, x, my_result;
   double  local_a, local_b;
   int  i, local_n;

#ifdef _OPENMP
   int my_rank = omp_get_thread_num();
   int thread_count = omp_get_num_threads();
#else
   int my_rank = 0;
   int thread_count = 1;
#endif

   h = (b-a)/n; 
   local_n = n/thread_count;  
   local_a = a + my_rank*local_n*h; 
   local_b = local_a + local_n*h; 
   my_result = (f(local_a) + f(local_b))/2.0; 
   for (i = 1; i <= local_n-1; i++) {
     x = local_a + i*h;
     my_result += f(x);
   }
   my_result = my_result*h; 

   std::cout << " rank " << my_rank << " computed " << std::setprecision(14) << my_result << "\n";

#  pragma omp critical 
   *global_result_p += my_result; 
}  /* Trap */
