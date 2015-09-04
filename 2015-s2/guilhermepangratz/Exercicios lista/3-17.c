//faz a media do consumo de combustivel por seção e depois uma media de todas as seções

#include <stdio.h>

int main () {
	
	float litros = 0, km, tLitros = 0, tKm = 0;
	
	while ( litros != -1 ) {
		printf("Informe quantos litros abasteceu (-1 para terminar): ");
		scanf("%f", &litros);
		if (litros != -1){
			printf("Informe quantos km dirigiu: ");
			scanf("%f", &km);
			printf("O consumo atual e de %.6f km/l", km/litros);
			tLitros += litros;
			tKm += km;
		}
		printf("\n\n");
	}
	
	printf("O consumo geral foi de %.6f km/l", tKm/tLitros);
	
}
