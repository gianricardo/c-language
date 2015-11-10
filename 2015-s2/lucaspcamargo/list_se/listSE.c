#include "listSE_priv.h"
#include <stdlib.h>

//Função que cria uma entrada da lista simplesmente encadeada.
//HINT: adicionar um parametro para a proxima entrada da lista. 
Entry* make_entry(int nv, double nd){
    Entry* new_entry;
    new_entry = (Entry*) malloc(sizeof(Entry));
    if(new_entry != NULL){
        new_entry->campo1=nv;
        new_entry->campo2=nd;
        new_entry->next=NULL;
    }
    return new_entry;
}

List_SE* create_list_se(){
    List_SE* new_list;
    new_list = (List_SE*) malloc(sizeof(List_SE));
    if(new_list != NULL){
        new_list->size=0;
        new_list->head=NULL;
    }
    return new_list;
}

void destroy_list_se(List_SE** list){
    if(*list !=NULL){
        if((*list)->head!=NULL){
            Entry *mov=(*list)->head, *rmv;
            for(;mov!=NULL;){
                rmv=mov;
                mov=mov->next;
                free(rmv);
            }
            (*list)->head=NULL;            
        }
        free(*list);
        *list=NULL;
    }
}

//função que insere uma entrada no fim da lista
Error_code push_back(List_SE* list, int niv,double ndv){
    if(list==NULL) return INVALID;
    Entry* new_e;
    new_e=make_entry(niv, ndv);
    if(new_e == NULL) return BAD_ALLOCATION;
    if(list->head==NULL)return push_front(list,niv,ndv);
    Entry *iterator=list->head;
    //ir até o final da lista
    for(;iterator->next!=NULL;iterator=iterator->next){}
    //inserir como o pŕoximo do iterador
    iterator->next = new_e;
    //incrementa o tamanho da lista
    list->size+=1;
    return SUCCESS;
}

//função que insere o primeiro na lista
Error_code push_front(List_SE* list, int niv,double ndv){
    Entry* new_e;
    new_e=make_entry(niv, ndv);
    if(new_e == NULL) return BAD_ALLOCATION;
    if(list==NULL) return INVALID;
    //nova frente aponta para antiga frente
    new_e->next = list->head; 
    //descritor da lista aponta para a nova frente
    list->head = new_e;
    //incrementar o tamanho
    list->size += 1;
    return SUCCESS;
}

//função que retira a entrada do final da lista
Error_code pop_back(List_SE* list, int* niv,double* ndv){
    if(list==NULL) return INVALID;
    if(list->head == NULL) return UNDERFLOW;
    if(list->size <  2) return pop_front(list, niv,ndv);
    Entry *to_remove, *it=list->head;
    //procura o penultimo
    for(;(it->next)->next!=NULL;it=it->next){}
    //it é o penultimo, entao remove o próximo
    to_remove = it->next;
    //retiro a entrada da lista e decremento o tamanho da lista
    it->next = NULL;
    list->size-=1;
    //atribuir os valores da entrada
    if(niv!=NULL) *niv = to_remove->campo1;
    if(ndv!=NULL) *ndv = to_remove->campo2;
    //detruir entrada
    free(to_remove);
    return SUCCESS;
}

//Função que retira o primeiro da lista
Error_code pop_front(List_SE* list, int* niv,double* ndv){
    if(list==NULL) return INVALID;
    if(list->head == NULL) return UNDERFLOW;
    Entry* to_remove=list->head;
    //remover da lista
    list->head=to_remove->next;
    //decrementar quantidade
    list->size-=1;
    //atribuir os valores da entrada
    if(niv!=NULL) *niv = to_remove->campo1;
    if(ndv!=NULL) *ndv = to_remove->campo2;
    //detruir entrada
    free(to_remove);
    return SUCCESS;
}

//função que insere uma entrada na posicao especifica. 
//Se posicao <= 1 insere no inicio. 
//Se posicao >= tamanho insere no fim.
Error_code seek_insert(long position,List_SE* list, int niv,double ndv){
    if(list     == NULL      ) return INVALID;
    if(position <= 1         ) return push_front(list, niv, ndv);
    if(position >  list->size) return push_back(list, niv, ndv);
    Entry* new_e;
    new_e=make_entry(niv, ndv);
    if(new_e == NULL) return BAD_ALLOCATION;
    long i;
    Entry* it=list->head;
    for(i=0;i<position-1;i++) it=it->next;
    //1-ligar a entrada nova na lista no proximo do it 
    new_e->next=it->next;
    //2-ligar a posicao-1 na nova entrada
    it->next=new_e;
    //incrementar tamanho
    list->size+=1;
    return SUCCESS;
}

Error_code seek_destroy(long position,List_SE* list, int* niv,double* ndv){
    
}

Error_code seek_lse(long position,List_SE* list, int* niv,double* ndv){
    
}

long size_list_se(List_SE* list){
    return list->size;
}

