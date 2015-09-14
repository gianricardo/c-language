#include <stdio.h>

int main()
{
    printf("terms\tpi\n\n");
    
    for(int terms = 1; terms <= 1000; terms++)
    {
        float pi = 0;
        
        for(int i = 1; i <= terms; i++)
        {
            pi += (i%2? 1 : -1) * (4.0 / (1 + 2*(i-1)));             
        }
        
        printf("%d\t%f\n", terms, pi);
        
    }
    
    return 0;
}