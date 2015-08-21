//escreva um programa que calcule o quadrado e o cubo dos números de 0 a 10

#include <stdio.h>

int main(void)
{
	int i; //variavel auxiliar para o laço for
	printf("Numero		Quadrado	Cubo\n");
	for(i=0;i<=10;i++){
		printf("%d		%d		%d\n",i,i*i,i*i*i);
	}
}
