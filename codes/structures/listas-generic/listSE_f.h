#ifndef listSE_f_H
#define listSE_f_H

#include <stdbool.h>
#include "../common/comum.h"

typedef struct list_se Lista_S;

Lista_S*    listas_create(void (*destroi)(void *data));
void 	    listas_destroy(Lista_S** list);
codigo_erro listas_push_back(Lista_S* list, void *data);
codigo_erro listas_push_front(Lista_S* list, void *data);
codigo_erro listas_pop_back(Lista_S* list, void **data);
codigo_erro listas_pop_front(Lista_S* list, void **data);
codigo_erro listas_seek_insert(long position,Lista_S* list, void *data);
codigo_erro listas_seek_destroy(long position,Lista_S* list, void **data);
codigo_erro listas_seek(Lista_S* list, long position,void **data);
long	    listas_size(Lista_S* list);
bool        listas_empty(const Lista_S* list);
void 	    listas_print(Lista_S* list,void (*visit)(void *data));

#endif

