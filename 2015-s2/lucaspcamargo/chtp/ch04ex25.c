#include <stdio.h>

int main()
{
    printf("dec\tbin\t\toct\thex\n\n");
    
    for(int i = 1; i <= 256; i++)
    {
        printf("%d\t", i);
        
        for(int j = 8; j >= 0; j--)
        {
            printf("%c", (i & (1 << j))? '1' : '0');
        }
        printf("\t");
        
        for(int j = 2; j >= 0; j--)
        {
            int mask = 7 << (j*3);
            int digit = (i & mask) >> (j*3);
            printf("%01d", digit);
        }
        printf("\t");
        
        printf("0x%02x\n", i);
    }
    
    return 0;
}