#include <stdio.h>

int main()
{
    float accum = 0.0f;
    int count = 0;
    
    while(1)
    {
        float g, m;
        
        printf("Enter the gallons used (-1 to end): ");
        scanf("%f", &g);
        
        if(g == -1.0f)
            break;
        
        printf("Enter the miles driven: ");
        scanf("%f", &m);
        
        printf("The miles / gallon for this tank was %.6f\n\n", m/g);
        
        accum =+ m/g;
        count ++;
    }
    
    printf("\nThe overall average miles/gallon was %.6f\n", accum/count);

    return 0;
}