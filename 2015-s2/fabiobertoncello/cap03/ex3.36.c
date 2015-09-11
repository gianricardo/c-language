#include<stdio.h>
#define TAMANHO_NUMERO 5
int main(void){
	int numero=10011010,multiplicador_10=1,multiplicador_2=1,numero_convertido=0,variavel_suporte=0;
	printf("informe o valor de 5 digitos: %d\n",numero);
	scanf("%d",&numero);
	while(1){
		printf("%d    ,",multiplicador_2*((numero%(10*multiplicador_10))/(multiplicador_10)));
		numero_convertido+=((numero%(10*multiplicador_10))/(multiplicador_10))*multiplicador_2;
		multiplicador_10*=10;
		multiplicador_2*=2;
		printf("%d\n",numero_convertido);
	
	//falta uma condicao de parada
	
	
	
	}
return 0;
}
