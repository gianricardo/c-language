#include <stdio.h>

int main () {
	
	double pi = 0;
	int i, contador = 1, sinal = 1, termos;
	
	printf("Quantidade de termos: ");
	scanf("%d", &termos);
	
	printf("%-4c%10s\n", 'n', "pi");
	
	for ( i = 1; i < (termos * 2) ; i += 2) {
		
		pi += sinal * (4.0/i);
		
		sinal *= -1;
		
		printf("%-4d%10lf\n", contador++, pi);
	}

	return 0;
}

// 3.14 em 119

// 3.141 em +- 2000 termos

//
