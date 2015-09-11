#include <stdio.h>

int main()
{
    int a, b, c, d, e;
    printf("\nEnter five numbers: ");
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < ((int[]){a, b, c, d, e})[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    
    return 0;
}