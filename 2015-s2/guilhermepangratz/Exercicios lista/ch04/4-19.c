#include <stdio.h>

int main () {
	
	float total = 0, quantidade;
	
	int i, produto, cond = 1;
	
	for ( i = 0; i < 7; i++) {
		printf("\nDia %d, insira o codigo do produto seguido da quantidade,\n"
				 "Produtos de 1 a 5, outro valor para passar o dia.", i + 1);
				 
		while ( cond ) {
			printf("\nProduto Quantidade: ");
			scanf("%d", &produto);
			
			if ( produto < 1 || produto > 5) {
				break;
			}
			
			scanf("%f", &quantidade);
			
			switch ( produto ) {
				case 1 : total += ( 2.98 * quantidade); 
				break;
				case 2 : total += ( 4.5 * quantidade); 
				break;
				case 3 : total += ( 9.98 * quantidade); 
				break;
				case 4 : total += ( 4.49 * quantidade); 
				break;
				case 5 : total += ( 6.87 * quantidade); 
				break;
			}
		}
	}
	
	printf("\nTotal da semana: %.2f\n\n", total);
	
	return 0;
}
