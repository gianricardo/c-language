/**
 * c02ex23.c - The decision tree of eternal suffering
 * © Lucas Pires Camargo
 * 
 * See LICENSE file at the root of this repository.
 */

#include <stdio.h>

#define SM(x) printf(sm, (x))
#define LG(x) printf(lg, (x))

int main(void)
{
    int n1, n2, n3, n4, n5;
    
    printf("Input five different integers: ");
    scanf("%d%d%d%d%d", &n1, &n2, &n3, &n4, &n5);
    
    const char * sm = "Smallest is %d\n";
    const char * lg = "Largest is %d\n";

    // Find smallest by brute-force
    // A more structured approach using only if's would be a pain to write
    
    if((n1 <= n2) && (n1 <= n3) && (n1 <= n4) && (n1 <= n5))
        SM(n1);
    else if((n2 <= n1) && (n2 <= n3) && (n2 <= n4) && (n2 <= n5))
        SM(n2);
    else if((n3 <= n1) && (n3 <= n2) && (n3 <= n4) && (n3 <= n5))
        SM(n3);
    else if((n4 <= n1) && (n4 <= n2) && (n4 <= n3) && (n4 <= n5))
        SM(n4);
    else if((n5 <= n1) && (n5 <= n2) && (n5 <= n3) && (n5 <= n4))
        SM(n5);
    
    // Find the largest in pretty much the same way
    
    if((n1 >= n2) && (n1 >= n3) && (n1 >= n4) && (n1 >= n5))
        LG(n1);
    else if((n2 >= n1) && (n2 >= n3) && (n2 >= n4) && (n2 >= n5))
        LG(n2);
    else if((n3 >= n1) && (n3 >= n2) && (n3 >= n4) && (n3 >= n5))
        LG(n3);
    else if((n4 >= n1) && (n4 >= n2) && (n4 >= n3) && (n4 >= n5))
        LG(n4);
    else if((n5 >= n1) && (n5 >= n2) && (n5 >= n3) && (n5 >= n4))
        LG(n5);
    
    
    return 0;
}
