#include <stdio.h>

int main () {
	
	int n5 = 100000, n0, n1, n2, n3, n4;
	
	while ( n5 < -99999 || n5 > 99999 || ( n5 > -10000 && n5 < 10000) ) {
		printf("Informe um inteiro de 5 digitos: ");
		scanf("%d", &n5);
	}
	
	n0 = n5 / 10000;
	n5 %= 10000;
	
	n1 = n5 / 1000;
	n5 %= 1000;

	n2 = n5 / 100;
	n5 %= 100;

	n3 = n5 / 10;
	n5 %= 10;

	n4 = n5;

	if ( n0 == n4 && n1 == n3 ) {
		printf("Palindromo!\n");
	} else {
		printf("Nao palindromo!\n");
	}
	
	return 0;
}
