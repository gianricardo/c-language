#include <stdio.h>

int main( void )
{
    int side = 0;
    
    printf("Enter side: ");
    scanf("%d", &side);

    for(int i = 0; i < side; i++)
    {
        for(int j = 0; j < side; j++)
        {
            printf("*");
        }
        
        printf("\n");
    
    }
    
    
    return 0;
}