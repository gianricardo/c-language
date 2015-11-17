#ifndef listDE_H
#define listDE_H

#include "../common/5603_common.h"

typedef struct list_de List_DE;

List_DE* lde_create(long data_size,void (*destroy)(void **data));
void lde_destroy(List_DE** list);

Error_code lde_push_back(List_DE* list, void *nd);
Error_code lde_push_front(List_DE* list, void *nd);
Error_code lde_pop_back(List_DE* list, void* nd);
Error_code lde_pop_front(List_DE* list, void* nd);
Error_code lde_seek_insert(List_DE* list,long position, void* nd);
Error_code lde_seek_destroy(List_DE* list,long position, void* nd);
Error_code lde_seek(List_DE* list,long position, void* nd);

long lde_size(List_DE* list);
void lde_print(List_DE* list,void (*visit)(void* data));

//remove por valor da celula
//
#endif

