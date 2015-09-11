#include <stdio.h>

int main () {
	
	int i =1;
	
	while ( i < 300000001 ) {
		if ( i % 100000000 == 0 ) {
			printf("%d", i / 100000000);
		}
		i++;
	}
	
	
	return 0;
}
