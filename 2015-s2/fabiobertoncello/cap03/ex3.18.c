#include<stdio.h>

int main(void){
	int n_conta=0;	
	float saldo=0.0,encargos=0.0,limite_creditos=0.0,total_creditos=0.0;
	while (n_conta!=-1){
		printf("informe o numero da conta:(-1 para terminar a) \n");
		scanf("%d",&n_conta);
		if (n_conta!=-1){
			printf("informe o saldo inicial: \n");
			scanf("%f",&saldo);
			printf("informe o total de encargos: \n");
			scanf("%f",&encargos);
			printf("informe o total de creditos: \n");
			scanf("%f",&total_creditos);
			printf("informe o limite de creditos: \n");
			scanf("%f",&limite_creditos);
			printf("\v\n");
		}
			if(((saldo+encargos-total_creditos)>limite_creditos)&&(n_conta!=-1)){
				printf("conta: %.2d \n\vLimite de credito: %.2f \n",n_conta,limite_creditos);
				printf("saldo: %.2f \n",saldo+encargos-total_creditos);
				printf("limite de credito ultrapassado: \n\v");
			}
	
	}
return 0;

}
