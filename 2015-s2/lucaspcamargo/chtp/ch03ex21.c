#include <stdio.h>

int main()
{
    while(1)
    {
        int hours;
        float rate;
        
        printf("\nEnter hours worked (-1 to end): ");
        scanf("%d", &hours);
        
        if(hours == -1)
            break;        
        
        printf("\nEnter hourly rate of the worker: ");
        scanf("%d", &hours);
        
        if(hours > 40)
            printf("Salary is %.2f\n", 40 * rate + (hours - 40) * 1.5f * rate );
        else
            printf("Salary is %.2f\n", hours * rate);
        
    }
    
    return 0;
}