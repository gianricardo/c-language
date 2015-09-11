#include <stdio.h>

int main () {
	
	int deposito;
	
	printf("%-6s%-6s%-6s\n\n", "Dec", "Oct", "Hex");
	
	int i, j; //contadores
	
	for ( i = 1; i < 257; i++) {
		
		printf("%-6d%-6o%-6X\n", i, i, i);
		
	}
	
	return 0;
}
