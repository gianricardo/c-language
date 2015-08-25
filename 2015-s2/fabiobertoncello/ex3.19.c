#include<stdio.h>

int main(void){
	float venda_bruta=0.0,encargos=0.0;
	printf("informe os valores: (-1 para terminar)\n");
	scanf("%f",&venda_bruta);
		if(venda_bruta!=-1){
			printf("O pagamento que voce recebeu é: %.2f\n",(venda_bruta*0.09)+200.00);
		}
	while (venda_bruta!=-1){
		printf("informe os valores: (-1 para terminar)\n");
		scanf("%f",&venda_bruta);
		if(venda_bruta!=-1){
			printf("O pagamento que voce recebeu é: %.2f\n",(venda_bruta*0.09)+200.00);
		}
	}
return 0;
}
