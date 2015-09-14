#include<stdio.h>
int main(void){
	int numero,i=0,j=0;
	
	printf("informe o tamanho do quadrado:");
	scanf("%d",&numero);
	while((j)<numero){
		while((i)<numero){
			if((i+j)<(numero+j-1)&&((i+j)>(j))&&(j!=0)&&(j!=(numero-1))){
				printf("  ");
			
			}
			else{
					printf(" *");
			
			}
		++i;
		}
	printf("\n");
	++j,i=0;
	}


return 0;
}
