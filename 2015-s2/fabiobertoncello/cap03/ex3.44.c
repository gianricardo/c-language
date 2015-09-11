#include<stdio.h>

int main(void){
	float lado_a,lado_b,lado_c;
	printf("informe o valores dos lados\n");
	scanf("%f%f%f",&lado_a,&lado_b,&lado_c);
	if(((lado_b-lado_c)<lado_a)&&((lado_b-lado_c)<lado_a)&&((lado_b+lado_c)>lado_a)){
		printf("e um triangulo\n");
	}
	else{
		printf("nao e um triangulo sinto muito'");
	
	}
	
return 0;
}
