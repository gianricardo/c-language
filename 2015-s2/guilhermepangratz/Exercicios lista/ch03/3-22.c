#include <stdio.h>

int main () {
	
	int i = 10;
	
	printf("i = %d\n", i);
	
	printf("printf(\"i = i--);   i = %d\n", i--);
	
	printf("i = %d\n", i);
	
	printf("printf(\"i = --i);   i = %d\n", --i);
	
	printf("i = %d\n", i);
	
	return 0;
}
