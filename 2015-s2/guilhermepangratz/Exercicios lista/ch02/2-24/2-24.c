#include <stdio.h>

int main () {
	
	int n;
	printf("insira um inteiro: ");
	scanf("%d", &n);
	
	if ( n % 2 == 0) {
		printf("Par\n");
		return 0;
	}
	
	printf("Impar\n");
	
	return 0;
}
