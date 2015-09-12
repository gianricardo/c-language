#include<stdio.h>

int main(void){
	int numero,i,j;
	for(j=0;j<5;j++){
		printf("Digite um número entre um e trinta.\n");
		while(numero < 1 || numero >30)
		{
			scanf("%d",&numero);
		}
		for(i=0;i<numero;i++)
			printf("*");
		numero=0;
		printf("\n");
	}
}

