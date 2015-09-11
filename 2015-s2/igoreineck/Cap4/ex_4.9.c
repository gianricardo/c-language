#include <stdio.h>

int main(void){

	int quantidade;
	int contador;
	int valor;
	int total;

	printf("Digite a quantidade de números a serem somados: ");
	scanf("%d", &quantidade);
	
	for(contador = 0; contador < quantidade; contador++){
		printf("Digite o valor a ser somado: ");
		scanf("%d", &valor);

		total += valor;
	}

	printf("Soma: %d\n", total);

	return 0;
}