#include <stdio.h>

int inverte_digitos(int n); //inverte os digitos do inteiro recebido

int main () {
	
	int numero;
	
	printf("Digite um inteiro: ");
	scanf("%d", &numero);
	
	printf("\nInvertido: %d\n", inverte_digitos(numero));

	return 0;
}

int inverte_digitos(int n) {
	
	int i, lacre = 0, invertido = 0, multiplicador = 1, pot10 = 1000000000;
	
	for (i = 9; i >= 0; i--) {
		
		invertido += multiplicador * (n / pot10);
		lacre += (n / pot10);
		if (lacre) {
			multiplicador *= 10;
		}			
		
		n %= pot10;
		pot10 /= 10;
		
	}
	
	
	
	return invertido;
}
