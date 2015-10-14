#include "pilha_e.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimePilha(Pilha *pilha);

int main (){
   
    Pilha *pilha;
    pilha = criaPilha(10);

    if (emptyPilha(pilha))
	{
		printf ("A pilha está vazia\n");
	}
    if (popPilha(pilha,NULL)==UNDERFLOW)
	{    
		printf ("Ocorreu UNDERFLOW da pilha\n");
	}
	
	for(long l = 0; ; l++)
	{	
		if(pushPilha(pilha, (int) l ) == OVERFLOW)
		{
			printf ("Ocorreu OVERFLOW da pilha no %ld-esimo elemento\n", l);
			break;
		}
	}
	
	imprimePilha(pilha);

    destroiPilha(&pilha);
    
    return 0;
}

void imprimePilha(Pilha *pilha){
	Pilha *aux;
	int aux2;
	aux=criaPilha(sizePilha(pilha)); // tamanho atual da pilha
	while (!emptyPilha(pilha)){
			popPilha(pilha,&aux2);
			pushPilha(aux,aux2);
	}
	while (!emptyPilha(aux)){
			popPilha(aux,&aux2);
			pushPilha(pilha,aux2);
			printf("%3d", aux2);
	}
	printf("\n");
}
    
