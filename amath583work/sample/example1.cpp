#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <sys/time.h>


/* --- Function to get current time --- */
double getTime()
{

  struct timeval tp;
  gettimeofday(&tp, NULL);
  return 1000.0*tp.tv_sec + tp.tv_usec/1000.0;

}


int main(int argc, char *argv[])
{

  if (argc <= 1)
  {
	std::cout << "\n ... The code requires one input parameter: an integer ...\n\n";
    return -1;
  }

  int n = (int) strtol(argv[1], NULL, 10);

  std::vector<double> b(n, 1.0);
  std::vector<double> A(n*n, 0.0);

  //--- Fill the matrix A
  //--- Store the matrix row by row
  for (int i = 0; i < n; ++i) {
	  double *Arow = &A[i*n];
	  Arow[i] = 12;
	  if (i > 0)
		  Arow[i-1] = -4;
	  if (i > 1)
		  Arow[i-2] = 1;
	  if (i + 1 < n)
		  Arow[i+1] = -4;
	  if (i + 2 < n)
		  Arow[i+2] = 1;
  }
 
  //--- Store the inverse of the diagonal entries of A
  std::vector<double> invD(n, 0.0);
  for (int i = 0; i < n; ++i)
	  invD[i] = 1.0/A[i + i*n];

  //--- Compute the norm of b
  double normb = 0.0;
  for (int i = 0; i < n; ++i)
	  normb += b[i] * b[i];
  normb = sqrt(normb);

  std::vector<double> r(n, 0.0);
  int itMax = 10000;
  double tol = 1.0e-04 * normb;

  //--- Start with a zero initial guess
  std::vector<double> x(n, 0.0);

  int it;
  double timer = -getTime();
  for (it = 0; it < itMax; ++it) {

	  //--- Compute the residual vector and its norm
	  double normr = 0.0;
	  for (int i = 0; i < n; ++i) {
		  r[i] = 0.0;
		  double *Arow = &A[i*n];
		  for (int j = 0; j < n; ++j)
			  r[i] += Arow[j] * x[j];
		  r[i] = b[i] - r[i];
		  normr += r[i] * r[i];
	  }

	  std::cout << " ... IT " << it << " norm " << sqrt(normr) << "\n";

	  if (sqrt(normr) < tol)
		  break;

	  //--- Update x
	  for (int i = 0; i < n; ++i)
		  x[i] = x[i] + invD[i] * r[i];

  } // for (it = 0; it < itMax; ++it)
  timer += getTime();

  std::cout << "\n";
  std::cout << " ... Finished in " << it << " iterations \n";
  std::cout << " ... Time " << timer/1000.0 << " s \n";
  std::cout << "\n";

  return 0;

}


