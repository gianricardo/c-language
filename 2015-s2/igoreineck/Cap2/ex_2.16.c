#include <stdio.h>

int main(void){

	int num1 = 0;
	int num2 = 0;

	printf("Digite dois numeros inteiros: ");
	scanf("%d%d", &num1, &num2);

	printf("Lidos: %d e %d\n", num1, num2);
	printf("Soma = %d\n", num1 + num2);
	printf("Diferença = %d\n", num1 - num2);
	printf("Produto = %d\n", num1 * num2);
	printf("Quociente = %d\n", num1 / num2);
	printf("Módulo = %d\n", num1 % num2);

	return 0;
}