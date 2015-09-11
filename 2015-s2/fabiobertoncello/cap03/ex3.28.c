#include<stdio.h>
int main(void){
	int valor=0;
	while((valor!=1)&&(valor!=2)){
		printf("informe um valor para sair deste aplicativo: ");
		scanf("%d",&valor);
	}

return 0;
}
