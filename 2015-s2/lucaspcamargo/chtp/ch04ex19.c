#include <stdio.h>

int main()
{
    int prod = 0;
    float total = 0.0f;
    
    while(prod >= 0)
    {
        printf("Enter product id (-1 to quit): ");
        scanf("%d", &prod );
        if(prod < 0)
            continue;
        
        float price = 0.0f;
        
        switch(prod)
        {
            case 1:
                price = 2.98f;
                
            case 2:
                price = 4.50f;
                
            case 3:
                price = 9.98f;
                
            case 4:
                price = 4.49f;
                
            case 5:
                price = 6.87f;
        }
        
        int amount;
        printf("Enter product amount: ");
        scanf("%d", &amount );
        
        total += amount * price;
    }
    
    printf("Total sold: $%2.2f\n", total);
        
    return 0;
}