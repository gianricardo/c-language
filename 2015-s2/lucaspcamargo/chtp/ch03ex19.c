#include <stdio.h>

int main()
{
    while(1)
    {
        float sales;
        
        printf("\nEnter sales in dollars (-1 to end): ");
        scanf("%f", &sales);
        
        if(sales == -1.0f)
            break;
        
        printf("Salary is %.2f\n", 200.0f + 0.09f * sales );
        
    }
    
    return 0;
}