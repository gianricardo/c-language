#include <stdio.h>
#include <limits.h>

int main()
{
    int sum = 0;
    
    for(int i = 1; i <= 15; i++)
    {
        if(i % 2)
            sum += i;
    }
    
    printf("sum of odd ints from 1 to 15 is %d\n", sum);
    
    return 0;
}