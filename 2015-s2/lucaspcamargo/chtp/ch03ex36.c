#include <stdio.h>

int main( void )
{
    int n = 0, accum = 0, pos = 1;
    printf("Enter a binary number: ");
    scanf("%d", &n);

    while(n)
    {
        accum += (n%10? pos : 0);
        
        pos *= 2;
        
        n = n / 10;
        printf("%d %d\n", n, accum);
    }
    
    printf("Number is %d\n", accum);
    
    return 0;
}