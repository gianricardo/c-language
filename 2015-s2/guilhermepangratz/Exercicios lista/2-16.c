//Lê dois inteiros do teclado e depois exibe o valor da soma, produto, diferença, quociente e modlo entre estes inteiros


#include <stdio.h>

int main(){
	
	while (1 == 1){
		int num1, num2;
		
		printf("entre dois numeros inteiros: ");
		
		scanf("%d%d", &num1, &num2);
		
		printf("Numeros lidos: %d ; %d\n", num1, num2);
	
		printf("Soma: %d\nProduto: %d\nDiferenca: %d\nQuociete: %d\nModulo: %d\n", num1+num2, num1*num2, num1-num2, num1/num2, num1%num2);
	}
	
}
