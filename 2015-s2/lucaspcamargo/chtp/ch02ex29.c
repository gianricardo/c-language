/**
 * c02ex29.c - ASCII codes
 * © Lucas Pires Camargo
 * 
 * See LICENSE file at the root of this repository.
 */

#include <stdio.h>

int main(void)
{
    
    // Since this is a "look-ahead" exercise, I am using string manipulation with pointers :)
    // Hope you don't mind
    const char * str = "ABCabc012$*+/";

    for(;;) // forever
    {
        // current char in not null
        if(*str)
        {
            // print the char, its code, and advance ahead one position
            printf("%c %d\n", *str, *str);
            str++;
        }
        else
        {
            // the string is over, show NUL character and break loop
            printf("NUL %d\n", *str);
            break;
        }
    }

    return 0;
}
