#include <stdio.h>

int main () {
	
	long value1 = 200000, value2;
	
	long *lPtr = &value1; //a - b
	
	printf("\n*lPtr = %ld\n", *lPtr); //c
	
	value2 = *lPtr; //d
	
	printf("\nvalue2 = %ld\n", value2); //e
	
	printf("\n&value1 = %ld\n", &value1); //f
	
	printf("\nlPtr = %ld\n", lPtr); //g
	
	return 0;
}
