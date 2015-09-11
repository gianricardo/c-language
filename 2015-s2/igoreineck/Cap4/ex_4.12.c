#include <stdio.h>

int main(void){

	int soma;
	int contador;

	for (contador = 2; contador <= 30; contador ++){

		if (contador % 2 == 0){
			soma += contador;
		}
	}

	printf("Soma: %d\n", soma);

	return 0;
}