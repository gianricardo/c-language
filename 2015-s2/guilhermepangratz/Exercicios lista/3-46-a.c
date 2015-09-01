//calcular o fatorial de um inteiro positivo

#include <stdio.h>

int main () {
	
	int n = -1, acumulador = 1; 
	
	while ( n < 0 ) {
		printf("Calculo do Fatorial\nEntre um numero inteiro nao negativo: ");
		scanf("%i", &n);
	}
	
	if ( n == 0 ) {
		printf("0! = 1\n");
	} else { 
		int i;
		for (i = 2; i <= n; i++) {
			acumulador *= i;
		}
		printf("%i! = %i\n", n, acumulador);
	}		
	
}
