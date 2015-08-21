#include <stdio.h>

int main()
{
	float pi=3.14159;
	int raio;
	printf("Digite o raio da circunferência:\n");
	scanf("%d",&raio); //capta o valor do raio informado pelo usuario
	while(raio < 0) //nao existe raio menor que zero
	{
		printf("Raio deve ser maior que zero.\nDigite o raio da circunferência:\n");
		scanf("%d",&raio);
	}

	printf("Diâmetro=%d\n",2*raio); //apresenta diametro
	printf("Circunferência=%f\n",2*pi*raio); //apresenta a cricunferencia, especificador deve ser float pelo fato do pi resultar a operaçãõ em um número float
	printf("Área do círculo=%f\n",pi*raio*raio); //apresemta area do circulo, especificador deve ser float pelo fato do pi resultar a operaçãõ em um número float
	return 0;
}
