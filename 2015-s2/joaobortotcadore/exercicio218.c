#include <stdio.h>

int main()
{
	int num1,num2;
	//trecho que recebe a entrada dos numeros
	printf("Digite um número: \n");
	scanf("%d",&num1);
	printf("Digite outro número: \n");
	scanf("%d",&num2);
	//trecho que faz o teste de qual é o maior
	if(num1 > num2)
		printf("%d é maior que %d.\n",num1, num2);
	if(num1 == num2) // imprime que os numeros sao iguais
		printf("Os números são iguais.\n");
	else
		printf("%d é maior que %d.\n",num2, num1);
	return 0;
}
