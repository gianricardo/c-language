#include <stdio.h>

int main () {
	
	int contador = 1;
	
	while (contador < 101) {
		printf("*");
		if ( contador % 10 == 0) {
			printf("\n");
		}
		contador++;
	}
	
	return 0;
}
