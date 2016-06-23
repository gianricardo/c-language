/*
 * long_impl.c
 *
 *  Created on: Jun 23, 2016
 *      Author: gian
 */
#include "long_data.h"
#include <stdlib.h>
#include <stdio.h>

void mostra_long(void *data){
    long *dado = (long*) data;
    if(dado==NULL)printf("NULL");
    else printf(" %ld ",*dado);
}

long* crial(long val){
    long *pval=(long*) malloc(sizeof(long));
    *pval=val;
    return pval;
}

void destroi_long(void *data){
    long *info = (long*) data;
    if(info!= NULL){
        free(info);
    }
}

int compara_long(void *key1, void* key2){//0=igual; >0 key2 maior e key 1 menor; <0 key1 maior e key2 menor
    long *c1 = (long*)key1;
    long *c2 = (long*)key2;
    if(*c1==*c2){
        return (0);
    }else if(*c1 > *c2){
        return -1;
    }else{
        return 1;
    }
}

