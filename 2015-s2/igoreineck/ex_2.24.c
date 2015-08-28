#include <stdio.h>

int main (void){

	int num = 0;

	printf ("Digite um número inteiro: ");
	scanf ("%d", &num);

	if (num % 2 == 0){
		printf ("O número é par\n");
	}
	
	else { 
		printf ("O número é impar\n");
	}

	return 0;
}