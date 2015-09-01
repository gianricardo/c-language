//Consumo de combustivel

#include<stdio.h>

int main(void)
{
	float distancia_km=0, litros_combustivel=0;
	float distancia_acumulada=0, litros_acumulados=0;
	while(1)
	{
		printf("Informe quantos litros de combustível foi abastecido:\n");
		scanf("%f",&litros_combustivel);
		if(litros_combustivel==-1)
			break;
		litros_acumulados+=litros_combustivel;
		printf("Informe quantos km foram rodados:\n");
		scanf("%f",&distancia_km);
		distancia_acumulada+=distancia_km;
		printf("O consumo atual é de %f km/l\n\n",distancia_km/litros_combustivel);
	}
	printf("O consumo geral foi de %f km/l.",distancia_acumulada/litros_acumulados);
}
