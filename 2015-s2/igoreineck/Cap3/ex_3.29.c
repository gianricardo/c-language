#include <stdio.h>

int main(void){

	int contador = 1;

	while (contador <= 10){

		printf("%s\n", contador % 2 ? "****" : "++++++++");

		contador++;
	}

	return 0;
}