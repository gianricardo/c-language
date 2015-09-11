#include <stdio.h>

int main( void )
{
    int n = 1;

    while(n <= 300000000)
    {
        if(!(n%100000000))
        {
            printf("%d\n", n);
        }
        
        n++;
    }
    
    return 0;
}