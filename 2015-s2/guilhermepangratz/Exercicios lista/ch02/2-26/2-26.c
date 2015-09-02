#include <stdio.h>

int main () {
	
	int x, y;
	
	printf("Insira dois inteiros: ");
	scanf("%d%d", &x, &y);
	
	if ( y % x == 0 ) {
		printf("%d e multiplo de %d", y, x);
		 return 0;
	}
	
	printf("%d nao e multiplo de %d", y, x);
	
	return 0;
}
