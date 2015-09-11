#include <stdio.h>

int main () {
	
	int lado, i, j;
	
	printf("Valor do lado: ");
	scanf("%d", &lado);
	
	while ( lado > 20 || lado < 1) {
		printf("Valor do lado (entre 1 e 20): ");
		scanf("%d", &lado);
	}
	
	printf("\n");
	
	for ( i = 0; i < lado; i++) {
		for ( j = 0; j < lado; j++) {
			if ( i == 0 || i == lado-1){
				printf("*");
			} else if ( j == 0 || j == lado-1) {
				printf("*");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
	
	return 0;
}
