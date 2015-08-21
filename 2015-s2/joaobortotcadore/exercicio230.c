//Escreva um programa que receba a entrada de um número de cinco dígitos, separe o número em seus dígitos componentes e os imprima separados uns dos outros por três espaços.

#include <stdio.h>

int main(void)
{
	int num;
	int dig1, dig2, dig3, dig4, dig5;
	printf("Digite um número de 5 digitos:\n");	
	scanf("%d", &num);
	dig1=num/10000;
	dig2=num/1000-dig1*10;
	dig3=num/100-dig1*100-dig2*10;
	dig4=num/10-dig1*1000-dig2*100-dig3*10;
	dig5=num/1-dig1*10000-dig2*1000-dig3*100-dig4*10;
	printf("%d   %d   %d   %d   %d\n",dig1,dig2,dig3,dig4,dig5);
}
