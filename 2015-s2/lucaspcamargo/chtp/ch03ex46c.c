#include <stdio.h>


int main( void )
{
    float acc = 1;
    int power;
    
    printf("Enter power of e: ");
    scanf("%d", &power);
    
    for(int i = 1; i < 1000; i++)
    {
        int n = i;
        float fac = 1;
        
        while(n > 0)
        {
            fac *= n;
            n--;
        }
        
        float powerToI = 1;
        
        n = 1;
        while(n > 0)
        {
            powerToI *= power;
            n--;
        }
        
        acc += powerToI / fac;
    
    }
    
    printf("e^%d is approximately: %f\n", power, acc);
    
    return 0;
}
