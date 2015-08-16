/*2.16 Escreva um programa que peça ao usuário para digitar dois números, obtenha-os do usuário e imprima a soma, o produto, a diferença, o quociente e o resto da divisão dos dois números.*/
#include <stdio.h>

int main()
{
	int num1,num2;
	printf("Digite dois números separados por vírgula, exemplo: num1,num2\nLembre-se que não pode ocorrer divisão por zero\n");
	scanf("%d,%d",&num1,&num2); //capta os valores inseridos pelo usuario
	while(num1==0 && num2==0) //verifica se os dois numeros são zero, caso verdadeiro pede que o usuario informe novamente num1,num2 separadamente
	{
		printf("Digite num1\n");
		scanf("%d",&num1);
		printf("Digite num2\n");
		scanf("%d",&num2);
	}

	printf("A soma de num1+num2=%d\n",num1+num2); //apresenta soma
	printf("A diferença de num1-num2=%d\n",num1-num2); //apresenta primeiro caso da subtraçao
	printf("A diferença de num2-num1=%d\n",num2-num1); //apresemta segundo caso da subtraçao
	printf("O produto de num1*num2=%d\n",num1*num2); //apresenta o produto
	
	if(num2==0 && num1!=0) //no caso da divisão, como é indeterminação divisão por zero, mesmo que o usuário informe o programa é capaz de trocar numerador por denominador, caso contrario executa o caso corretamente que é num1/num2
	{
		printf("O quociente de num2/num1=%d\n",num2/num1);
		printf("O resto de num2/num1=%d\n",num2%num1);
	}else{
		printf("O quociente de num1/num2=%d\n",num1/num2);
		printf("O resto de num1/num2=%d\n",num1%num2);
	}
	return 0;
}
