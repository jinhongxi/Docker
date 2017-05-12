#include <cstdlib>
#include <iostream>

#ifdef _OPENMP
#include <omp.h>
#endif


void Hello(void);
void Bye(void);


int main(int argc, char* argv[])
{

  if (argc < 2)
  {
	std::cout << "\n !!! Specify the number of threads at command line !!! " << std::endl;
    return -1;
  }

  /* Get the number of threads from the command line */
  int thread_count = strtol(argv[1], NULL, 10);

  /* The preprocessor command should hold on one line */
#pragma omp parallel num_threads(thread_count)
  Hello();

  std::cout << "\n";

#ifdef _OPENMP
  std::cout << " Number of Threads " << omp_get_num_threads() << std::endl;

  /* Return the maximum number of threads of the program. */
  std::cout << " Limit Number of Threads " << omp_get_thread_limit() << std::endl;

  /* Return the maximum number of threads used for the current parallel region that does not use the clause num_threads. */
  std::cout << " Maximum Number of Threads " << omp_get_max_threads() << std::endl;
  
  /* Returns the number of processors online on that device. */
  std::cout << " Number of Processors " << omp_get_num_procs() << std::endl;
  
  std::cout << std::endl;
#endif

  /* The character # must be on the first column */
#pragma omp parallel
  Bye();

  return 0;

}


void Hello(void)
{

#ifdef _OPENMP
  int my_rank = omp_get_thread_num();
  int thread_count = omp_get_num_threads();
#else
  int my_rank = 0;
  int thread_count = 1;
#endif

  std::cout << "Hello from thread " << my_rank << " of " << thread_count << std::endl;

}

void Bye(void)
{

#ifdef _OPENMP
  int my_rank = omp_get_thread_num();
  int thread_count = omp_get_num_threads();
#else
  int my_rank = 0;
  int thread_count = 1;
#endif

  std::cout << "Bye from thread " << my_rank << " of " << thread_count << std::endl;

}


