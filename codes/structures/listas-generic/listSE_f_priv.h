#ifndef listSE_f_priv_H
#define listSE_f_priv_H

#include "listSE_f.h"

struct entry {
    void* info;
    struct entry *next;
};

typedef struct entry Entry;

struct list_se {
    long size;
    void (*destroi)(void *data);
    Entry *head;  
    Entry *tail;  
};

Entry* make_entry(void* data);
Entry* get_position(Lista_S* list,long pos);
void remove_entry(Lista_S* list,Entry **to_remove,void** data);


#endif

