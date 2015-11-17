#include <stdio.h>
#include <stdlib.h>
#include "listSE_f.h"

void print(int intg,double doble){
    printf("(%d <-> %.2lf) ",intg,doble);
}

int main(void){
	int x=4,y=2,z=6,i;
	double a=2.7,b=6.6,c=9.8;

	List_SE_f *l=lsef_create();
    
	if(l!=NULL) printf("Lista criada com sucesso.\n");
	else printf("Não foi possível criar a lista.\n");
    //
    lsef_print(l,print);
    //
	if(lsef_push_front(l,x,a)==SUCCESS) 
        printf("Entrada (%d,%lf) inserida no início da lista.\n",x,a); 
	else printf("Inserção sem sucesso.\n");
    //
    lsef_print(l,print);
    //
	for(i=0;i<10;i++){
		if(lsef_push_back(l,y+i,b)==SUCCESS) 
            printf("Entrada (%d,%lf) inserida no final da lista.\n",y+i,b);
		else
            printf("Inserção sem sucesso.\n");
	}
    //
    lsef_print(l,print);
    //
	if(lsef_seek_insert(5,l,z,c)==SUCCESS) 
         printf("Entrada (%d,%lf) inserida na posição 5 da lista.\n",z,c);
	else printf("Inserção sem sucesso.\n");
    //
    lsef_print(l,print);
    //
	if(lsef_pop_front(l,&x,&a)==SUCCESS) 
        printf("Item (%d,%lf) removido do início da lista.\n",x,a);
	else printf("Remoção sem sucesso.\n");
    //
    lsef_print(l,print);
    //
	if(lsef_pop_back(l,&x,&a)==SUCCESS) 
        printf("Item (%d,%lf) removido do fim da lista.\n",x,a);
	else printf("Remoção sem sucesso.\n");
    //
    lsef_print(l,print);
    //
	if(lsef_seek_destroy(3,l,&x,&a)==SUCCESS) 
        printf("Item (%d,%lf) removido da posição 3 da lista.\n",x,a);
	else printf("Remoção sem sucesso.\n");
    //
    lsef_print(l,print);
    //
	if(lsef_seek(2,l,&x,&a)==SUCCESS) 
        printf("Item (%d,%lf) localizado na posição 2 da lista.\n",x,a);
	else printf("Localização sem sucesso.\n");
    //
    lsef_print(l,print);
    //
	printf("o tamanho da lista e %ld\n", lsef_size(l));
	lsef_destroy(&l);
	return 0;
}
