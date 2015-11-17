#include "listDE_priv.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Entry* get_position(List_DE* list,long pos){
    long i,diff;
    Entry* it=list->head;
    diff = list->list_size-pos;
    if(diff<(list->list_size/2)){
        //move o iterador para a posição desejada
        it=list->tail;
        for(i=0;i<diff;i++){ //printf("%2ld",i);
        it=it->prev;}
    }else{
        //move o iterador para a posição desejada
        for(i=1;i<pos;i++){ //printf("%2ld",i);
        it=it->next;}
    }
    return it;
}

void copy_data(Entry* entry,void* dst, long size){
    //atribuir os valores da entrada
    if(dst!=NULL) memcpy(dst,entry->data, size);
}

void remove_entry(List_DE* list,Entry **to_remove,void* nd){
    //decrementar o tamanho da lista
    list->list_size-=1;
    //atribuir os valores da entrada
    copy_data((*to_remove), nd, list->element_size);
    //detruir entrada
    list->destroy_entry(&((*to_remove)->data));
    free(*to_remove);
    *to_remove=NULL;
}

List_DE* lde_create(long data_size,void (*destroy)(void **data)){
    List_DE *nl;
    nl = (List_DE*) malloc(sizeof(List_DE));
    if(nl!=NULL){
        nl->head=NULL;
        nl->tail=NULL;
        nl->list_size = 0;
        nl->element_size = data_size;
        nl->destroy_entry = destroy;
    }
    return nl;
}

void lde_destroy(List_DE** list){
    if(*list !=NULL){
        if((*list)->head!=NULL){
            Entry *mov=(*list)->head, *rmv;
            for(;mov!=NULL;){
                rmv=mov;
                mov=mov->next;
                (*list)->destroy_entry(&(rmv->data));
                free(rmv);
            }
            (*list)->head=NULL; 
            (*list)->tail=NULL;           
        }
        free(*list);
        *list=NULL;
    }    
}

Entry* make_entry(void *nd){
    Entry *ne;
    ne = (Entry*) malloc (sizeof(Entry));
    if(ne!=NULL){
        ne->next=NULL;
        ne->prev=NULL;
        ne->data=nd;
    }
    return ne;
}

Error_code lde_push_back(List_DE* list, void *nd){
    if(list==NULL) return INVALID;
    Entry* new_e;
    new_e=make_entry(nd);
    if(new_e == NULL) return BAD_ALLOCATION;
    if(list->head==NULL)return lde_push_front(list,nd);
    //ir até o final da lista
    Entry *it=list->tail;
    //inserir como o próximo do iterador
    it->next = new_e;
    new_e->prev = it;
    //atualizar a nova cauda
    list->tail = new_e;
    //incrementa o tamanho da lista
    list->list_size+=1;
    return SUCCESS;
}

Error_code lde_push_front(List_DE* list, void *nd){
    Entry* new_e;
    new_e=make_entry(nd);
    if(new_e == NULL) return BAD_ALLOCATION;
    if(list==NULL) return INVALID;
    //nova frente aponta para antiga frente
    new_e->next = list->head; 
    //se for a primeira inserção, atualizar a cauda
    if(list->head==NULL){   
        list->tail = new_e;
    }else{
        //antiga frente aponta para nova frente
        list->head->prev = new_e;
    }
    //descritor da lista aponta para a nova frente
    list->head = new_e;
    //incrementar o tamanho
    list->list_size += 1;
    return SUCCESS;

}

Error_code lde_pop_back(List_DE* list, void* nd){
    if(list==NULL) return INVALID;
    if(list->head == NULL) return UNDERFLOW;
    if(list->list_size <  2) return lde_pop_front(list, nd);
    Entry *to_remove, *it;
    //procura o penultimo
    it=list->tail->prev;
    //it é o penultimo
    to_remove = it->next;
    //retiro a entrada da lista e atualiza a cauda
    it->next = NULL;
    list->tail=it;
    //remove o último
    remove_entry(list,&to_remove,nd);
    return SUCCESS;
}

Error_code lde_pop_front(List_DE* list, void* nd){
    if(list==NULL) return INVALID;
    if(list->head == NULL) return UNDERFLOW;
    Entry *to_remove=list->head;
    //remover da lista
    list->head=to_remove->next;
    if(list->head==NULL){
        list->tail=NULL;
    }else{
        list->head->prev=NULL;
    }
    remove_entry(list,&to_remove,nd);
    return SUCCESS;

}

Error_code lde_seek_insert(List_DE* list,long position, void* nd){
    if(list     == NULL      ) return INVALID;
    if(position <= 1         ) return lde_push_front(list, nd);
    if(position >  list->list_size) return lde_push_back(list, nd);
    Entry* new_e;
    new_e=make_entry(nd);
    if(new_e == NULL) return BAD_ALLOCATION;
    Entry* it=get_position(list,position-1);
    //1-ligar a entrada nova na lista no proximo do it 
    new_e->next=it->next;
    //2-ligar o anterior da nova entrada na lista
    new_e->prev=it;
    //3-ligar o anterior do proximo da nova entrada da lista 
    new_e->next->prev=new_e;
    //4-ligar a posicao-1 na nova entrada
    it->next=new_e;
    //incrementar tamanho
    list->list_size+=1;
    return SUCCESS;
}

Error_code lde_seek_destroy(List_DE* list,long position, void* nd){
    if(list == NULL) return INVALID;
    if(position < 0 || position > list->list_size) return INVALID_POSITION;
    if(position <= 1         ) return lde_pop_front(list, nd);
    if(position ==  list->list_size) return lde_pop_back(list, nd);    
    Entry* it, *to_remove, *following;
    //move o iterador para a posição anterior à entrada a ser removida
    it=get_position(list,position-1);
    to_remove = it->next;//entrada a ser removida
    following = to_remove->next;//o seguinte a entrada a ser removida
    
    //retirar a entrada da lista
    following->prev=it;
    it->next=following;
    
    remove_entry(list,&to_remove,nd);
    return SUCCESS;
}

Error_code lde_seek(List_DE* list,long position, void* nd){
    if(list == NULL) return INVALID;
    if(position < 0 || position > list->list_size) return INVALID_POSITION;
    Entry* it=get_position(list,position);
    //atribuir os valores da entrada
    copy_data(it, nd, list->element_size);
    return SUCCESS;  
}

long lde_size(List_DE* list){
    return list->list_size;
}

void lde_print(List_DE* list,void (*visit)(void* data)){
    Entry *it=list->head;
    printf("{");
    while(it!=NULL){
        (*visit)(it->data);
        it=it->next;
    }
    printf("}\n");
}
