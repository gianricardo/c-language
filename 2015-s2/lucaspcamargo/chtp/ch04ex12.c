#include <stdio.h>
#include <limits.h>

int main()
{
    int sum = 0;
    
    for(int i = 2; i <= 30; i++)
    {
        if(!(i % 2))
            sum += i;
    }
    
    printf("sum of even ints from 2 to 30 is %d\n", sum);
    
    return 0;
}