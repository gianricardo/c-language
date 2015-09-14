#include <stdio.h>

int main( void )
{

    for(int i = 0; i < 100; i++)
    {
        printf("*");

        if(!((i+1)%10))
            printf("\n");
    
    }
    
    return 0;
}