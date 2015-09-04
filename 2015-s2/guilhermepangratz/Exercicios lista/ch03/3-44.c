//Ler 3 valores floats e determinar se els podem representar os lados de um triangulo

#include <stdio.h>

int main () {
	
	float a,b,c, dif1, dif2, dif3; //lados do triangulo
	
	printf("Entre os valores para os 3 lados: ");
	
	scanf("%f%f%f", &a, &b, &c);
	
	dif1 = b - c;
	dif2 = a - c;
	dif3 = a - b;
	
	if (dif1 < 0) {
		dif1 = -dif1;
	}		
	if (dif2 < 0) {
		dif2 = -dif2;
	}
	if (dif3 < 0) {
		dif3 = -dif3;
	}
	
	if (dif1 < a && a < b + c) {
		if (dif2 < b && b < a + c) {
			if (dif3 < c && c < b + a) {
				printf ("Os valores informados podem ser usados como lados de um tringulo\n\n");
			} else {
				printf("Os valores não servem para lados de um triangulo\n\n");
			}
		} else {
			printf("Os valores não servem para lados de um triangulo\n\n");
		}
	} else {
		printf("Os valores nao servem para lados de um triangulo\n\n");
	}
}
