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
  return tp.tv_sec + tp.tv_usec/1000000.0;

}


int main(int argc, char* argv[])
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
  srand(1);
  for (int i = 0; i < n; ++i) {
    double *Ai = &A[i*n];
    for (int j = 0; j < n; ++j)
    {
      if (i == j)
      {
        Ai[j] = n/10.0;
      }
      else
      {
        Ai[j] = ((double) rand())/RAND_MAX;
      }
    }
  }

  std::vector<double> U(A);

  /*
   * Create the right-hand size
   */
  
  std::vector<double> xtilde(n, 1.0), x(n, 0.0), btilde(n, 0.0);

  for (int i = 0; i < n; ++i)
  {
	b[i] = 0.0;
    for (int j = 0; j < n; ++j)
    {
      b[i] += A[j + i*n] * xtilde[j];
    }
    btilde[i] = b[i];
  }
  
  /*
   * Do the Gaussian elimination
   */
 
  
  double time1 = -getTime();
  for (int i = 0; i < n-1; ++i)
  {

    double invDiag = 1.0 / U[i + i*n];

    for (int k = i+1; k < n; ++k)
    {
      double *Uk = &U[k*n];
      double fact = - Uk[i] * invDiag;
      Uk[i] = 0.0;
      for (int j = i+1; j < n; ++j)
      {
        Uk[j] += fact * U[j + i*n];
      }
      b[k] += fact * b[i];
    }
  }
  time1 += getTime();

  double time2 = -getTime();
  for (int i = n - 1; i >= 0; --i)
  {

    double xtmp = b[i];
      
    for (int j = i + 1; j < n; ++j)
    {
      xtmp += - U[j + i*n] * x[j];
    }

    {
      x[i] = xtmp / U[i*n + i];        
    }
      
  }
  time2 += getTime();

  double error = 0.0;
  for (int i = 0; i < n; ++i)
  {
    error += (x[i] - xtilde[i]) * (x[i] - xtilde[i]);
  }
  error = sqrt(error);
  
  std::cout << "\n";
  std::cout << " ... Relative error " << error << "\n";

  std::cout << "\n";
  std::cout << " ... Time for upper-triangular transformation " << time1 << "\n";
  std::cout << " ... Time for backward substitution           " << time2 << "\n";
  std::cout << " ... Total Time = " << time1 + time2 << "\n";
  std::cout << "\n";

  return 0;

}


