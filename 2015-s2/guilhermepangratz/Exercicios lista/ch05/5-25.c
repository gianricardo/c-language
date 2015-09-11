#include <stdio.h>

float menor (float n1, float n2, float n3);

int main () {
	
	float n1, n2, n3;
	printf("entre com 3 numeros: ");
	scanf("%f%f%f", &n1, &n2, &n3);
	
	n1 = menor(n1, n2, n3);
	
	printf("O menor numero recebido foi o: %f\n", n1);

	return 0;
}

float menor (float n1, float n2, float n3) {
	
	if ( n1 <= n2 & n1 <= n3) {
		return n1;
	} else if (n2 <= n3) {
		return n2;
	} else {
		return n3;
	}
}
