#include <stdio.h>
#include <stdlib.h>
#include "listDE.h"

void destroy(void** dados){
    //int *ptr = (int*)*dados;
    //printf("Destruir (%d) ",*ptr);
    //free(ptr);
}

void print(void* dados){
    int *ptr = (int*)dados;
    printf("(%d) ",*ptr);
}

int main(void){
	int x=74,y=22,z=16,i;
	//int *pt=(int*)malloc(sizeof(int));
	//*pt=99;
	int vx[]={2,3,4,5,6,7,8,9,10,11};

	List_DE *l=lde_create(sizeof(int),destroy);
    
	if(l!=NULL) printf("Lista criada com sucesso.\n");
	else printf("Não foi possível criar a lista.\n");
    //
    lde_print(l,print);
    //
    
	if(lde_push_front(l,&x)==SUCCESS) 
        printf("Entrada (%d) inserida no início da lista.\n",x); 
	else printf("Inserção sem sucesso.\n");
    //
    lde_print(l,print);
    
    //
	for(i=0;i<10;i++){
		if(lde_push_back(l,vx+i)==SUCCESS) 
            printf("Entrada (%d) inserida no final da lista.\n",vx[i]);
		else
            printf("Inserção sem sucesso.\n");
	}
    //
    lde_print(l,print);
    //
    //
	if(lde_seek_insert(l,5,&z)==SUCCESS) 
         printf("Entrada (%d) inserida na posição 5 da lista.\n",z);
	else printf("Inserção sem sucesso.\n");
    //
    lde_print(l,print);
	if(lde_seek_insert(l,10,&y)==SUCCESS) 
         printf("Entrada (%d) inserida na posição 10 da lista.\n",y);
	else printf("Inserção sem sucesso.\n");
    //
    lde_print(l,print);    //
	if(lde_pop_front(l,&x)==SUCCESS) 
        printf("Item (%d) removido do início da lista.\n",x);
	else printf("Remoção sem sucesso.\n");
    //
    lde_print(l,print);
    //
	if(lde_pop_back(l,&x)==SUCCESS) 
        printf("Item (%d) removido do fim da lista.\n",x);
	else printf("Remoção sem sucesso.\n");
    //
    lde_print(l,print);
    //
	if(lde_seek_destroy(l,3,&x)==SUCCESS) 
        printf("Item (%d) removido da posição 3 da lista.\n",x);
	else printf("Remoção sem sucesso.\n");
    //
    lde_print(l,print);
    //
	if(lde_seek(l,2,&x)==SUCCESS) 
        printf("Item (%d) localizado na posição 2 da lista.\n",x);
	else printf("Localização sem sucesso.\n");
    //
    lde_print(l,print);
    //
    //
	printf("o tamanho da lista e %ld\n", lde_size(l));
	lde_destroy(&l);
	if(l==NULL) printf("Lista destruida com sucesso.\n");
	else printf("Não foi possível destruir a lista.\n");
	
	return 0;
}
