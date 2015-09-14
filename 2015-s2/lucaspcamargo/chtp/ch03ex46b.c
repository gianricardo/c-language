#include <stdio.h>


int main( void )
{
    float acc = 1;
    
    for(int i = 1; i < 1000; i++)
    {
        int n = i;
        float fac = 1;
    
        while(n > 0)
        {
            fac *= n;
            n--;
        }
        
        acc += 1.0f / fac;
    
    }
    
    printf("Constant e is approximately: %f\n", acc);
    
    return 0;
}
