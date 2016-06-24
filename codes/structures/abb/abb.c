#include "abb_priv.h"
#include <stdio.h>
#include <stdlib.h>
#include "../listas-generic/listSE_f.h"

ArvBB* arv_criar(void (*mostrar)(void *data), void (*destruir)(void *data), int (*compara)(void *key1, void* key2)) {
    ArvBB* arv = (ArvBB*) malloc(sizeof(ArvBB));
    if (arv == NULL) {
        printf("%s - %d - Erro de memória.", __FILE__, __LINE__);
    } else {
        arv->tamanho = 0;
        arv->raiz = NULL;
        arv->destroi = destruir;
        arv->mostra = mostrar;
        arv->compara = compara;
    }
    return (arv);
}

codigo_erro arv_destruir(ArvBB** arv) {
    if ((*arv) == NULL) {
        return (INVALIDO);
    }
    if ((*arv)->raiz != NULL) {
        nodearv_destruir(&((*arv)->raiz), (*arv)->destroi, NULL);
    }
    free(*arv);
    *arv = NULL;
    return (SUCESSO);
}

bool arv_vazia(const ArvBB* arv) {
    return ((arv->raiz == NULL) && (arv->tamanho == 0));
}

long arv_tamanho(const ArvBB* arv) {
    return (arv->tamanho);
}

codigo_erro arv_insere(ArvBB* arv, void* data) {
    if ((arv) == NULL) {
        return (INVALIDO);
    }
    //verificar se possue funcao de comparacao senaum devolve codigo de erro
    bool achou;
    Node_Arv *t, *pai;
    if (arv->compara == NULL) {
        return (ESTADO_INVALIDO);
    }
    arv_encontrarPai(arv, data, &achou, &pai, NULL);
    if (achou) {
        return (DUPLICADO);
    } else {
        t = nodearv_criar(data);

        if (pai == NULL) {
            arv->raiz = t;
        } else {
            arv->compara(nodearv_info(pai), data) < 0 ? nodearv_novo_esq(pai, t) : nodearv_novo_dir(pai, t);
        }
        arv->tamanho++;
    }
    return (SUCESSO);
}

void arv_encontrarPai(ArvBB* arv, void* data, bool *encontrou, Node_Arv** pai, Node_Arv** x) {
    Node_Arv *q;
    *encontrou = false;
    *pai = NULL;

    if (arv->raiz == NULL) {
        return;
    }
    q = arv->raiz;
    while (q != NULL) {
        if (arv->compara(nodearv_info(q), data) == 0) {
            *encontrou = true;
            if (x != NULL) {
                *x = q;
            }
            return;
        }
        if (arv->compara(nodearv_info(q), data) < 0) {
            *pai = q;
            q = nodearv_esq(q);
        } else {
            *pai = q;
            q = nodearv_dir(q);
        }
    }

}

void arv_substitui_menor_direita(ArvBB *arv, Node_Arv *no, Node_Arv *suc) {
    Node_Arv *tmp;
    if(nodearv_esq(suc) == NULL) {
        Node_Arv *pai;
        bool bpai;
        arv_encontrarPai(arv,nodearv_info(suc),&bpai,&pai,NULL);
        nodearv_novo_info(no,nodearv_info(suc),arv->destroi);
        //remove suc
        tmp = suc;
        suc = nodearv_dir(suc); //altera no->dir
        nodearv_novo_dir(tmp,NULL);
        if(bpai)nodearv_novo_dir(pai,NULL);
        nodearv_destruir(&tmp,arv->destroi, NULL);
        //free(tmp);//destruir tmp
    } else
        arv_substitui_menor_direita(arv, no, nodearv_esq(suc));
}

