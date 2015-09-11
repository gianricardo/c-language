#include <stdio.h>

int main(void){

	int valor;
	int quantidade;
	int contador;
	int menor;

	printf("Digite a quantidade de números: ");
	scanf("%d", &quantidade);

	for (contador = 0; contador < quantidade; contador++){
		printf("Digite um valor: ");
		scanf("%d", &valor);

		if (valor < menor){
			menor = valor;
		}

	}

	printf("Menor valor: %d\n", menor);

	return 0;
}