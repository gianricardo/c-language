#ifndef listSE_f_priv_H
#define listSE_f_priv_H

#include "listSE_f.h"

struct entry {
    int campo1;
    double campo2;
    struct entry *next;
};

typedef struct entry Entry;

struct list_se_f {
    long size;
    Entry *head;  
    Entry *tail;  
};

Entry* make_entry(int nv, double nd);
Entry* get_position(List_SE_f* list,long pos);
void remove_entry(List_SE_f* list,Entry **to_remove,int* nv, double* nd);


#endif

