/**
 * @file mkinput.h
 * @author Lucas Camargo
 * @date Oct 2015
 * @brief Writes a lot of random doubles to stdout.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * Writes a lot of doubles to stdout
 */
int mkinput() {
  long c;
  double n;
 
  for (c = 0; c < 8000000; c++) {
    n = rand() / ((double) INT_MAX);
    printf("%lf\n", n);
  }
 
  return 0;
}