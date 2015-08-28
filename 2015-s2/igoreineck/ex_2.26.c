#include <stdio.h>

int main (void){

	int num1, num2 = 0;

	printf ("Digite dois números inteiros: ");
	scanf ("%d%d", &num1, &num2);

	if (num2 % num1 == 0){
		printf ("O primeiro número é múltiplo do segundo\n");
	}

	else {
		printf ("O primeiro número não é múltiplo do segundo\n");
	}

	return 0;
}