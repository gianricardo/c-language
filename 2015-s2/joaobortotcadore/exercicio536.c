#include <stdio.h>

void movern(int numero_discos, int pino_origem, int pino_destino, int pino_temp);

int main(void){

movern(3,1,3,2);

}

void movern(int numero_discos, int pino_origem, int pino_destino, int pino_temp)
{
	//caso basico
	if(numero_discos == 1){
		printf("%d -> %d\n", pino_origem, pino_destino); //imprime movimentaçao
	}else{
		movern(numero_discos - 1, pino_origem, pino_temp, pino_destino ); 
       		printf ("%d -> %d\n", pino_origem, pino_destino);
        	movern(numero_discos - 1, pino_temp, pino_destino, pino_origem );
	}
}
