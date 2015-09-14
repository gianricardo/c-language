#include<stdio.h>
#define PI 3.14159
int main(void){
	float raio;
	printf("informe o valor do raio\n");
	scanf("%f",&raio);
	printf("o diametro %f circunferencia %f e a area %f \n",raio*2.0,PI*raio,PI*raio*raio);
	
return 0;
}
