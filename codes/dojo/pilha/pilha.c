#include "pilha_f.h"
#include <stdio.h>
#include <stdlib.h>

Pilha *criaPilha(int capacidade_maxima){
    Pilha *p;
    p=NULL;
    p=(Pilha *)malloc(sizeof(Pilha));
    if(p!=NULL){
        p->itens=(int *)malloc(sizeof(int)*capacidade_maxima);
        if(p->itens==NULL){
            free(p);
            p=NULL;
        }else{
            p->top=-1;
            p->maximo=capacidade_maxima;
        }
    }
    return p;
}

Error_code pushPilha(Pilha* p, int novo){
    if(p!=NULL){
        if(!fullPilha(p)){
            p->top=p->top+1;
            p->itens[p->top]=novo;
        }else{
            return OVERFLOW;
        }
    }else return INVALID;
    return SUCCESS;
}

Error_code popPilha(Pilha* p, int *r){
    
    int x;
    
    if(p!=NULL){
        if(!emptyPilha(p)){
            x=p->itens[p->top];
            p->top-=1;
            if(r!=NULL){
                *r=x;
            }
        }else{
            return UNDERFLOW;
        }
    }else{
        return INVALID;
    }
    return SUCCESS;
}

int emptyPilha(Pilha *p){
    if(p!=NULL){
        return p->top==-1;
    }
    return 0;
}

int topPilha(Pilha *p, int* val){
    if(p!=NULL){
        (*val) = p->itens[p->top];
        return 0;
    }
    return -1;
}


int fullPilha(Pilha *p){
    if(p!=NULL){
        if(p->top==p->maximo-1){
        return 1;
        }
    }
    return 0;
}

int sizePilha(Pilha *p){
    if(p!=NULL){
        return p->top + 1;
    }else{
        return 0;
    }
}

int maxPilha(Pilha *p){
    if(p!=NULL){
        return p->maximo;
    }else{
        return 0;
    }
}

void clearPilha(Pilha *p){
    if(p!=NULL){
        p->top = -1;
    }
}

void destroiPilha(Pilha **p){
    if (*p!=NULL){
        free((*p)->itens);
        free(*p);
        *p = NULL;
    }
}
