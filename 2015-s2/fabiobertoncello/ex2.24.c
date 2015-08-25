#include<stdio.h>
int main(void){
	int valor1=0;
	printf("informe um valor para saber se é par(P) ou impar(I)\n");
	scanf("%d",&valor1);
	printf("%c \n",((valor1%2)==0)? 'P':'I');
	
	
return 0;
}
