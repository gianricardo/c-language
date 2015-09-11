#include <stdio.h>

int main(void){

	int contador;
	int produto = 1;

	for (contador = 1; contador <= 5; contador++){
		
		produto *= contador;
		printf("O fatorial de %d", contador);
		printf(" é %d\n", produto);
	}

	return 0;
}