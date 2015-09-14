#include<stdio.h>
#define NUMERO_FINAL 7


int main(void){
	int contador=0,numero1,numero2,numero3,segundo_maior,primeiro_maior;
	printf("informe os tres valores iniciais:\n");
	scanf("%d%d%d",&numero1,&numero2,&numero3);
	while(contador<NUMERO_FINAL){
		if(numero1!=numero2!=numero3){
			if((numero1>numero2)&&(numero1>numero3)){
				primeiro_maior=numero1;
				if(numero2>numero3){
					segundo_maior=numero2;
					printf("informe um valor: \n");
					scanf("%d",&numero3);
				}
				else{
					printf("IF ELSE 2\n");
					segundo_maior=numero3;
					printf("informe um valor: \n");
					scanf("%d",&numero2);
				
				}
		
			}
			else{
				if((numero2>numero1)&&(numero2>numero3)){
					primeiro_maior=numero2;
					if(numero1>numero3){
						segundo_maior=numero1;
						printf("informe um valor: \n");
						scanf("%d",&numero3);
					}
					else{
						printf("ELSE IF ELSE 4\n");
						segundo_maior=numero3;
						printf("informe um valor: \n");
						scanf("%d",&numero1);
				
					}
				}
				else{
					if((numero3>numero1)&&(numero3>numero2)){
						primeiro_maior=numero3;
						if(numero2>numero1){
							segundo_maior=numero2;
							printf("informe um valor: \n");
							scanf("%d",&numero1);
						}
						else{
							segundo_maior=numero1;
							printf("informe um valor: \n");
							scanf("%d",&numero3);
						}
					}
				}
			}
		}
		else{
			printf("informe um valor nao reptido\n");
			printf("informe os tres valores iniciais:\n");
			scanf("%d%d%d",&numero1,&numero2,&numero3);
		}
	}
	if((numero1>numero2)&&(numero1>numero3)){
				primeiro_maior=numero1;
				if(numero2>numero3){
					printf("contador %d os maiores valores sao %d e %d\n",contador,primeiro_maior,segundo_maior);
				}
				else{
					printf("contador %d os maiores valores sao %d e %d\n",contador,primeiro_maior,segundo_maior);
				}
		
			}
			else{
				if((numero2>numero1)&&(numero2>numero3)){
					primeiro_maior=numero2;
					if(numero1>numero3){
						printf("contador %d os maiores valores sao %d e %d\n",contador,primeiro_maior,segundo_maior);
					}
					else{
						printf("contador %d os maiores valores sao %d e %d\n",contador,primeiro_maior,segundo_maior);
					}
				}
				else{
					if((numero3>numero1)&&(numero3>numero2)){
						primeiro_maior=numero3;
						if(numero2>numero1){
							printf("contador %d os maiores valores sao %d e %d\n",contador,primeiro_maior,segundo_maior);
						}
						else{
							printf("contador %d os maiores valores sao %d e %d\n",contador,primeiro_maior,segundo_maior);
						}
					}
				}
			}

return 0;
}