void arv_remove_no(ArvBB *arv, Node_Arv **no) {
    Node_Arv *tmp;
    if(nodearv_esq(*no) == NULL) { //substitui pelo filho da direita (note que “no” pode ser folha)
        tmp = *no;
        *no = nodearv_dir(*no);
        //free(tmp);
        nodearv_novo_dir(tmp,NULL);
        nodearv_destruir(&tmp,arv->destroi,NULL);
    } else if(nodearv_dir(*no) == NULL) { //substitui pelo filho da esquerda
        tmp = *no;
        *no = nodearv_esq(*no);
        //free(tmp);
        nodearv_novo_esq(tmp,NULL);
        nodearv_destruir(&tmp,arv->destroi,NULL);
    } else {
        //o nó a ser removido tem os dois filhos
        arv_substitui_menor_direita(arv, *no, nodearv_dir(*no));
        //alternativamente arvore_substitui_maior_esquerda(arv, *no, *no->esq);
    }
}

codigo_erro arvore_remove_interna(ArvBB *arv, Node_Arv *raiz, void *valor) {
    if(arv_vazia(arv)) { //remoção em árvore vazia
        return UNDERFLOW;
    } else {
        int comp = arv->compara(valor, nodearv_info(raiz));
        if(comp == 0) { //achou o dado a ser removido
            arv_remove_no(arv, &raiz);
        } else if(comp > 0)
            return arvore_remove_interna(arv, nodearv_esq(raiz), valor);
        else //comp < 0
            return arvore_remove_interna(arv, nodearv_dir(raiz), valor);
    }
    arv->tamanho--;
    return (SUCESSO);
}

codigo_erro arv_remove(ArvBB* arv, void* data) {
    if (arv != NULL && data != NULL)
        return arvore_remove_interna(arv, arv->raiz, data);
    else
        return (INVALIDO);
}

codigo_erro arv_remove2(ArvBB* arv, void* data){
    Node_Arv *pai,*x,*xsucc;
    bool achou;
    // If EMPTY TREE
    if(arv->raiz==NULL) {
        return (UNDERFLOW);
    }
    pai=x=NULL;
    arv_encontrarPai(arv,data,&achou,&pai,&x);
    if(!achou) {
        return (VALOR_INVALIDO);
    }

     // Se o nó a apagar tiver duas subarvores
     if(nodearv_esq(x) != NULL && nodearv_dir(x) != NULL) {
         pai=x;
         xsucc=nodearv_dir(x);

         while(nodearv_esq(xsucc) != NULL) {
             pai=xsucc;
             xsucc=nodearv_esq(xsucc);
         }
         nodearv_novo_info(x,nodearv_info(xsucc),arv->destroi);
         x=xsucc;
     }

     // Se o nó a apagar não tiver subarvores
     if(nodearv_esq(x) == NULL && nodearv_dir(x) == NULL) {
         if(nodearv_dir(pai) == x) {
             nodearv_novo_dir(pai,NULL);
         } else {
             nodearv_novo_esq(pai,NULL);
         }
         nodearv_novo_dir(x,NULL);
         nodearv_novo_esq(x,NULL);
         nodearv_destruir(&x,arv->destroi,NULL);
         arv->tamanho--;
         return (SUCESSO);
     }

     // se o nó apenas tiver subarvore direita
     if(nodearv_esq(x) == NULL && nodearv_dir(x) != NULL ) {
         if(nodearv_esq(pai) == x) {
             nodearv_novo_esq(pai,nodearv_dir(x));
         } else {
             nodearv_novo_dir(pai,nodearv_dir(x));
         }
         nodearv_novo_dir(x,NULL);
         nodearv_novo_esq(x,NULL);
         nodearv_destruir(&x,arv->destroi,NULL);
         arv->tamanho--;
         return (SUCESSO);
     }

     // se o nó apenas tiver subarvore esquerda
     if(nodearv_esq(x) != NULL && nodearv_dir(x) == NULL) {
         if(nodearv_esq(pai) == x) {
             nodearv_novo_esq(pai,nodearv_esq(x));
         } else {
             nodearv_novo_dir(pai,nodearv_esq(x));
         }
         nodearv_novo_dir(x,NULL);
         nodearv_novo_esq(x,NULL);
         nodearv_destruir(&x,arv->destroi,NULL);
         arv->tamanho--;
         return (SUCESSO);
     }
     return (INVALIDO);
}

