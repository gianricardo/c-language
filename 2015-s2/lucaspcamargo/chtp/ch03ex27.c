#include <stdio.h>
#include <limits.h>

int main()
{
    int i, buf, max = INT_MIN;
    int max2 = max;
    
    for(i = 0; i < 10; i++)
    {
        printf("Insert a number: ");
        scanf("%d", &buf);
        
        if(buf > max)
        {
            max2 = max;    
            max = buf;
        }
        else if(buf > max2)
        {
            max2 = buf;
        }
    }
    
    printf("The maximum number was %d\n", max);
    printf("The second-maximum number was %d\n", max2);
    
    return 0;
}