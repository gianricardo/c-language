#include <stdio.h>

int main( void )
{
    int side = 8;
    

    for(int i = 0; i < side; i++)
    {
        
        if(i%2)
            printf(" ");
        
        for(int j = 0; j < side; j++)
        {
            printf("*");
            printf(" ");
        }
        
        printf("\n");
    
    }
    
    
    return 0;
}