#include <stdio.h>

int main () {
	
	int ns[5], i, j;
	
	printf("Entre 5 numeros inteiros entre 1 e 30: ");
	for (i=0; i<5; i++){
		scanf("%i", &ns[i]);
	}
	printf("\nHistograma:\n\n");
	
	for (i = 0; i < 5; i++) {
		printf("%2i: ", ns[i]);
		for (j = 0; j < ns[i]; j++) {
			printf("*");
		}
		printf("\n");
	} 
		
	
}
