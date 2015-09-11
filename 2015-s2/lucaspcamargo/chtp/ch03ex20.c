#include <stdio.h>

int main()
{
    int days = 0;
    float rate = 0.0f, main = 0.0f, interest = 0.0f;

    while (main != -1)
    {
        printf("Inform loan amount (-1 to quit): ");
        scanf("%f",&main);
        
        if (main == -1) 
            continue;
        
        printf("Inform yearly interest rate: ");
        scanf("%f",&rate);
        
        printf("Enter loan term in days: ");
        scanf("%d",&days);
        
        interest = (main*rate*days) / 365.0f;
        printf("The amount of interest paid is R$%.2f: \n", interest);
    }
        
    return 0;
}
