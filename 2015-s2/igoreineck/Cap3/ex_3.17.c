#include <stdio.h>

int main(void){

	float litros = 0;
	float quilometros = 0;
	float consumo = 0;

	while (litros != -1){
		
		printf("Informe quantos litros abasteceu (-1 para terminar): ");
		scanf("%f", &litros); 

		if (litros != -1){
			printf("Informe quantos km dirigiu: ");
			scanf("%f", &quilometros);

			consumo = (quilometros/litros);
			printf("O consumo atual é de %f km/l\n", consumo);
		}
		
		else{
			
			break;
		}
	}
	
	return 0;	
}