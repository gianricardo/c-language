#ifndef ARVORE_PRIV_H
#define ARVORE_PRIV_H

#include "arvore.h"

struct no {
    long valor;
    struct no *esq,*dir;
};

struct arvore {
    struct no *raiz;
};

#endif

