//Escreva um programa que leia um número inteiro e então determine e imprima se ele é par ou ímpar

#include <stdio.h>

int main(void)
{
	int num;
	printf("Digite um número para saber se é par ou ímpar:\n");
	scanf("%d",&num);
	printf("O número é %s",num%2==0 ? "par" : "impar");
}
