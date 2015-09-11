#include <stdio.h>

int main(void){

	int contador;
	int produto = 1;

	for (contador = 1; contador <= 15; contador++){

		if(contador % 2 == 1){
			produto *= contador;
		}
	}

	printf("Produto: %d\n", produto);

	return 0;
}