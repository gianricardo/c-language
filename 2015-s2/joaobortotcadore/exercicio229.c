/*Escreva um programa em C que imprima os inteiros equivalentes a algumas letras maiúsculas, letras minúsculas e símbolos especiais.*/

#include <stdio.h>

int main(void)
{
	int i;
	printf("TABELA DE CARACTERES\n");
	for(i=33;i<=126;i++) //imrime tabela de alguns caracteres ASCII
	{
		printf("%d=%c\n",i,i);
	}
}


