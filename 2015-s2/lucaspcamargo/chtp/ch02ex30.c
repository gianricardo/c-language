/**
 * c02ex30.c - Split digits
 * © Lucas Pires Camargo
 * 
 * See LICENSE file at the root of this repository.
 */

#include <stdio.h>

int main(void)
{
    int n;
    
    printf("Input a five-digit number: ");
    scanf("%d", &n);
    
    if( 9999 < n && n < 100000)
    {
        // number is valid
        // let's split it
        int d1 = (n / 10000) % 10;
        int d2 = (n / 1000) % 10;
        int d3 = (n / 100) % 10;
        int d4 = (n / 10) % 10;
        int d5 = (n / 1) % 10;
        
        // print the split digits
        printf("%d   %d   %d   %d   %d\n", d1, d2, d3, d4, d5);
    }
    else
    {
        // whoops
        printf("Invalid input. Terminating...\n");
        return -1;
    }

    return 0;
}