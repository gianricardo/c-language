#include <stdio.h>

int main()
{
    for(int i = 0; i < 3; i++)
    {
        int acc;
        float bb, cl;
        
        printf("\nEnter account number: ");
        scanf("%d", &acc);
        
        if(acc == -1)
            break;
        
        printf("Enter current balance: ");
        scanf("%f", &bb);
        
        printf("Enter credit limit before recession: ");
        scanf("%f", &cl);
        
        float ncl = cl / 2;
        
        printf("Account: \t%d\n", acc);
        printf("New credit limit:\t%.2f\n", ncl);
        printf("Balance: \t%.2f\n", bb);
        
        if(bb > ncl)
            printf("New credit Limit exceeded.");
        
    }
    
    return 0;
}