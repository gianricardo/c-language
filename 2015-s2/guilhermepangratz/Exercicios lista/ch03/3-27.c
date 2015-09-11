#include <stdio.h>

int main () {
	
	float i, atual, maior, maior2;
	
	printf("Numero: ")/
	scanf("%f", &atual);
	
	maior = atual;
	
	printf("Numero: ")/
	scanf("%f", &atual);
	
	if (atual > maior){
		maior2 = maior;
		maior = atual;
	} else {
		maior2 = atual;
	}
	
	for (i=2; i<10; i++) {
		
		printf("Numero: ")/
		scanf("%f", &atual);
		
		if (atual > maior) {
			maior2 = maior;
			maior = atual;
		} else if (atual > maior2) {
			maior2 = atual;
		}
		
	}
	
	printf("Maiores numeros: %f ; %f\n\n", maior, maior2);
	
	return 0;
}
