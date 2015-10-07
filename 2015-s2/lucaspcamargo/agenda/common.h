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
