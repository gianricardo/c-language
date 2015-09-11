#include <stdio.h>

int main( void )
{
    int n = 0, accum = 0;
    printf("Enter a number: ");
    scanf("%d", &n);

    while(n)
    {
        accum += (((n%10) == 7)? 1 : 0);
        
        n = n / 10;
    }
    
    printf("Number contains %d sevens\n", accum);
    
    return 0;
}