#include<stdio.h>
#define VALOR_MAXIMO 4
#define INTERVALO 8
int main(void){
	int contador=1,contador_2=1;
	
	while(contador<=VALOR_MAXIMO){
	
		while (contador_2<=8){
			printf("*");
			printf(" ");
			++contador_2;
		
		}
		printf("\n");
		contador_2=0;
		while (contador_2<=8){
			printf(" ");
			printf("*");
			++contador_2;
		}
		contador_2=0;
		++contador;
		printf("\n");
		
	}	 
return 0;
}
