#include <stdio.h>

int main (void){

	int num1, num2, num3, num4, num5 = 0;

	printf ("Digite cinco números inteiros: ");
	scanf ("%d%d%d%d%d", &num1, &num2, &num3, &num4, &num5);

	if (num1 < num2 && num1 < num3 && num1 < num4 && num1 < num5){
		printf ("O primeiro número é o menor \n");
	}

	if (num2 < num3 && num2 < num4 && num2 < num5 && num2 < num1){
		printf ("O segundo número é o menor \n");
	}

	if (num3 < num4 && num3 < num5 && num3 < num1 && num3 < num2){
		printf ("O terceiro número é o menor \n");
	}

	if (num4 < num5 && num4 < num1 && num4 < num2 && num4 < num3){
		printf ("O quarto número é o menor \n");
	}

	if (num5 < num1 && num5 < num2 && num5 < num3 && num5 < num4){
		printf ("O quinto número é o menor \n");
	}

	if (num1 > num2 && num1 > num3 && num1 > num4 && num1 > num5){
		printf ("O primeiro número é o maior \n");
	}

	if (num2 > num3 && num2 > num4 && num2 > num5 && num2 > num1){
		printf ("O segundo número é o maior \n");
	}

	if (num3 > num4 && num3 > num5 && num3 > num1 && num3 > num2){
		printf ("O terceiro número é o maior \n");
	}

	if (num4 > num5 && num4 > num1 && num4 > num2 && num4 > num3){
		printf ("O quarto número é o maior \n");
	}

	if (num5 > num1 && num5 > num2 && num5 > num3 && num5 > num4){
		printf ("O quinto número é o maior \n");
	}

	return 0;
}