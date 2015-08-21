//Escreva um programa que leia dois inteiros e então determine e imprima se o primeiro é múltiplo do segundo 

#include <stdio.h>

int main(void)
{
	int num1,num2;
	printf("Digite um número (Num1):\n");
	scanf("%d",&num1);
	printf("Digite outro número (Num2):\n");
	scanf("%d",&num2);
	printf("%s",num2%num1==0 ? "Num1 é multiplo de Num2\n" : "Num1 não é multiplo de Num2\n");
}
