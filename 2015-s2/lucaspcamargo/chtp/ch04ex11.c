#include <stdio.h>
#include <limits.h>

int main()
{
    int count = -1;
    int min = INT_MAX;
    int in;
    
    while(count)
    {
        scanf("%d", &in);
        
        if(count == -1)
            count = in;
        else
        {
            if(in < min)
                min = in; 
            
            count--;
        }
    }
    
    printf("minimum is %d\n", min);
    
    return 0;
}