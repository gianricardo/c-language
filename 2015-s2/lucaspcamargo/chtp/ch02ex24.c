/**
 * c02ex24.c - Even or odd?
 * © Lucas Pires Camargo
 * 
 * See LICENSE file at the root of this repository.
 */

#include <stdio.h>

int main(void)
{
    int n1;
    
    printf("Input an integer: ");
    scanf("%d", &n1);
    
    printf("The number is %s\n", (n1%2? "odd" : "even" ) );
    
    return 0;
}
