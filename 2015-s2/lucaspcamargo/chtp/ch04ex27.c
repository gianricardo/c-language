#include <stdio.h>

int main()
{
    printf("a\tb\tc\n\n");
    
    for(int a = 1; a <= 500; a++)
    {
        for(int b = 1; b <= a; b++)
        {
            for(int c = 1; c <= b; c++)
            {
                if((a*a) == (b*b + c*c))
                printf("%d\t%d\t%d\n", a, b, c);
            }
        }
    }
    
    return 0;
}