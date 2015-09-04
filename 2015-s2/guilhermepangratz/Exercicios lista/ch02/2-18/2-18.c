#include <stdio.h>

int main () {
	
	int num1, num2;
	
	printf("Entre dois inteiros: ");
	scanf("%i%i", &num1, &num2);
	
	if (num1 > num2){
		printf("O maior e o: %i", num1);
	} else if (num2 > num1) {
		printf("O maior e: %i", num2);
	} else {
		printf("Esses numeros sao iguais");
	}
	
	
}
