#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice();

int main () {
	srand(time(0));
	
	int resultados[11] = {0};
	
	int dice1, dice2, i = 0;
	
	for (; i<36000; i++) {
		dice1 = roll_dice();
		dice2 = roll_dice();
		resultados[dice1 + dice2 - 2]++;
	}
	
	printf("\nResultados\n%7d%7d%7d%7d%7d%7d%7d%7d%7d%7d%7d   resultado\n", 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
	
	for ( i=0; i < 11; i++) {
		printf("%7d", resultados[i]);
	}
	printf("   n\n");
	
	for ( i=0; i < 11; i++) {
		printf("%7.2f", resultados[i] * 100.0 / 36000);
	}
	printf("   n/100\n");
	
	return 0;
}

int roll_dice() {

	int n = rand() % 6 + 1;
	return n;
}
