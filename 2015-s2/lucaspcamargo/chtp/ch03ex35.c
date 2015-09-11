#include <stdio.h>

int main( void )
{
    int n = 0;
    printf("Enter a 5-digit number: ");
    scanf("%d", &n);

    if(n > 9999 && n < 100000)
    {
        if(((n/10000 % 10) == (n%10)) && ((n/1000 % 10) == (n/10 % 10)))
            printf("Number is a palindrome\n");            
        else
            printf("Number is not a palindrome\n");
        
    }
    else printf("Number invalid\n");
    
    return 0;
}