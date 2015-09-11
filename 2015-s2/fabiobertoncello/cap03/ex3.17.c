#include<stdio.h>

int main(void){
	float d_percorrida=0.0,l_abastecido=0.0,consumo_total=0.0,km_total=0.0,litros_total=0.0;
	while((d_percorrida!=-1.0)&&(l_abastecido!=-1.0)){
		printf("informe quantos litros abasteceu(-1 para finalizar o programa): \n");
		scanf("%f",&l_abastecido);
		printf("infome quantos km dirigiu: \n");
		scanf("%f",&d_percorrida);
		if((d_percorrida>0.0)&&(l_abastecido>0.0)||(consumo_total>0.0)){
			printf("O consumo atual é de: %f \n",d_percorrida/l_abastecido);
			litros_total+=l_abastecido;
			km_total+=d_percorrida;
		}
	}
	printf("O consumo total é de: %f\n",km_total/litros_total);
}
