#include <stdio.h>

int main(void){

	float venda;
	float comissao = 200.00;
	float acrescimo;
	float pagamento;

	while (venda != -1){

		printf("Informe a venda em reais: ");
		scanf("%f", &venda);

		if (venda == -1){

			break;
		}

		printf("\nVenda: %.2f\n", venda);

		acrescimo = (venda * 0.09);

		pagamento = (comissao + acrescimo);

		printf("O pagamento é de: %.2f\n\n", pagamento);
	}

	return 0;

}