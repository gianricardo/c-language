/**
 * c02ex27.c - printf(...) checkerboard
 * © Lucas Pires Camargo
 * 
 * See LICENSE file at the root of this repository.
 */

#include <stdio.h>

int main(void)
{
    
    // using eight statements
    printf("* * * * * * * * \n");
    printf(" * * * * * * * *\n");
    printf("* * * * * * * * \n");
    printf(" * * * * * * * *\n");
    printf("* * * * * * * * \n");
    printf(" * * * * * * * *\n");
    printf("* * * * * * * * \n");
    printf(" * * * * * * * *\n");
    
    //let's skip a couple lines
    printf("\n\n");
    
    // It can be done in a single (retarded) statement
    printf("* * * * * * * * \n * * * * * * * *\n* * * * * * * * \n * * * * * * * *\n* * * * * * * * \n * * * * * * * *\n* * * * * * * * \n * * * * * * * *\n");
    
    //let's skip a couple lines again
    printf("\n\n");
    
    return 0;
}

