#include <stdio.h>

int main(void)
{
	int valor1=0,valor2=0;
	printf("Informe os dois valores inteiros : ");
	scanf("%d %d",&valor1,&valor2);
	if (valor1>valor2){
		printf("%d é Maior  : \n",valor1);
	}
	else{
		if(valor2>valor1){
			printf("%d é Maior \n",valor2);
		}
		else{
			printf("esses numeros sao iguais : \n");
		}
	}
return 0;
}
