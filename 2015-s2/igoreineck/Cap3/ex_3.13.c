#include <stdio.h>

int main (void){

	int x = 1
	int total = 0; 
	int y;

	while (x <= 10){
		
		y = x * x;
		
		printf("%d\n", y);
		
		total += y;
		++x;
	}

	printf("Total is %d\n", total);
	
	return 0;
}