#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  (void) printf("pid = %d\n", getpid());
  return 0;
}
