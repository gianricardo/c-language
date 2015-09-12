#include <stdio.h>

float calculateCharges(float hours);

int main(void){

	printf("Car      Hours       Charge\n");
	printf("1	   1.5		%.2f\n",calculateCharges(1.5)); //calcula a taxa para 1.5hrs
	printf("1	   4.0		%.2f\n",calculateCharges(4.0)); //calcula a taxa para 4.0hrs
	printf("1	  24.0		%.2f\n",calculateCharges(24.0)); ////calcula a taxa para 24hrs
	printf("TOTAL	  29.5		%.2f\n",calculateCharges(1.5)+calculateCharges(4.0)+calculateCharges(24.0)); //calcula o total
	return 0;
}

float calculateCharges(float hours)
{
	if(hours < 3) //até 3 horas cobra 2 dolares
	{
		return 2.00;
	}
	if(hours > 3 && hours < 24) //até 24 horas, acrescenta 50 cents na taxa por mais 3 horas
	{
		return (2.00 + (int)(hours/3)*0.50); //é necessario fazer o cast para inteiro nesse caso, pois divisao de float resulta em possiveis valores decimais
	}
	if(hours >= 24) //se passar de 24 horas é cobrado 10 dolares
	{
		return 10.00;
	}
}
