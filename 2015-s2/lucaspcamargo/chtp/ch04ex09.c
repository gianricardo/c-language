#include <stdio.h>

int main()
{
    int count = -1;
    int accum = 0;
    int in;
    
    while(count)
    {
        scanf("%d", &in);
        
        if(count == -1)
            count = in;
        else
        {
            accum += in;
            count--; 
        }
    }
    
    printf("%d\n", accum);
    
    return 0;
}