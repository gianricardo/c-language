#include <stdio.h>

int main () {
	
	int i, j, k, contador = 1;
	
	printf("%3s %3s %3s %3s\n", "n", "h", "c", "c");
	
	for ( i = 1; i < 501; i++) {
		for ( j = 1; j <= i; j++) {
			for ( k = 1; k <= j; k++) {
				if ( ((k * k) + (j * j)) == (i * i) ){
					printf("%3d %d %d %d\n", contador++, i, j, k);
				}
			}
		}
	}

	return 0;
}
