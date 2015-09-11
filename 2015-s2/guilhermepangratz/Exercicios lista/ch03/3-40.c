#include <stdio.h>

int main () {
	
	int i = 1, j;
	
	for (; i<=8; i++) {
		if ( i % 2 == 0) {
			printf(" ");
		} 
		for (j = 1; j<=8; j++) {
			printf("* ");
		}
		printf("\n");
	}
			
	return 0;
}
