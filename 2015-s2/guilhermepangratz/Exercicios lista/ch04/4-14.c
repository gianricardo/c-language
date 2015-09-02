#include <stdio.h>

int main () {
	
	int f, i, j;
	
	printf("%-3c%4i%4i%4i%4i%4i\nn! ", 'n', 1, 2, 3, 4, 5);
	
	for (i=1; i<=5; i++) {
		f =1;
		for (j=1; j<=i; j++) {
			f *= j;
		}
		printf("%4i", f);
	}
	
}
