   Counter-controlled repetition with the for statement */
#include <stdio.h>

/* function main begins program execution */
int main( void )
{
   int counter = 1; /* define counter */

   /* initialization, repetition condition, and increment 
      are all included in the for statement header. */
   for ( counter; counter <= 10; counter++ ) {
      printf( "%d\n", counter );
   } /* end for */

   return 0; /* indicate program ended successfully */
} /* end function main */

