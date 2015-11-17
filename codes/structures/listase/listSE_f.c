#include "listSE_f_priv.h"
#include <stdlib.h>
#include <stdio.h>

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

List_SE_f* lsef_create(){
    List_SE_f* new_list;
    new_list = (List_SE_f*) malloc(sizeof(List_SE_f));
    if(new_list != NULL){
        new_list->size=0;
        new_list->head=NULL;
        new_list->tail=NULL;
    }
    return new_list;
}

void lsef_destroy(List_SE_f** list){
    if(*list !=NULL){
        if((*list)->head!=NULL){
            Entry *mov=(*list)->head, *rmv;
            for(;mov!=NULL;){
                rmv=mov;
                mov=mov->next;
                free(rmv);
            }
            (*list)->head=NULL; 
            (*list)->tail=NULL;           
        }
        free(*list);
        *list=NULL;
    }
}

//busca uma posição válida na lista
Entry* get_position(List_SE_f* list,long pos){
    long i;
    Entry* it=list->head;
    //move o iterador para a posição desejada
    for(i=1;i<pos;i++){ it=it->next;}
    return it;
}

//função que insere uma entrada no fim da lista
Error_code lsef_push_back(List_SE_f* list, int niv,double ndv){
    if(list==NULL) return INVALID;
    Entry* new_e;
    new_e=make_entry(niv, ndv);
    if(new_e == NULL) return BAD_ALLOCATION;
    if(list->head==NULL)return lsef_push_front(list,niv,ndv);
    //ir até o final da lista
    Entry *iterator=list->tail;
    //inserir como o próximo do iterador
    iterator->next = new_e;
    //atualizar a nova cauda
    list->tail = new_e;
    //incrementa o tamanho da lista
    list->size+=1;
    return SUCCESS;
}

//função que insere o primeiro na lista
Error_code lsef_push_front(List_SE_f* list, int niv,double ndv){
    Entry* new_e;
    new_e=make_entry(niv, ndv);
    if(new_e == NULL) return BAD_ALLOCATION;
    if(list==NULL) return INVALID;
    //nova frente aponta para antiga frente
    new_e->next = list->head; 
    //se for a primeira inserção, atualizar a cauda
    if(list->head==NULL){   
        list->tail = new_e;
    }
    //descritor da lista aponta para a nova frente
    list->head = new_e;
    //incrementar o tamanho
    list->size += 1;
    return SUCCESS;
}

//função para remover uma entrada da lista
void remove_entry(List_SE_f* list,Entry **to_remove,int* nv, double* nd){
    //decrementar o tamanho da lista
    list->size-=1;
    //atribuir os valores da entrada
    if(nv!=NULL) *nv = (*to_remove)->campo1;
    if(nd!=NULL) *nd = (*to_remove)->campo2;
    //detruir entrada
    free(*to_remove);
    *to_remove=NULL;
}

//função que retira a entrada do final da lista
Error_code lsef_pop_back(List_SE_f* list, int* niv,double* ndv){
    if(list==NULL) return INVALID;
    if(list->head == NULL) return UNDERFLOW;
    if(list->size <  2) return lsef_pop_front(list, niv,ndv);
    Entry *to_remove, *it;
    //procura o penultimo
    it=get_position(list,list->size-1);
    //it é o penultimo
    to_remove = it->next;
    //retiro a entrada da lista e atualiza a cauda
    it->next = NULL;
    list->tail=it;
    //remove o último
    remove_entry(list,&to_remove,niv,ndv);
    return SUCCESS;
}

//Função que retira o primeiro da lista
Error_code lsef_pop_front(List_SE_f* list, int* niv,double* ndv){
    if(list==NULL) return INVALID;
    if(list->head == NULL) return UNDERFLOW;
    Entry *to_remove=list->head;
    //remover da lista
    list->head=to_remove->next;
    if(list->head==NULL){
        list->tail=NULL;
    }
    remove_entry(list,&to_remove,niv,ndv);
    return SUCCESS;
}

//função que insere uma entrada na posicao especifica. 
//Se posicao <= 1 insere no inicio. 
//Se posicao >= tamanho insere no fim.
Error_code lsef_seek_insert(long position,List_SE_f* list, int niv,double ndv){
    if(list     == NULL      ) return INVALID;
    if(position <= 1         ) return lsef_push_front(list, niv, ndv);
    if(position >  list->size) return lsef_push_back(list, niv, ndv);
    Entry* new_e;
    new_e=make_entry(niv, ndv);
    if(new_e == NULL) return BAD_ALLOCATION;
    Entry* it=get_position(list,position-1);
    //1-ligar a entrada nova na lista no proximo do it 
    new_e->next=it->next;
    //2-ligar a posicao-1 na nova entrada
    it->next=new_e;
    //incrementar tamanho
    list->size+=1;
    return SUCCESS;
}

//Função que remove a n-esima posição válida na lista
Error_code lsef_seek_destroy(long position,List_SE_f* list, int* niv,double* ndv){
    if(list == NULL) return INVALID;
    if(position < 0 || position > list->size) return INVALID_POSITION;
    if(position <= 1         ) return lsef_pop_front(list, niv, ndv);
    if(position ==  list->size) return lsef_pop_back(list, niv, ndv);    
    Entry* it, *to_remove, *following;
    //move o iterador para a posição anterior à entrada a ser removida
    it=get_position(list,position-1);
    to_remove = it->next;//entrada a ser removida
    following = to_remove->next;//o seguinte a entrada a ser removida
    //retirar a entrada da lista
    it->next=following;
    remove_entry(list,&to_remove,niv,ndv);
    return SUCCESS;
}

Error_code lsef_seek(long position,List_SE_f* list, int* niv,double* ndv){
    if(list == NULL) return INVALID;
    if(position < 0 || position > list->size) return INVALID_POSITION;
    Entry* it=get_position(list,position);
    //atribuir os valores da entrada
    if(niv!=NULL) *niv = it->campo1;
    if(ndv!=NULL) *ndv = it->campo2;
    return SUCCESS;    
}

long lsef_size(List_SE_f* list){
    return list->size;
}

void lsef_print(List_SE_f* list, void (*visit)(int intg,double doble)){
    Entry *it=list->head;
    printf("{");
    while(it!=NULL){
        (*visit)(it->campo1,it->campo2);
        it=it->next;
    }
    printf("}\n");
}

