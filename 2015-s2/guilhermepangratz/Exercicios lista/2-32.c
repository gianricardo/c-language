//IMC

#include <stdio.h>

int main () {
	
	double peso, altura;
	
	printf("Entre com os dados para o calculo do IMC\nPeso (kg): ");
	scanf("%Lf", &peso);
	printf("Altura (m): ");
	scanf("%Lf", &altura);
	
	printf("IMC: %Lf\n\nVALORES DE IMC\nAbaixo do peso: menor que 18,5\nNormal:         entre 18,5 e 24,9\nAcima do peso:  entre 25 e 29,9\nObeso:          30 ou mais", peso/(altura*altura));
	
}