void arv_preordem_interna (const ArvBB* arv,const Node_Arv* raiz){
    if(raiz!=NULL){
        nodearv_mostra(raiz,arv->mostra);
        arv_preordem_interna (arv,nodearv_esq(raiz));
        arv_preordem_interna (arv,nodearv_dir(raiz));
    }
}

void arv_inordem_interna (const ArvBB* arv,const Node_Arv* raiz){
    if(raiz!=NULL){
        arv_inordem_interna (arv,nodearv_esq(raiz));
        nodearv_mostra(raiz,arv->mostra);
        arv_inordem_interna (arv,nodearv_dir(raiz));
    }
}

void arv_posordem_interna (const ArvBB* arv,const Node_Arv* raiz){
    if(raiz!=NULL){
        arv_posordem_interna (arv,nodearv_esq(raiz));
        arv_posordem_interna (arv,nodearv_dir(raiz));
        nodearv_mostra(raiz,arv->mostra);
    }
}

void        arv_preordem    (const ArvBB* arv){
    arv_preordem_interna(arv,arv->raiz);
}

void        arv_inordem     (const ArvBB* arv){
    arv_inordem_interna(arv,arv->raiz);
}

void        arv_posordem    (const ArvBB* arv){
    arv_posordem_interna(arv,arv->raiz);
}

bool        arv_busca_bin   (const ArvBB* arv, void* info){
    bool encontrou = false;
    Node_Arv *q = arv->raiz;
    while (q != NULL) {
        if (arv->compara(nodearv_info(q), info) == 0) {
            encontrou = true;
            break;
        }
        if (arv->compara(nodearv_info(q), info) < 0) {
            q = nodearv_esq(q);
        } else {
            q = nodearv_dir(q);
        }
    }
    return encontrou;
}

bool arv_busca (    const ArvBB* arv,
                    void* info ){
    Lista_S* fila = listas_create(NULL);
    Node_Arv *no;
    listas_push_back(fila,arv->raiz);
    while(!listas_empty(fila)){
        listas_pop_front(fila,(void*)&no);
        if(arv->compara(info,nodearv_info(no))==0){return (true);}
        if(nodearv_esq(no)!=NULL){listas_push_back(fila,nodearv_esq(no));}
        if(nodearv_dir(no)!=NULL){listas_push_back(fila,nodearv_dir(no));}
    }
    return (false);
    listas_destroy(&fila);
}

void arv_preordem_it(const ArvBB* arv){
    Lista_S* pilha = listas_create(NULL);
    Node_Arv *no;
    listas_push_front(pilha,arv->raiz);
    while(!listas_empty(pilha)){
        listas_pop_front(pilha,(void*)&no);
        nodearv_mostra(no,arv->mostra);
        if(nodearv_dir(no)!=NULL){listas_push_front(pilha,nodearv_dir(no));}
        if(nodearv_esq(no)!=NULL){listas_push_front(pilha,nodearv_esq(no));}
    }
    listas_destroy(&pilha);
}

void arv_mostra_busca(const ArvBB* arv){
    Lista_S* fila = listas_create(NULL);
    Node_Arv *no;
    listas_push_back(fila,arv->raiz);
    while(!listas_empty(fila)){
        listas_pop_front(fila,(void*)&no);
        nodearv_mostra(no,arv->mostra);
        if(nodearv_esq(no)!=NULL){listas_push_back(fila,nodearv_esq(no));}
        if(nodearv_dir(no)!=NULL){listas_push_back(fila,nodearv_dir(no));}
    }
    listas_destroy(&fila);
}
