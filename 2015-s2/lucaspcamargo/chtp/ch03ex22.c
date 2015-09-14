#include <stdio.h>

int main()
{
    int a = 4;
    int b = 4;

    printf("a is %d\n", a);
    printf("b is %d\n", b);
    
    printf("printing a-- : %d\n", a--);
    printf("printing --b : %d\n", --b);
    
    printf("a is %d\n", a);
    printf("b is %d\n", b);

    return 0;
}