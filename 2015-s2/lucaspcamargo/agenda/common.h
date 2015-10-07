/**
 * @file common.h
 * @author Lucas Camargo
 * @date Oct 2015
 * @brief File containing common functions.
 */

#include "stdlib.h"
#include "stdio.h"

#define ALLOC_NEW(x) (x *) malloc(sizeof(x)); 

/**
 * clears stdin buffer
 */
void clearstdin()
{
  while(fgetc(stdin) != EOF)
  {
    // clear buffer
  }
}
