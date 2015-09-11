#include <stdio.h>
#include <limits.h>

int main()
{
    int i, buf, max = INT_MIN;
    
    for(i = 0; i < 10; i++)
    {
        printf("Insert a number: ");
        scanf("%d", &buf);
        
        if(buf > max)
            max = buf;
    }
    
    printf("The maximum number was %d\n", max);
    
    return 0;
}