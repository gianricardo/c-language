#include <stdio.h>

int main(void){

	int numero;
	int contador;
	int maior;

	for (contador = 0; contador <= 10; contador++){

		printf("Digite um número: ");
		scanf("%d", &numero);

		if (numero > maior){
			maior = numero;
		}

		printf("O maior número até agora é: %d\n", maior);

	}

	return 0;
}