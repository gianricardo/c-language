#include<stdio.h>
#define MAIOR_NUMERO 10
int main(void){
	int numero=1;
	printf(" N\t10*N\t100*N\t1000*N\n\n");
	while(numero<=MAIOR_NUMERO){
		printf(" %d\t%d\t%d\t%d\n",numero++,numero*10,numero*100,1000*numero);
	
	}

return 0;
}
