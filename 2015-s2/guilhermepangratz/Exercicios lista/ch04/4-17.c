#include <stdio.h>

int main () {
	
	int i, conta, limite, saldo;
	
	for ( i = 0; i < 3; i++) {
		printf("\nNumero da conta: ");
		scanf("%d", &conta);
		
		printf("Limite de credito: ");
		scanf("%d", &limite);
		
		printf("Saldo atual: ");
		scanf("%d", &saldo);
		
		printf("\nNovo limite: %f\n", limite/2.0);
		if (limite/2.0 < saldo) {
			printf("Saldo atual maior que o novo limite de credito\n");
		}
	}
	
	
	return 0;
}
