#include <stdio.h>

int main (void){

	int num1 = 0;
	int num2 = 0;

	printf ("Digite dois numeros inteiros: ");
	scanf ("%d%d", &num1, &num2);

	if (num1 > num2){
		printf("O número um é maior\n");
	}

	if (num1 < num2){
		printf("O número dois é maior\n");
	}

	if (num1 == num2){
		printf ("O número um é igual ao número dois\n");
	}

	return 0;
}