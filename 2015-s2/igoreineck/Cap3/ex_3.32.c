#include <stdio.h>

int main(void){

	int x, y;

	printf("Digite um valor para y: ");
	scanf("%d", &y);

	printf("Digite um valor para x: ");
	scanf("%d", &x);

	if (y == 8){
		printf("@@@@@\n");
	}

	if (x == 5){
		printf("#####\n");
	}

	else{
		printf("$$$$$\n");
		printf("&&&&&\n");
	}

	return 0;
}