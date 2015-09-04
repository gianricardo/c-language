#include <stdio.h>

int main (void){

	float raio, diametro, comprimento = 0;
	float PI = 3.14159265;

	printf ("Digite o raio da circunferencia: ");
	scanf ("%f", &raio);

	diametro = raio * 2;
	comprimento = 2 * PI * raio;

	printf ("O diâmetro é da circunferencia é %f\n", diametro);
	printf ("O comprimento da circunferencia é %f\n", comprimento);

	return 0;
}