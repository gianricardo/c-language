#include<stdio.h>
int main(void){
	int numero,i=0,j=0;
	
	printf("informe o tamanho do quadrado:");
	scanf("%d",&numero);
	while(j<numero){
		while(i<numero){
			printf("* ");
		++i;
		}
	printf("\n");
	++j,i=0;
	}


return 0;
}
