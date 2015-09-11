#include<stdio.h>

int main(void){
	float valor_emprestimo=0.0,juros=0.0;
	int dias=0;
	printf("informe os valor principal do emprestimo: (-1 para terminar)\n");
	scanf("%f",&valor_emprestimo);
		if(valor_emprestimo!=-1){
			printf("informe a taxa de juros: \n");
			scanf("%f",&juros);
			printf("informe o prazo de emprestimo em dias: \n");
			scanf("%d",&dias);
			printf("O valor do juros é: %.2f\n\n",(valor_emprestimo*juros*dias)/365);
		}
	while (valor_emprestimo!=-1){
		printf("informe os valor principal do emprestimo: (-1 para terminar)\n");
		scanf("%f",&valor_emprestimo);
		if(valor_emprestimo!=-1){
			printf("informe a taxa de juros: \n");
			scanf("%f",&juros);
			printf("informe o prazo de emprestimo em dias: \n");
			scanf("%d",&dias);
			printf("O valor do juros é: %.2f\n\n",(valor_emprestimo*juros*dias)/365);
		}
	}
return 0;
}
