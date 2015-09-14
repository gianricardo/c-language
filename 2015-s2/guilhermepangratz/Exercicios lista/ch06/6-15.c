#include <stdio.h>

int main () {
	
	float numeros[20] = {0};
	
	int i = 0, j, lacre;
	
	for (; i < 20; i++) {
		lacre =1;
		scanf("%f", &numeros[i]);
		for ( j = 0; j < i; j++ ) {
			if ( numeros[i] == numeros[j] ) {
				lacre =0;
			}
		}
		if (lacre) {
			printf("%d# valor: %.2f\n", i + 1, numeros[i]);
		}
	}
	
	return 0;
}
