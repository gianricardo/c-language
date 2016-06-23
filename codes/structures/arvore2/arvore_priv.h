#ifndef __ARVORE_PRIV_H
#define __ARVORE_PRIV_H

#include "arvore.h"

struct arvore_t{
	long tamanho;
	Node_Arv* raiz;
	void (*destroi)(void *data);
	void (*mostra)(void *data);
};

#endif
