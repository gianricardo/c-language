#include <stdio.h>

int main (void){

	int num1, num2, num3 = 0;
	int soma, media, produto = 0;

	printf ("Digite três números inteiros diferentes: ");
	scanf ("%d%d%d", &num1, &num2, &num3);

	soma = num1 + num2 + num3;
	printf ("A soma é %d\n", soma);

	media = soma/3;
	printf ("A média é %d\n", media);

	produto = num1 * num2 * num3;
	printf ("O produto é %d\n", produto);

	if (num1 < num2 && num1 < num3){
		printf ("O menor é %d\n", num1);
		printf ("O maior é %d\n", num3);
	}

	if (num2 < num3 && num2 < num1){
		printf ("O menor é %d\n", num2);
	}

	if (num3 < num2 && num3 < num1){
		printf ("O menor é %d\n", num3);
	}

	if (num1 > num2 && num1 > num3){
		printf ("O menor é %d\n", num3);
		printf ("O maior é %d\n", num1);
	}

	if (num2 > num3 && num2 > num1){
		printf ("O maior é %d\n", num2);
	} 

	if (num3 > num2 && num3 > num1){
		printf ("O maior é %d\n", num3);
	}

	return 0;
}