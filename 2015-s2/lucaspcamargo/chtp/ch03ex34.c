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
            if((i == 0 || i == (side-1)) || (j == 0 || j == (side-1)))
                printf("*");
            else
                printf(" ");
        }
        
        printf("\n");
    
    }
    
    
    return 0;
}