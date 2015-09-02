#include <stdio.h>

int main () {
	
	int a, b, c;
	
	printf("Entre 3 numeros inteiros diferentes:");
	scanf("%i%i%i", &a, &b, &c);
	
	int sum, av, prod, smal, larg;
	
	sum = a + b + c;
	av = sum /3;
	prod = a * b * c;
	
	smal = a;
	if ( b < a && b < c) {
		smal = b;
	}
	if ( c < a && c < b) {
		smal = c;
	}
	
	larg = a;
	if ( b > a && b > c) {
		larg = b;
	}
	if ( c > a && c > b) {
		larg = c;
	}
	
	printf("soma = %d\n"
			"media = %d\n"
			"produto = %d\n"
			"menor = %d\n"
			"maior = %d\n", sum, av, prod, smal, larg);
	
	return 0;
}
