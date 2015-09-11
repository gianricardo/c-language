#include <stdio.h>

int main(void){

	int lado;
	int contador = 0;

	printf("Digite o tamanho do lado do quadrado: ");
	scanf("%d", &lado);

	for (contador; contador < lado; contador++){
		printf("*");
	}

	return 0;
}
