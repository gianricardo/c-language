/**
 * c02ex20.c - Circle stats
 * © Lucas Pires Camargo
 * 
 * See LICENSE file at the root of this repository.
 */

#include <stdio.h>

int main(void)
{
    float r;
    const float pi = 3.14159f;
    
    printf("Input circle radius: ");
    scanf("%f", &r);
    
    printf("The diameter is %f\n", 2 * r );
    printf("The circunference is %f\n", 2 * pi * r );
    printf("The area is %f\n", pi * r * r );
    
    return 0;
}

