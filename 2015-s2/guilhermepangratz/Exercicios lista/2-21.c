//Verifica a forma desejada e a exibe no terminal (Quadrado, Circulo, Flecha, Losango)

#include <stdio.h>

int main () {
	
	int forma = 0;
	
	printf("Entre o numero da forma desejada:\n1 - Quadrado\n2 - Circulo\n3 - flecha\n4 - Losango\n\n");
	scanf("%i", &forma);

	if ( forma == 1 ) {
		printf("\n*********\n*       *\n*       *\n*       *\n*       *\n*       *\n*       *\n*       *\n*********");
	} else if ( forma == 2 ) {
		printf("\n  ***  \n *   * \n*     *\n*     *\n*     *\n*     *\n*     *\n *   * \n  ***");
	} else if ( forma == 3 ) {
		printf("\n  *  \n *** \n*****\n  *  \n  *  \n  *  \n  *  \n  *  \n  *");
	} else if ( forma == 4 ) {
		printf("\n    *    \n   * *  \n  *   *\n *     *\n*       *\n *     *\n  *   *\n   * *\n    *");
	}
	
	
	
}
