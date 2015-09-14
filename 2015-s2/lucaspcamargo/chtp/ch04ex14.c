#include <stdio.h>

/* calculating 20! might be problematic because the result 
 * does not fit an int. it overflows
 */

int main( void )
{
    
    printf("n\tn!\n");
    
    for(int i = 1; i <= 5; i++)
    {
        int n = i;
        int fac = 1;
        
        while(n > 0)
        {
            fac *= n;
            n--;
        }
        
        printf("%d\t%d\n", i, fac);
    
    }
    
    return 0;
}
