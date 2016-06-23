#include "arvore_priv.h"
#include <stdio.h>
#include <stdlib.h>
#include "../listas-generic/listSE_f.h"

Arvore*		arv_criar	(	void (*mostrar)(void *data),
							void (*destruir)(void *data)){
	Arvore* arv = (Arvore*)malloc(sizeof(Arvore));
	if(arv==NULL){
		printf("%s - %d - Erro de memória.",__FILE__,__LINE__);
	}else{
		arv->tamanho=0;
		arv->raiz=NULL;
		arv->destroi = destruir;
		arv->mostra = mostrar;
	}	
	return (arv);
}
	
codigo_erro arv_destruir(Arvore** arv){
	if((*arv) == NULL) {return (INVALIDO);}
	
	//(*arv)->raiz = nodearv_criar(NULL);
	
	if((*arv)->raiz!=NULL){
		//nodearv_mostra((*arv)->raiz,(*arv)->mostra);
		nodearv_destruir(&((*arv)->raiz),(*arv)->destroi,NULL);
	}
	
	free(*arv);
	*arv=NULL;
	return (SUCESSO);
}

codigo_erro arv_insere_dir(Arvore* arv, Node_Arv*no, void *data){
	if(arv==NULL) return (INVALIDO);
	Node_Arv* novo = nodearv_criar(data);

	if(arv_vazia(arv)){
	    arv->tamanho++;
		arv->raiz=novo;
		return (SUCESSO);
	}
	if(no == NULL){
		nodearv_destruir(&novo,arv->destroi,NULL);
	 	return INVALIDO;
	}
	if(nodearv_dir(no)!=NULL){
		nodearv_destruir(&novo,arv->destroi,NULL);
	 	return OVERFLOW;
	}
	arv->tamanho++;
	nodearv_novo_dir(no,novo);
	//nodearv_mostra(no,arv->mostra);
	return (SUCESSO);
}

codigo_erro arv_insere_esq(Arvore* arv, Node_Arv* no, void *data){
	if(arv==NULL) return (INVALIDO);
	Node_Arv* novo = nodearv_criar(data);

	if(arv_vazia(arv)){
	    arv->tamanho++;
		arv->raiz=novo;
		return (SUCESSO);
	}

	if(no == NULL){
		nodearv_destruir(&novo,arv->destroi,NULL);
	 	return INVALIDO;
	}
	if(nodearv_esq(no)!=NULL){
		nodearv_destruir(&novo,arv->destroi,NULL);
	 	return OVERFLOW;
	}
	arv->tamanho++;
	nodearv_novo_esq(no,novo);
	//nodearv_mostra(no,arv->mostra);
	return (SUCESSO);
}

codigo_erro arv_remove_dir	(Arvore* arv, Node_Arv* no){
	if(arv==NULL) return (INVALIDO);
	if(arv_vazia(arv))return (INVALIDO);
	codigo_erro er;
	if(no == NULL){
		Node_Arv* rem = arv->raiz;
		er = nodearv_destruir(&rem,arv->destroi,NULL);
		if(er==SUCESSO){
			arv->tamanho = 0;
			arv->raiz=NULL;
		}
	} else {
		Node_Arv* rem = nodearv_dir(no);
		long destruidos =0;
		er = nodearv_destruir(&rem,arv->destroi,&destruidos);
		if(er==SUCESSO){
			arv->tamanho = arv->tamanho - destruidos;
		}
	}
	return er;
}

codigo_erro arv_remove_esq	(Arvore* arv, Node_Arv*no){
	if(arv==NULL) return (INVALIDO);
	if(arv_vazia(arv))return (INVALIDO);
	codigo_erro er;
	if(no == NULL){
		Node_Arv* rem = arv->raiz;
		er = nodearv_destruir(&rem,arv->destroi,NULL);
		if(er==SUCESSO){
			arv->tamanho = 0;
			arv->raiz=NULL;
		}
	} else {
		Node_Arv* rem = nodearv_esq(no);
		long destruidos =0;
		er = nodearv_destruir(&rem,arv->destroi,&destruidos);
		if(er==SUCESSO){
			//Atualizar tamanho
		    arv->tamanho = arv->tamanho - destruidos;
		}
	}
	return er;
}

