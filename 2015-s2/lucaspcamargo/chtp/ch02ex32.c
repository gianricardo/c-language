/**
 * c02ex32.c - BMI Calculator
 * © Lucas Pires Camargo
 * 
 * See LICENSE file at the root of this repository.
 */

#include <stdio.h>

int main(void)
{
    float weight, height;
    
    printf("Input weight (in kilograms): ");
    scanf("%f", &weight);

    printf("Input height (in meters): ");
    scanf("%f", &height);
    
    printf("\nBMI VALUES \nUnderweight: \tless than 18.5 \nNormal: \tbetween 18.5 and 24.9\nOverweight:\tbetween 25 and 29.9\nObese:\t30 or greater\n");
    printf("\nYour BMI is %.2f\n", weight / (height * height) );
    
    return 0;
}