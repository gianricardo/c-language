/**
 * c02ex19.c - Arithmetic and comparing integers
 * © Lucas Pires Camargo
 * 
 * See LICENSE file at the root of this repository.
 */

#include <stdio.h>

int main(void)
{
    int n1, n2, n3;
    
    printf("Input three different integers: ");
    scanf("%d%d%d", &n1, &n2, &n3);
    
    printf("Sum is %d\n", n1 + n2 + n3);
    printf("Average is %.2f\n", (((float)n1) + ((float)n2) + ((float)n3))/3.0 );
    printf("Product is %d\n", n1 * n2 * n3);

    const char * formatSmallest = "Smallest is %d\n";
    const char * formatLargest = "Largest is %d\n";
    
    if(n1 < n2)
    {
        if(n1 < n3)
        {
            printf(formatSmallest, n1);
        }
        else printf(formatSmallest, n3);
    }
    else
    {
        if(n2 < n3)
        {
            printf(formatSmallest, n2);
        }
        else printf(formatSmallest, n3);
    }
    
    if(n1 > n2)
    {
        if(n1 > n3)
        {
            printf(formatLargest, n1);
        }
        else printf(formatLargest, n3);
    }
    else
    {
        if(n2 > n3)
        {
            printf(formatLargest, n2);
        }
        else printf(formatLargest, n3);
    }
    
    
    return 0;
}
