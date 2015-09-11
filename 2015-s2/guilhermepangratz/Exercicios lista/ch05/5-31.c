#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int flip();

int main () {
	
	srand(time(0));
	
	int i = 0, cara = 0, coroa = 0, f;
	
	for (; i < 100; i++) {
		
		f = flip();
		if ( f == 0) {
			cara++;
			printf("\n%d# lancamento - cara", i);
		} else {
			coroa++;
			printf("\n%d# lancamento - coroa", i);
		}
		
	}
	
	printf("\nCaras: %d - Coroas: %d ;", cara, coroa); 
	
	
	return 0;
}

int flip() {
	return rand() % 2;
}
