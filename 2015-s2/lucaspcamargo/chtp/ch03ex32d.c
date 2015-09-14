#include <stdio.h>

int main( void )
{
    int x = 5; 
    int y = 7; 

    if ( y == 8 )
    {
        if ( x == 5 )
            printf( "@@@@@\n");
    }
    else
    {
        printf( "#####\n");
        printf( "$$$$$\n");
        printf( "&&&&&\n");
    }
    return 0;
}