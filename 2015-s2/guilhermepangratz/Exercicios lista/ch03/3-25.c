#include <stdio.h>

int main () {
	
	int i = 1;
	
	printf("%-2c\t%4s\t%5s\t%6s\n\n", 'N', "10*N", "100*N", "1000*N");
	
	for (; i < 11; i++) {
		printf("%-2d\t%-4d\t%-5d\t%-6d\n", i, 10*i, 100*i, 1000*i);
	}
	
	return 0;
}
