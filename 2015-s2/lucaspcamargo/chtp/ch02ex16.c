/**
 * c02ex16.c - Calculates numerical relationships between two numbers
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
    
    printf("Their sum is %d\n", n1 + n2);
    printf("Their product is %d\n", n1 * n2);
    printf("Their difference is %d\n", n1 - n2);
    printf("Their quotient is %d\n", n1 / n2);
    printf("Their remainder is %d\n", n1 % n2);
    return 0;
}
