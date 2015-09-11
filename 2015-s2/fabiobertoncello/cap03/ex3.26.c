#include<stdio.h>
#define MAIOR_NUMERO 15
int main(void){
	int numero=0;
	printf(" A\t2+A\t4+A\t6+A\n\n");
	while(numero<MAIOR_NUMERO){
		printf(" %d\t%d\t%d\t%d\n",numero,numero+2,numero+4,6+(numero+=3));
	
	}

return 0;
}
