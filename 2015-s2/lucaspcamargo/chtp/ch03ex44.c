#include <stdio.h>


int main( void )
{
    float r, s, t;
    int valid = 0;
    
    printf("Enter side r: ");
    scanf("%f", &r);
    printf("Enter side s: ");
    scanf("%f", &s);
    printf("Enter side t: ");
    scanf("%f", &t);
    
    if( r >= s && r >= t)
        if(r < (s + t))
            valid = 1;
        
    if( s >= t && s >= r)
        if(s < (r + t))
            valid = 1;
        
    if( t >= s && t >= r)
        if(t < (r + s))
            valid = 1;
        
    if(valid)
        printf("Valid triangle\n");
    else
        printf("Invalid triangle\n");
    
    return 0;
}
