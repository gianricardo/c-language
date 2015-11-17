#ifndef listDE_priv_H
#define listDE_priv_H

#include "listDE.h"

struct entry {
    void *data;
    struct entry *next;
    struct entry *prev;
};

typedef struct entry Entry;

struct list_de {
    long list_size;
    long element_size;
    void (*destroy_entry)(void **data);
    Entry *head;  
    Entry *tail;  
};

void copy_data(Entry* entry,void* dst, long size);
Entry* get_position(List_DE* list,long pos);
Entry* make_entry(void *nd);
void remove_entry(List_DE* list,Entry **to_remove,void* nd);


#endif

