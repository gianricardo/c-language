#ifndef _ABB_PRIV_H
#define _ABB_PRIV_H

#include "abb.h"
#include "../arvore2/nodearv.h"

struct arvorebb_t{
    long tamanho;
    Node_Arv* raiz;
    void (*destroi)(void *data);
    void (*mostra)(void *data);
    int (*compara)(void *key1, void* key2); //0=igual; >0 key2 maior e key 1 menor; <0 key1 maior e key2 menor
};

void arv_encontrarPai(ArvBB* arv, void* data,bool *encontrou,Node_Arv** pai, Node_Arv** x);
codigo_erro arvore_remove_interna(ArvBB *arv, Node_Arv *raiz, void *valor);
void arv_remove_no(ArvBB *arv, Node_Arv **no);
void arv_substitui_menor_direita(ArvBB *arv, Node_Arv *no, Node_Arv *suc);
void arv_preordem_interna (const ArvBB* arv,const Node_Arv* raiz);
void arv_inordem_interna (const ArvBB* arv,const Node_Arv* raiz);
void arv_posordem_interna (const ArvBB* arv,const Node_Arv* raiz);

#endif
