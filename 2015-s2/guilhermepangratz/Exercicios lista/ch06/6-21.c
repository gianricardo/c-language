#include <stdio.h>

void recibo(int assento);

int main () {
	
	int assentos[10] = {0};
	
	int identificador, i;
		
	while (1) {
		
		printf("Favor digitar 1 para \"primeira classe\"\nFavor digitar 2 para \"classe economica\"\n");
		scanf("%d", &identificador);
		
		if (identificador == 1) {
			for ( i = 0; i < 10; i++) {
				if (assentos[i] == 0) {
					assentos[i] = 1;
					recibo(i);
					break;
				} else if (assentos[4] == 1 && i < 5) {
					printf("Deseja procurar local na classe economica? (1 para sim, 2 para não): ");
					scanf("%d", &identificador);
					if (identificador == 1) {
						i = 4;
					} else {
						recibo(-1);
						break;
					}
				}
			}
		} else if (identificador == 2) {
			for ( i = 9; i >= 0; i--) {
				if (assentos[i] == 0) {
					assentos[i] = 1;
					recibo(i);
					break;
				} else if (assentos[5] == 1 && i > 4) {
					printf("Deseja procurar local na primeira classe? (1 para sim, 2 para não): ");
					scanf("%d", &identificador);
					if (identificador == 1) {
						i = 5;
					} else {
						recibo(-1);
						break;
					}
				}
			}
		}
	}

	return 0;
}

void recibo(int assento) {
	if ( assento == -1 ) {
		printf("\nO proximo voo sai em 3 horas!\n\n");
	} else if (assento < 5) {
		printf("\n\nBILHETE DE EMBARQUE\nAssento: %d\nPrimeira classe\n\n", assento + 1 );
	} else {
		printf("\n\nBILHETE DE EMBARQUE\nAssento: %d\nClasse economica\n\n", assento + 1 );
	}
}
