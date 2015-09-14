#include<stdio.h>
#define MAXIMO 10
int main(void){
	int i,j;
	for(i=1;i<=MAXIMO;i++){
		for(j=1;j<=i;j++){
			printf("* ");
		}
	printf("\n");
	}
	printf("\n");
		for(i=MAXIMO;i>=1;i--){
			for(j=1;j<=i;j++){
				printf("* ");
			}
	printf("\n");
	}
	
	printf("\n");
	for(i=MAXIMO;i>=1;i--){
		for(j=MAXIMO;j>i;j--){
			printf("  ");
		}
		for(j=1;j<=i;j++){
			printf("* ");
		}
	printf("\n");
	}
		
	printf("\n");
	for(i=MAXIMO;i>=1;i--){
		for(j=1;j<i;j++){
			printf("  ");
		}
		for(j=MAXIMO;j>=i;j--){
			printf("* ");
		}
	printf("\n");
	}

return 0;
}
