#include <stdio.h>

int main(void){

	int x, y;

	printf("Digite um número para x: ");
	scanf("%d", &x);

	printf("Digite um número para y: ");
	scanf("%d", &y);

	if (x < 10){
		printf("*****\n");
	}

	if (y > 10){
		printf("#####\n");
	}

	else{
		printf("$$$$$\n");
	}

	return 0;
}