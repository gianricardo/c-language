#include <stdio.h>

int main()
{
    int count = 0;
    int accum = 0;
    int in = 0;
    
    printf("insert sequence of numbers (sentinel is 9999): ");
    
    while(1)
    {
        scanf("%d", &in);
        
        if(in != 9999)
            accum += in;
        else
            break;
        
        count ++;
        
    }
    
    printf("average is %.2f\n", ((float)accum) / count);
    
    return 0;
}