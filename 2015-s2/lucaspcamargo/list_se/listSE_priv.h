#ifndef listSE_priv_H
#define listSE_priv_H

#include "listSE.h"

struct entry {
    int campo1;
    double campo2;
    struct entry *next;
};

typedef struct entry Entry;

struct list_se {
    long size;
    Entry *head;    
};

Entry* make_entry(int nv, double nd);
//função para retornar uma Celula de acordo com uma posição lógica

#endif

