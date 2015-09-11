#include <stdio.h>

int main () {
	
	int i, j, binario, pot10, pot2, decimal = 0;
	
	printf("Informe um numero binario: ");
	scanf("%d", &binario);
	
	int n[10] = {0};
	
	pot10 = 1000000000;
	pot2 = 512;
	
	for ( i = 10; i > 0; i--) {
		n[i-1] = (binario / pot10) * pot2;
		
		binario %= pot10;
		pot10  /= 10;
		pot2 /= 2;
		
		decimal += n[i-1];
	}
	
	printf("\nEquivalente decimal: %d\n", decimal);
		
		
	return 0;
}
