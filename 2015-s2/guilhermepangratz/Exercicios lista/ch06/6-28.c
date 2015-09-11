//gerador randomico n está funcioanndo da maneira adequada!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main () {
	
	srand(time(NULL));
	
	int aleatorios[20] = {0};
	
	int i, j, segura, lacre = 1;	
	
	for ( i = 0; i < 20;) {
		
		segura = rand() % 20 + 1;
		for ( j = 0; j < i; j++) {
			if (segura == aleatorios[j] ) {
				lacre = 0;
			}
		}
		if (lacre){
			i++; 
			aleatorios[i] = segura;
		}
		printf("%d \n ", aleatorios[i]);

	}	
	
	printf("\n");
	
	return 0;
}

