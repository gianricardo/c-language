#include "nodearv.h"
#include <stdio.h>
#include <stdlib.h>

Node_Arv* constroi(void);

bool arv_estritamente_bin(Node_Arv* raiz);
long arv_altura(Node_Arv* raiz);
long arv_profundidade(Node_Arv* raiz);
//
//funções específicas do tipo de informação 
//
long* crial(long val);
void destroi_long(void *data);
void mostra_long(void *data);
//fim das funções

int main(void){
	Node_Arv* raiz = constroi();
	
	Node_Arv* node1 = nodearv_criar(crial(1));
	Node_Arv* novo2=node1;
	while(1){
		Node_Arv* novo = nodearv_criar(crial(3));
		if(novo==NULL) break;
		nodearv_novo_dir(novo2,novo);
		novo2=novo;
	}
	exit(0);
	
	
	printf("%ld - %ld\n\n\n",sizeof(long),sizeof(long double));
	printf("Estritamente Bin: %s\n\n\n",arv_estritamente_bin(raiz)?"sim":"nao");
	printf("Profundidade: %ld\n\n\n",arv_profundidade(raiz));
	nodearv_destruir(&raiz,destroi_long);
	return 0;
}

Node_Arv* constroi(void){
	Node_Arv* node1 = nodearv_criar(crial(1));
	nodearv_novo_dir(node1,nodearv_criar(crial(3)));
	nodearv_novo_esq(node1,nodearv_criar(crial(2)));
	nodearv_novo_dir(nodearv_dir(node1),nodearv_criar(crial(5)));
	nodearv_novo_esq(nodearv_dir(node1),nodearv_criar(crial(4)));		
	Node_Arv* node4 = nodearv_esq(nodearv_dir(node1));
	nodearv_novo_dir(node4,nodearv_criar(crial(7)));
	nodearv_novo_esq(node4,nodearv_criar(crial(6)));		
	/*
	Node_Arv* node1 = nodearv_criar_ref(1,
	                            nodearv_criar(2),
	                            nodearv_criar_ref(3,
	                            	   nodearv_criar_ref(4,
	                            		   nodearv_criar(6),
	                            		   nodearv_criar(7)),
	                            	   nodearv_criar(5))
	                            	       );			
	*/
	return node1;
}

bool arv_estritamente_bin(Node_Arv* raiz){
	nodearv_mostra(raiz,mostra_long);
	if(raiz==NULL){return false;}
	if (nodearv_folha(raiz)){
			return true;
	}else{
		return ((arv_estritamente_bin(nodearv_esq(raiz)))&&
		 	    (arv_estritamente_bin(nodearv_dir(raiz))));
	}
}


long arv_profundidade(Node_Arv* raiz){
    long u, v;
    if (raiz == NULL) return -1;
    u = arv_profundidade(nodearv_esq(raiz));
    v = arv_profundidade(nodearv_dir(raiz));
    if (u > v) {
    	return u+1;
    } else {
    	return v+1;
    }
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




