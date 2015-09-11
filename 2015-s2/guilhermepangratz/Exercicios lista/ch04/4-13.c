#include <stdio.h>

int main () {
	
	int i, prod = 1;
	
	for (i = 1; i <= 15; i+=2) {
		prod *= i;
	}
	
	printf("\nProduto dos inteiros impares de 1 a 15: %d\n", prod); 
	
	return 0;
}
