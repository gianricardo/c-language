#include<stdio.h>
#define NUMERO_FINAL 2

int main(void){
	int lado_a,lado_b,numero,lado_c;
	printf("informe um lado do triangulo\n");
	
	scanf("%d%d%d",&lado_a,&lado_b,&lado_c);
	
	if((lado_a*lado_a)==((lado_b*lado_b)+(lado_c*lado_c))){
		printf("forma um triangulo retangulo ,sinto muito \n");
	}
	else{
		if((lado_b*lado_b)==((lado_c*lado_c)+(lado_a*lado_a))){
			printf("forma um triangulo retangulo ,sinto muito \n");
		}
		else{
			if((lado_c*lado_c)==((lado_b*lado_b)+(lado_a*lado_a))){
				printf("forma um triangulo retangulo ,sinto muito \n");
			}
			else{
				printf("nao forma um triangulo retangulo ,sinto muito \n");
			}
		}      
	}
return 0;
}
