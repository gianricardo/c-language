#include <stdio.h>

/*
 * When run, this program overflows to a very large
 * negative number, and to zero, and stays there,
 * printing zeroes forever.
 */

int main( void )
{
    int n = 2;
    
    for(;;)
    {
        
        printf("%d ", n);
            
        n *= 2;
    }

    return 0;
}
