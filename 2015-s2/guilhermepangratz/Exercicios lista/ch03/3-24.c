#include <stdio.h>

int main () {
	
	int i, atual, maior = 0;
	
	for (i=0; i<10; i++) {
		
		printf("Total de itens vendido: ")/
		scanf("%d", &atual);
		
		if (atual > maior) {
			maior = atual;
		}
		
	}
	
	printf("Maior quantidade de vendas: %d\n\n", maior);
	
	return 0;
}
