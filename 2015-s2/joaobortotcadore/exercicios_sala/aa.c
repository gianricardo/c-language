/* Fig. 8.13: fig08_13.c
   Using fgets and putchar */
#include <stdio.h>
#include<ctype.h>
   
int main( void )
{  

	int i;
	char sentence[ 80 ];
	printf ("escreva uma frase:\n");
	fgets (sentence, 80,stdin);

	char *curr = sentence; 
	while(*curr)
	{
		printf("%c", isalpha(*curr)? toupper(*curr) : *curr);
		curr++;

	}

	printf ("\n");
	return 0;
}
