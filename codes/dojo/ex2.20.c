#include <stdio.h>

int main(void)
{

    float r;
    const float PI = 3.14159;

    printf("Insert circle radius: ");
    scanf("%f", &r);

    printf("Diameter is %.2f\n", 2*r);
    printf("Circumference is %.2f\n", PI*r*2);
    printf("Area is %.2f\n", PI*r*r);

    return 0;
}
