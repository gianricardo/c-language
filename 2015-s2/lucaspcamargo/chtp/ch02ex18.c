/**
 * c02ex18.c - Comparing integers
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
    
    if(n1 > n2)
        printf("%d is bigger\n", n1);
    
    if(n2 > n1)
        printf("%d is bigger\n", n2);
    
    if(n2 == n1)
        printf("These numbers are equal\n");
    
    return 0;
}
