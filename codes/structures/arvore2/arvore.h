#ifndef __ARVORE_H
#define __ARVORE_H

#include "nodearv.h"

typedef struct arvore_t Arvore;

Arvore*		arv_criar		(	void (*mostrar)(void *data),
							void (*destruir)(void *data));
codigo_erro arv_destruir	(Arvore** arv); 
//
codigo_erro arv_insere_dir	(Arvore* arv, Node_Arv*no, void *data);
codigo_erro arv_insere_esq	(Arvore* arv, Node_Arv*no, void *data);
codigo_erro arv_remove_dir	(Arvore* arv, Node_Arv*no);
codigo_erro arv_remove_esq	(Arvore* arv, Node_Arv*no);
//
bool 		arv_vazia		(const Arvore* arv);
long 		arv_tamanho		(const Arvore* arv);
Node_Arv* 	arv_raiz		(const Arvore* arv);
void 		arv_preordem	(const Arvore* arv,const Node_Arv* raiz);
void        arv_inordem     (const Arvore* arv,const Node_Arv* raiz);
void        arv_posordem    (const Arvore* arv,const Node_Arv* raiz);
bool        arv_busca       (const Arvore* arv, void* info, bool (*compara)(void *key1, void* key2) );
void        arv_mostra_busca(const Arvore* arv);
void        arv_preordem_it (const Arvore* arv);
//
bool arv_estritamente_bin(const Arvore* arv,const Node_Arv* raiz);
//long arv_altura(Node_Arv* raiz);
long arv_profundidade(const Node_Arv* raiz);

#endif
