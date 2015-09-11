//Calcular o valor de e elevado a x

#include <stdio.h>

int main () {
	
	int x, i, j, limite = 18;
	
	long long int potencia = 1, fatorial = 1;
		
	double e = 1;
	
	printf("Expoente de e: ");
	scanf("%d", &x);
	
	for ( i = 1; i <= limite; i++) {	

		fatorial *= i;
		potencia *=x;
		
		printf("fatorial = %ld | potencia = %ld\n", fatorial, potencia);
		
		e += potencia*1.0/fatorial;
	}
	
	printf("\n e ^ %d = %f\n", x, e);
		
}
