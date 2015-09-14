#include <stdio.h>


int main( void )
{
    float r = -1;
    const float pi = 3.14159;
    
    printf("Enter circle radius: ");
    scanf("%f", &r);
    
    printf("Diameter is %.2f\n", 2 * r);
    printf("Circumference is %.2f\n", 2 * pi * r);
    printf("Area is %.2f\n", pi * r * r);

    return 0;
}
