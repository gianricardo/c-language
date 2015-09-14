#include <stdio.h>

int main () {
	
	int n1, n, soma, i;
	
	printf("Entre com a seguencia de inteiros (sequencia do tamanho do primeiro inteiro): ");
	scanf("%d", &n1);
	
	soma = n1;
	
	for (i = 1; i < n1; i++) {
		scanf("%d", &n);
		soma += n;
	}
	
	printf("Soma: %d\n", soma);
	
	return 0;
}
