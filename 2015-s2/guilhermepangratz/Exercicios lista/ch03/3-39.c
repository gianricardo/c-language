#include <stdio.h>

int main () {
	
	int i, j, numero, pot10, contador7 = 0;
	
	printf("Informe um numero: ");
	scanf("%d", &numero);
	
	int n[10] = {0};
	
	pot10 = 1000000000;
	
	for ( i = 10; i > 0; i--) {
		n[i-1] = (numero / pot10);
		
		numero %= pot10;
		pot10  /= 10;
		
		if (n[i-1] == 7) {
			contador7++;
		}
	}
	
	printf("\nQuantidade de 7: %d\n", contador7);
		
		
	return 0;
}
