#include <stdio.h>


int main( void )
{
    int n = -1, fac = 1;
    
    printf("Enter positive integer: ");
    scanf("%d", &n);
    
    while(n > 0)
    {
        fac *= n;
        n--;
    }
    
    printf("Factorial is: %d\n", fac);
    
    return 0;
}
