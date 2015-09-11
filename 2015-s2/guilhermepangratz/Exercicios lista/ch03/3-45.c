#include <stdio.h>

int main () {
	
	int h, c1, c2, armazem;
	
	printf("Entre com o valor dos lados: ");
	scanf("%d%d%d", &h, &c1, &c2);
	
	if (c1 > h) {
		armazem = h;
		h = c1;
		c1 = armazem;
	}
	if (c2 > h) {
		armazem = h;
		h = c2;
		c2 = armazem;
	}
	
	if ( (c1 * c1 + c2 * c2) == (h * h)) {
		printf("\nPodem representar um triangulo retangulo!\n");
	} else {
		printf("\nNao podem representar um triangulo retangulo!\n");
	}
	
	return 0;
}
