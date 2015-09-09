#include <stdio.h>

int main(void){

	int conta = ;
	float saldo_inicial = 0;
	float saldo_final = 0;
	float total_encargos = 0;
	float total_credito = 0;
	float limite_credito = 0;

	while (conta != -1){

		printf("Informe o número da conta (-1 para terminar): ");
		scanf("%d", &conta);

		if (conta == -1){

			break;
		}

		printf("Informe o saldo inicial: ");
		scanf("%f", &saldo_inicial);

		printf("Informe o total de encargos: ");
		scanf("%f", &total_encargos);

		printf("Informe o total de créditos: ");
		scanf("%f", &total_credito);

		printf("Informe o limite de crédito: ");
		scanf("%f", &limite_credito);

		saldo_final = (saldo_inicial + total_encargos - total_credito);

		if (saldo_final > limite_credito){

			printf("\nConta: %d\n", conta);
			printf("Limite de crédito: %.2f\n", limite_credito);
			printf("Saldo: %.2f\n", saldo_final);
			printf("Limite de crédito ultrapassado.\n");		
		}
	}
	
	return 0;
}