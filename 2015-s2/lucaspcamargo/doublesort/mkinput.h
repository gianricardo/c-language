#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
int mkinput() {
  long c;
  double n;
 
  for (c = 0; c < 64000000; c++) {
    n = rand() / ((double) INT_MAX);
    printf("%lf\n", n);
  }
 
  return 0;
}