#include <stdio.h>

int main ( ) {
	
	char c;
	
	printf("entre um caractere (ctrl + c para finalizar): \n");
	scanf("%1c", &c);
		
	printf("char: %c => int: %d\n\n", c, c); 
		
	return 0;
}
