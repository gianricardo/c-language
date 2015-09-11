#include <stdio.h>

unsigned fibonacci(unsigned n);

int main () {
	
	unsigned n;
	
	printf("n: ");
	scanf("%d", &n);
	
	printf("\nFibonacci(%d): %d\n", n, fibonacci(n)); 
 	
	return 0;
}

unsigned fibonacci(unsigned n) {
	
	unsigned i, a = 0, b = 1, c = 1;
	
	if ( n != 0 && n!=1 ) {
		for ( i = 0; i < n; i++) {
		
			c = a + b;
			a = b;
			b = c;
		
		}
		return c;
		
	} else if ( n == 0) {
		return 0;
	} else {
		return 1;
	}
	
}
