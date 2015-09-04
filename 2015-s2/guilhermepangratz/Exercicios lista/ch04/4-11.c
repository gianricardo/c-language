#include <stdio.h>

int main () {
	
	int n, quantia, menor, i =1;
	
	printf("Entre o %dth inteiro: ", i);
	scanf("%d", &n);
	
	quantia = n;
	menor = n;
	
	for (i=2 ; i <= quantia; i++) {
		
		
		printf("Entre o %dth inteiro: ", i);
		scanf("%d", &n);
		
		if ( n < menor ) {
			menor = n;
		}
		
	}
	
	printf("O menor numero recebido: %d", menor);
	
	return 0;
}
