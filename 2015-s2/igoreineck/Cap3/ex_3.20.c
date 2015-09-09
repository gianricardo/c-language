#include <stdio.h>

int main(void){

	float principal;
	float taxa;
	float juros;
	int dias;

	while (principal != -1){

		printf("Informe o valor principal do empréstimo (-1 para terminar): ");
		scanf("%f", &principal);

		if (principal == -1){

			break;
		}

		printf("Informe a taxa de juros: ");
		scanf("%f", &taxa);

		printf("Informe o prazo do empréstimo em dias: ");
		scanf("%d", &dias);

		juros = (principal * taxa * dias) / 365;

		printf("O valor dos juros é de %.2f\n\n", juros);
	}

	return 0;
}