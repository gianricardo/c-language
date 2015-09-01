//Calcular o valor de e elevado a x

#include <stdio.h>

int main () {
	
	float e = 1;
	int expoente;
	
	printf("\nValor do expoente: ");
	scanf("%i", &expoente);
	
	for (int i = 1; i < 31; i++) {
		
		float fatorial = 1;
		float xelevado = expoente;
	
		for (int j = 1; j <= i; j++) {
			fatorial *= j;
			xelevado *= expoente;
		}
		printf("%f/%10.10f\n", xelevado, expoente);
		
		e += (xelevado/fatorial);
		
	}
	
	printf("e = %f", e);
	

}
