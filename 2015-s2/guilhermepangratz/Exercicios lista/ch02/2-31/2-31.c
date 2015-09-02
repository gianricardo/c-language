//Imprimir os quadrados e os cubos dos números de 0 a 10 tabulados

#include <stdio.h>

int main () {
	
	int n0 = 0, n1 = 1, n2 = 2, n3 = 3, n4 = 4, n5 = 5, n6 = 6, n7 = 7, n8 = 8, n9 = 9, n10 = 10;
	
	printf("numero    quadrado  cubo\n%-10i%-10i%-10i", n0, n0, n0);
	printf("\n%-10i%-10i%-10i", n1, n1*n1, n1*n1*n1);
	printf("\n%-10i%-10i%-10i", n2, n2*n2, n2*n2*n2);
	printf("\n%-10i%-10i%-10i", n3, n3*n3, n3*n3*n3);
	printf("\n%-10i%-10i%-10i", n4, n4*n4, n4*n4*n4);
	printf("\n%-10i%-10i%-10i", n5, n5*n5, n5*n5*n5);
	printf("\n%-10i%-10i%-10i", n6, n6*n6, n6*n6*n6);
	printf("\n%-10i%-10i%-10i", n7, n7*n7, n7*n7*n7);
	printf("\n%-10i%-10i%-10i", n8, n8*n8, n8*n8*n8);
	printf("\n%-10i%-10i%-10i", n9, n9*n9, n9*n9*n9);
	printf("\n%-10i%-10i%-10i\n", n10, n10*n10, n10*n10*n10);
	
}
