#include <stdio.h>

int main()
{
    while(1)
    {
        int acc;
        float bb, ch, cr, cl;
        
        printf("\nEnter account number (-1 to end): ");
        scanf("%d", &acc);
        
        if(acc == -1)
            break;
        
        printf("Enter beginning balance: ");
        scanf("%f", &bb);
        
        printf("Enter total charges: ");
        scanf("%f", &ch);
        
        printf("Enter total credits: ");
        scanf("%f", &cr);
        
        printf("Enter credit limit: ");
        scanf("%f", &cl);
        
        float balance = bb + ch - cr;
        
        printf("Account: \t%d\n", acc);
        printf("Credit limit:\t%.2f\n", cl);
        printf("Balance: \t%.2f\n", balance);
        
        if(balance > cl)
            printf("Credit Limit exceeded.\n");
        
    }
    
    return 0;
}