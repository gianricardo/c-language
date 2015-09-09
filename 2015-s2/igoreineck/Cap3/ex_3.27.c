#include <stdio.h>

int main(void){

	int numero;
	int contador;
	int maior1;
	int maior2;

	for (contador = 0; contador <=10; contador++){

		printf("Digite um valor: ");
		scanf("%d", &numero);

		if (numero >= maior1){
			maior1 = numero;
		}

		if (numero < maior1 && numero > maior2){
			maior2 = numero;
		}

		if (numero >= maior2 && numero < maior1){
			maior2 = numero;
		}

		printf("O maior número é: %d\n", maior1);
		printf("O segundo maior número é: %d\n", maior2);

		if (numero < maior1 && numero >= maior2){
			maior2 = numero;
		}
	}

	return 0; 
}