bool arv_vazia(const Arvore* arv){
	return ((arv->raiz==NULL)&&(arv->tamanho==0));	
}

long arv_tamanho(const Arvore* arv){
	return (arv->tamanho);
}

Node_Arv* arv_raiz(const Arvore* arv){	
	return (arv->raiz);
}

void arv_preordem (const Arvore* arv,const Node_Arv* raiz){
	if(raiz!=NULL){
        nodearv_mostra(raiz,arv->mostra);
		arv_preordem (arv,nodearv_esq(raiz));
		arv_preordem (arv,nodearv_dir(raiz));
	}
}

void arv_inordem (const Arvore* arv,const Node_Arv* raiz){
    if(raiz!=NULL){
        arv_inordem (arv,nodearv_esq(raiz));
        nodearv_mostra(raiz,arv->mostra);
        arv_inordem (arv,nodearv_dir(raiz));
    }
}

void arv_posordem (const Arvore* arv,const Node_Arv* raiz){
    if(raiz!=NULL){
        arv_posordem (arv,nodearv_esq(raiz));
        arv_posordem (arv,nodearv_dir(raiz));
        nodearv_mostra(raiz,arv->mostra);
    }
}

bool arv_estritamente_bin(const Arvore* arv,const Node_Arv* raiz){
	//nodearv_mostra(raiz,arv->mostra);
	if(raiz==NULL){return false;}
	if (nodearv_folha(raiz)){
			return true;
	}else{
		return ((arv_estritamente_bin(arv,nodearv_esq(raiz)))&&
		 	    (arv_estritamente_bin(arv,nodearv_dir(raiz))));
	}
}


long arv_profundidade(const Node_Arv* raiz){
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

bool arv_busca (    const Arvore* arv,
                    void* info,
                    bool (*compara)(void *key1, void* key2) ){
    Lista_S* fila = listas_create(NULL);
    Node_Arv *no;
    listas_push_back(fila,arv_raiz(arv));
    while(!listas_empty(fila)){
        listas_pop_front(fila,(void*)&no);
        if((*compara)(info,nodearv_info(no))){return (true);}
        if(nodearv_esq(no)!=NULL){listas_push_back(fila,nodearv_esq(no));}
        if(nodearv_dir(no)!=NULL){listas_push_back(fila,nodearv_dir(no));}
    }
    return (false);
    listas_destroy(&fila);
}

void arv_preordem_it(const Arvore* arv){
    Lista_S* pilha = listas_create(NULL);
    Node_Arv *no;
    listas_push_front(pilha,arv_raiz(arv));
    while(!listas_empty(pilha)){
        listas_pop_front(pilha,(void*)&no);
        nodearv_mostra(no,arv->mostra);
        if(nodearv_dir(no)!=NULL){listas_push_front(pilha,nodearv_dir(no));}
        if(nodearv_esq(no)!=NULL){listas_push_front(pilha,nodearv_esq(no));}
    }
    listas_destroy(&pilha);
}

void arv_mostra_busca(const Arvore* arv){
    Lista_S* fila = listas_create(NULL);
    Node_Arv *no;
    listas_push_back(fila,arv_raiz(arv));
    while(!listas_empty(fila)){
        listas_pop_front(fila,(void*)&no);
        nodearv_mostra(no,arv->mostra);
        if(nodearv_esq(no)!=NULL){listas_push_back(fila,nodearv_esq(no));}
        if(nodearv_dir(no)!=NULL){listas_push_back(fila,nodearv_dir(no));}
    }
    listas_destroy(&fila);
}
