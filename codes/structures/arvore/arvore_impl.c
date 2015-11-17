#include "arvore_priv.h"
#include <stdlib.h>
#include <string.h>

Arvore* cria_arvore(){
    Arvore *nova;
    nova = (Arvore*) malloc(sizeof(Arvore));
    if(nova != NULL){
        nova->raiz=NULL;
    }
    return nova;
}

Arvore* cria_arvore_com_raiz(long valor){
    Arvore* nova = cria_arvore();
    if(nova!=NULL){
        No *novo=cria_no(valor);
        if(novo==NULL){
            free(nova);
        }else{
            nova->raiz=novo;
        }
    }
    return nova;
}

Error_code valor_no(No* no,long *dado){
    if(no == NULL) return INVALID_NODE;
    if(dado!=NULL) *dado = no->valor;
    return SUCCESS;
}


No* cria_no(long valor){
    No *novo;
    novo=(No*)malloc(sizeof(No));
    if(novo!=NULL){ 
        novo->valor=valor;
        novo->esq=NULL;
        novo->dir=NULL;
    }    
    return novo;
}

Error_code arvore_insere_esq(Arvore *arv, No *no, long dado){
	No **local,*novo;
    if(arv==NULL ) return INVALID;
    if(arv->raiz == NULL) local=&arv->raiz;
    if(no == NULL) {
	  local=&arv->raiz;
	}else{
	  local=&no->esq;
	}
    if(no->esq != NULL) return INVALID_POSITION;
    novo=cria_no(dado);
    if(novo==NULL) return BAD_ALLOCATION;
    *local=novo;   
    return SUCCESS;
}

Error_code arvore_insere_dir(Arvore *arv, No *no, long dado){
	No **local,*novo;
    if(arv==NULL ) return INVALID;
    if(arv->raiz == NULL) local=&(arv->raiz);
    if(no == NULL) {
	  local=&(arv->raiz);
	}else{
	  local=&(no->dir);
	}
    if(no->dir != NULL) return INVALID_POSITION;
    novo=cria_no(dado);
    if(novo==NULL) return BAD_ALLOCATION;
    *local=novo;   
    return SUCCESS;
}

void destroi_arvore(Arvore *arv) {
  arvore_remove_esq(arv, NULL);
  memset(arv, 0, sizeof(Arvore));
}

Error_code arvore_remove_esq(Arvore *arv, No *no) {
  No **position;
  if(arvore_vazia(arv)) return INVALID;
  /*encontra a posição de onde começar a remover*/
  if(no == NULL) position = &(arv->raiz);
  else position = &(no->esq);
  /*remove os nós*/
  if(*position != NULL) {
	arvore_remove_esq(arv, *position);
	arvore_remove_dir(arv, *position);
	free(*position);
	*position = NULL;
  }
  return SUCCESS; 
}

Error_code arvore_remove_dir(Arvore *arv,No *no) {
	No **position;
	if(arvore_vazia(arv)) return INVALID;
	/*encontra a posição de onde começar a remover*/
	if(no == NULL) position = &(arv->raiz);
	else position = &(no->dir);
	/*remove os nós*/
	if(*position != NULL) {
	  arvore_remove_esq(arv, *position);
	  arvore_remove_dir(arv, *position);
	  free(*position);
	  *position = NULL;
	}
	return SUCCESS; 
}


