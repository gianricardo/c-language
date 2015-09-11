#include <stdio.h>

int main(void){

	float quantidade;
	int valor;
	float total;
	float media;
	
	while (valor != 9999){
		
		printf("Digite o valor a ser somado: ");
		scanf("%d", &valor);

		if(valor == 9999){
			break;
		}

		quantidade += 1;
		total += valor;
	}

	media = (total/quantidade);

	printf("Média: %.2f\n", media);

	return 0;
}