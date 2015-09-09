#include <stdio.h>

int main(void){

	float horas;
	float salario_hora;
	float salario_total;

	while (horas != -1){

		printf("Digite # de horas trabalhadas (-1 para terminar): ");
		scanf("%f", &horas);

		if (horas == -1){

			break;
		}

		printf("Digite o salário por hora do funcionário (R$00,00): ");
		scanf("%f", &salario_hora);

		if (horas > 40){

			salario_hora *= 1.5;
		}

		salario_total = (horas * salario_hora);

		printf("Salário é de R$%.2f\n\n", salario_total);
	}

	return 0;
}