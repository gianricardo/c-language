#include "nodearv_priv.h"
#include <stdio.h>
#include <stdlib.h>

Node_Arv* nodearv_criar (void* info){
	Node_Arv* novo = (Node_Arv*)malloc(sizeof(Node_Arv));
	if(novo==NULL){	
		printf("%s - %d - Erro de memória.",__FILE__,__LINE__);
	}else{
		novo->info=info;
		nodearv_novo_dir(novo, NULL);
		nodearv_novo_esq(novo, NULL);
	}
	return (novo);
}

Node_Arv* nodearv_criar_ref (void* info,
							 Node_Arv* esquerda, 
							 Node_Arv* direita){
	Node_Arv* novo = nodearv_criar(info);
	if(novo!=NULL){	
		nodearv_novo_dir(novo, direita);
		nodearv_novo_esq(novo, esquerda);
	}
	return novo;
}

codigo_erro nodearv_destruir (Node_Arv** no,
                                   void (*destroy)(void *data), long *num_destruido){
	if((*no) == NULL) {return (INVALIDO);}
	
	//nodearv_mostra(*no);
	
	if(nodearv_esq(*no)!=NULL){
		Node_Arv* esq = nodearv_esq(*no);
		nodearv_destruir(&esq,destroy, num_destruido);
	}
	if(nodearv_dir(*no)!=NULL){
		Node_Arv* dir = nodearv_dir(*no);
		nodearv_destruir(&dir,destroy, num_destruido);
	}
	
	if(destroy != NULL){
	    (*destroy)((*no)->info);
	}
	if(num_destruido!=NULL)	*num_destruido = *num_destruido +1;
	free(*no);
	*no=NULL;
	return (SUCESSO);
}

void nodearv_mostra(const Node_Arv* no,
									void (*mostra)(void *data)){
	if(no == NULL){return;}
	printf("NODE[");
	(*mostra)(nodearv_info(no));
	printf(",");
	//if (nodearv_esq(no)!=NULL){
	   	printf("esq:");
	   	(*mostra)(nodearv_info(nodearv_esq(no)));
     	printf(",");
    //}else{printf("esq:NULL,");}
	//if (nodearv_dir(no)!=NULL){
	   	printf("dir:");
	   	(*mostra)(nodearv_info(nodearv_dir(no)));
    	printf(",");
    //}else{printf("dir:NULL,");}
	printf("folha:%s]\n",nodearv_folha(no)?"sim":"nao");
}

void* nodearv_info(const Node_Arv* no){
	if(no == NULL) {return (NULL);}
	return (no->info);
}

codigo_erro nodearv_novo_info(Node_Arv* no, void* ninfo,
									void (*destroy)(void *data)){
	if(no == NULL) {return (INVALIDO);}
	if(no->info != ninfo){
		(*destroy)(no->info);
	}
	no->info=ninfo;
	return (SUCESSO);
}

Node_Arv* nodearv_dir (const Node_Arv* no){
	if((no == NULL)) {return (NULL);}
	return (no->direita);
}

Node_Arv* nodearv_esq (const Node_Arv* no){
	if((no == NULL)) {return (NULL);}
	return (no->esquerda);
}

bool nodearv_folha (const Node_Arv* no){
	if((no == NULL)) {return (false);}
	return ((no->esquerda==NULL)&&(no->direita==NULL));
}

codigo_erro nodearv_novo_dir (Node_Arv* no, Node_Arv* direita){
	if(no == NULL) {return (INVALIDO);}
	no->direita=direita;
	return (SUCESSO);
}

codigo_erro nodearv_novo_esq (Node_Arv* no, Node_Arv* esquerda){
	if(no == NULL) {return (INVALIDO);}
	no->esquerda=esquerda;
	return (SUCESSO);
}

