#include<stdio.h>
#define TAMANHO_NUMERO 5
int main(void){
	int numero,multiplicador=1;
	printf("informe o valor de 5 digitos: %d\n",numero);
	scanf("%d",&numero);
	while(1){
		if((numero%(10*multiplicador)/(multiplicador))!=(numero/(10000/multiplicador)%(10))){
			printf("o numero informado nao e um palindromo sinto muito: %d \n",numero);
			break;
		}
		else{
			printf("o numero informado e um palindromo sinto muito: %d \n",numero);
			break;
		
		}
		multiplicador*=10;
		
	
	
	
	
	
	}
return 0;
}
