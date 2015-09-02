//Calcular o valor de e

#include <stdio.h>

int main () {
	
	int iteracoes = 34;
	
	/*while (iteracoes < 1) {
		printf("Determine a quantidade de iteracoes da serie (minimo 1): ");
		scanf("%i", &iteracoes);
	}*/ //Esse pedaço do codigo serve para o caso de o usuario desejar determianr o numero de iterações
	
	double e = 1.0;
	
	if (iteracoes == 1) {
		printf("e = %.10lf\n", e);
	} else {
		int i;
		for (i = 1; i < iteracoes; i++) {
			long int fatorial = 1, j;
			
			for ( j = 2; j <= i; j++) {
				fatorial *= j;
			}
			
			e += (1.0f/fatorial);
			 
		}
		printf("e = %lf\n", e);
	}
	
}
