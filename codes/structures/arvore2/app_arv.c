#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>

//
//funções específicas do tipo de informação 
//
long* crial(long val);
void destroi_long(void *data);
void mostra_long(void *data);
bool compara_long(void *key1, void* key2);
//fim das funções

int main(void){
	Arvore*	arvore = arv_criar	(mostra_long,destroi_long);
	arv_insere_dir(arvore,NULL, crial(1));	
	Node_Arv* n1 = arv_raiz(arvore);
	long chave = 10;
	//arv_preordem (arvore,n1);printf("1--\n");
	Node_Arv *n3,*n4;
	arv_insere_dir(arvore,n1,crial(3));//arv_preordem (arvore,n1);printf("2--\n");
	arv_insere_esq(arvore,n1,crial(2));//arv_preordem (arvore,n1);printf("3--\n");
	n3 = nodearv_dir(n1);
	arv_insere_dir(arvore,n3,crial(5));//arv_preordem (arvore,n1);printf("4--\n");
	arv_insere_esq(arvore,n3,crial(4));//	arv_preordem (arvore,n1);printf("5--\n");
	n4 = nodearv_esq(n3);
	arv_insere_dir(arvore,n4,crial(7));//arv_preordem (arvore,n1);printf("6--\n");
	arv_insere_esq(arvore,n4,crial(6));
	printf("=====\n");
	printf("\nEstritamente Bin: %s\n\n\n",arv_estritamente_bin(arvore,n1)?"sim":"nao");
	arv_preordem (arvore,n1);printf("\n--------\n");
	arv_preordem_it(arvore);
	if(arv_busca(arvore,&chave,compara_long)){ printf("Encontrou %ld\n",chave);}else{printf("NAO encontrou %ld\n",chave);}
    chave=2;
	if(arv_busca(arvore,&chave,compara_long)){ printf("Encontrou %ld\n",chave);}else{printf("NAO encontrou %ld\n",chave);}
    chave=7;
    if(arv_busca(arvore,&chave,compara_long)){ printf("Encontrou %ld\n",chave);}else{printf("NAO encontrou %ld\n",chave);}
    chave=20;
    if(arv_busca(arvore,&chave,compara_long)){ printf("Encontrou %ld\n",chave);}else{printf("NAO encontrou %ld\n",chave);}
    arv_mostra_busca(arvore);
    arv_destruir(&arvore);
	return (0);
}


void mostra_long(void *data){
	long *dado = (long*) data;
	if(dado==NULL)printf("NULL");
	else printf(" %ld ",*dado);
}

long* crial(long val){
	long *pval=(long*) malloc(sizeof(long));
	*pval=val;
	return pval;
}

void destroi_long(void *data){
	long *info = (long*) data;
	if(info!= NULL){
		free(info);
	}
}

bool compara_long(void *key1, void* key2){
    long *c1 = (long*)key1;
    long *c2 = (long*)key2;
    return (*c1==*c2);
}
