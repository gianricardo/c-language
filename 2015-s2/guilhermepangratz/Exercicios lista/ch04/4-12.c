#include <stdio.h>

int main () {
	
	int i, soma = 0;
	
	for ( i = 2; i < 31; i+=2) {
		soma += i;
	}
	
	printf("Soma dos pares de 2 a 30: %d\n", soma);
	
	return 0;
}
