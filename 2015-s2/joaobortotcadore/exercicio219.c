#include <stdio.h>

int main()
{
	int maior,menor,num1,num2,num3;
	float media;
	printf("Digite 3 números diferentes um do outro e separados por espaço. Exemplo: num1 num2 num3: ");
	scanf("%d %d %d",&num1,&num2,&num3); //capta os valores inseridos pelo usuario
	while(num1 == num2 || num2 == num3 || num1==num3) //caso o usuario nao siga a regra de digitar valores diferentes
	{
		printf("Digite 3 números diferentes: ");
		scanf("%d %d %d",&num1,&num2,&num3);
	}
	printf("A soma de num1+num2+num3=%d\n",num1+num2+num3); //apresenta soma
	media=(num1+num2+num3)/3;//calcula a media
	printf("A média=%f\n",media); //apresenta media
	printf("O produto de num1*num2*num3=%d\n",num1*num2*num3); //apresenta o produto
	//neste trecho faz todas as condições para encontrar qual dos tres é maior e menor
	if(num1>num2 && num1>num3)
	{
		maior=num1;  //para num1 ser maior ele deve ser maior que num2 e num3
		if(num3>num2) //para ver quem é´o menor dos outros dois, com um if else basta para solucionar o problema
			menor=num2;
		else
			menor=num3;
	}
	if(num2>num1 && num2>num3)//para num2 ser maior ele deve ser maior que num1 e num3
	{
		maior=num2;
		if(num3>num1)//para ver quem é´o menor dos outros dois, com um if else basta para solucionar o problema
			menor=num1;
		else
			menor=num3;
	}
	if(num3>num2 && num3>num1)//para num3 ser maior ele deve ser maior que num1 e num2
	{
		maior=num3;
		if(num2>num1)//para ver quem é´o menor dos outros dois, com um if else basta para solucionar o problema
			menor=num1;
		else
			menor=num2;
	}
	printf("O maior número=%d\n",maior); //apresenta o maior
	printf("O menor número=%d\n",menor); //apresenta o menor
	return 0;
}
