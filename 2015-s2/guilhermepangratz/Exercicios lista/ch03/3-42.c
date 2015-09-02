//calcular os dados de um circulo através do seu raio

#include <stdio.h>

int main () {
	
	float raio, pi = 3.14159;
	
	printf("Raio do circulo: ");
	
	scanf("%f", &raio);
	
	printf("Diametro: %f\nCircunferencia: %f\nArea: %f\n\n", raio*2, 2*pi*raio, pi*raio*raio);
	
}
