/**
 * c02ex26.c - Multiples
 * © Lucas Pires Camargo
 * 
 * See LICENSE file at the root of this repository.
 */

#include <stdio.h>

int main(void)
{
    int n1, n2;
    
    printf("Input two integers: ");
    scanf("%d%d", &n1, &n2);
    
    printf("The first number is%s a multiple of the second\n", (n1%n2? " not" : "" ));

    return 0;
}
