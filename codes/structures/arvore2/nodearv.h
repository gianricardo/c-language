#ifndef __NODEARV_H
#define __NODEARV_H

#include "../common/comum.h"
#include <stdbool.h>

typedef struct nodearv_t Node_Arv;
//
//Operações de criação e liberação
//
Node_Arv* 	nodearv_criar		(void* info);
Node_Arv* 	nodearv_criar_ref	(void* info,
										Node_Arv* esquerda, 
										Node_Arv* direita);
codigo_erro nodearv_destruir	(Node_Arv** no,
                                   void (*destroy)(void *data), long *num_destruido);
//
//Operações de acesso e manipulação
//
void* 		nodearv_info		(const Node_Arv* no);
Node_Arv* 	nodearv_dir			(const Node_Arv* no);
Node_Arv* 	nodearv_esq			(const Node_Arv* no); 
bool 		nodearv_folha		(const Node_Arv* no);
void 		nodearv_mostra		(const Node_Arv* no,
									void (*mostra)(void *data));
//
codigo_erro nodearv_novo_info	(Node_Arv* no, void* ninfo,
									void (*destroy)(void *data));
codigo_erro nodearv_novo_dir	(Node_Arv* no, Node_Arv* direita);
codigo_erro nodearv_novo_esq	(Node_Arv* no, Node_Arv* esquerda);

#endif
