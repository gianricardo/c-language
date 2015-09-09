#include <stdio.h>

int main(void){

	int A = 3;
	int A1, A2, A3;
	int contador = 0;

	printf("A\t A+2\t A+4\t A+6\n\n");

	for (contador; contador < 5; contador++){

		A1 = A + 2;
		A2 = A + 4;
		A3 = A + 6;

		printf("%d\t %d\t %d\t %d\n", A, A1, A2, A3);

		A += 3;	
	}

	return 0;
}