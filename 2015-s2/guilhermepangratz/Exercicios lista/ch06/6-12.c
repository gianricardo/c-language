#include <stdio.h>

int main () {
	
	int i;
	
	int counts[10] = {0}; //a
	
	int bonus[15] = {0}; //b
	for ( i = 0; i < 15; i++ ) {
		bonus[i] += 1;
	}
	
	float tempoPorMes[12]; //c
	for ( i = 0; i < 12; i++) {
		printf("tempoPorMes[%d] = ", i);
		scanf("%f", &tempoPorMes[i]);
	}
	
	printf("\n");
	
	int bestScores[] = {3, 3, 2, 4, 5}; //d
	for ( i = 0; i < 5; i++) {
		printf("%d\n", bestScores[i]);
	}

	return 0;
}
