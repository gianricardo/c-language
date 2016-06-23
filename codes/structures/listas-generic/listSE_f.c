#include "listSE_f_priv.h"
#include <stdlib.h>
#include <stdio.h>

//Função que cria uma entrada da lista simplesmente encadeada.
//HINT: adicionar um parametro para a proxima entrada da lista. 
Entry* make_entry(void* data){
    Entry* new_entry;
    new_entry = (Entry*) malloc(sizeof(Entry));
    if(new_entry != NULL){
        new_entry->info=data;
        new_entry->next=NULL;
    }
    return new_entry;
}

Lista_S* listas_create(void (*destroi)(void *data)){
    Lista_S* new_list;
    new_list = (Lista_S*) malloc(sizeof(Lista_S));
    if(new_list != NULL){
        new_list->size=0;
        new_list->head=NULL;
        new_list->tail=NULL;
        new_list->destroi=destroi;
    }
    return new_list;
}

void listas_destroy(Lista_S** list){
    if(*list !=NULL){
        if((*list)->head!=NULL){
            Entry *mov=(*list)->head, *rmv;
            for(;mov!=NULL;){
                rmv=mov;
                mov=mov->next;
                if((*list)->destroi!=NULL){
                    (*list)->destroi(rmv->info);
                }
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
Entry* get_position(Lista_S* list,long pos){
    long i;
    Entry* it=list->head;
    //move o iterador para a posição desejada
    for(i=1;i<pos;i++){ it=it->next;}
    return it;
}

//função que insere uma entrada no fim da lista
codigo_erro listas_push_back(Lista_S* list, void* data){
    if(list==NULL) { return (INVALIDO); }
    Entry* new_e;
    new_e=make_entry(data);
    if(new_e == NULL) { return (BAD_ALLOCATION); }
    if(list->head==NULL)return listas_push_front(list,data);
    //ir até o final da lista
    Entry *iterator=list->tail;
    //inserir como o próximo do iterador
    iterator->next = new_e;
    //atualizar a nova cauda
    list->tail = new_e;
    //incrementa o tamanho da lista
    list->size+=1;
    return (SUCESSO);
}

//função que insere o primeiro na lista
codigo_erro listas_push_front(Lista_S* list,  void* data){
    Entry* new_e;
    new_e=make_entry(data);
    if(new_e == NULL) return BAD_ALLOCATION;
    if(list==NULL) return (INVALIDO);
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
    return (SUCESSO);
}

//função para remover uma entrada da lista
void remove_entry(Lista_S* list,Entry **to_remove,void** data){
    //decrementar o tamanho da lista
    list->size-=1;
    //atribuir os valores da entrada
    if((data)!=NULL) (*data) = (*to_remove)->info;
    //detruir entrada
    free(*to_remove);
    *to_remove=NULL;
}

//função que retira a entrada do final da lista
codigo_erro listas_pop_back(Lista_S* list, void** data){
    if(list==NULL) return INVALIDO;
    if(list->head == NULL) return UNDERFLOW;
    if(list->size <  2) return listas_pop_front(list, data);
    Entry *to_remove, *it;
    //procura o penultimo
    it=get_position(list,list->size-1);
    //it é o penultimo
    to_remove = it->next;
    //retiro a entrada da lista e atualiza a cauda
    it->next = NULL;
    list->tail=it;
    //remove o último
    remove_entry(list,&to_remove,data);
    return SUCESSO;
}

//Função que retira o primeiro da lista
codigo_erro listas_pop_front(Lista_S* list, void** data){
    if(list==NULL) return INVALIDO;
    if(list->head == NULL) return UNDERFLOW;
    Entry *to_remove=list->head;
    //remover da lista
    list->head=to_remove->next;
    if(list->head==NULL){
        list->tail=NULL;
    }
    remove_entry(list,&to_remove,data);
    return SUCESSO;
}

//função que insere uma entrada na posicao especifica. 
//Se posicao <= 1 insere no inicio. 
//Se posicao >= tamanho insere no fim.
codigo_erro listas_seek_insert(long position,Lista_S* list, void* data){
    if(list     == NULL      ) return INVALIDO;
    if(position <= 1         ) return listas_push_front(list, data);
    if(position >  list->size) return listas_push_back(list, data);
    Entry* new_e;
    new_e=make_entry(data);
    if(new_e == NULL) return BAD_ALLOCATION;
    Entry* it=get_position(list,position-1);
    //1-ligar a entrada nova na lista no proximo do it 
    new_e->next=it->next;
    //2-ligar a posicao-1 na nova entrada
    it->next=new_e;
    //incrementar tamanho
    list->size+=1;
    return SUCESSO;
}

//Função que remove a n-esima posição válida na lista
codigo_erro listas_seek_destroy(long position,Lista_S* list, void** data){
    if(list == NULL) return INVALIDO;
    if(position < 0 || position > list->size) return POSICAO_INVALIDA;
    if(position <= 1         ) return listas_pop_front(list, data);
    if(position ==  list->size) return listas_pop_back(list, data);
    Entry* it, *to_remove, *following;
    //move o iterador para a posição anterior à entrada a ser removida
    it=get_position(list,position-1);
    to_remove = it->next;//entrada a ser removida
    following = to_remove->next;//o seguinte a entrada a ser removida
    //retirar a entrada da lista
    it->next=following;
    remove_entry(list,&to_remove,data);
    return SUCESSO;
}

codigo_erro listas_seek(Lista_S* list,long position,void **data){
    if(list == NULL) return INVALIDO;
    if(position < 0 || position > list->size) return POSICAO_INVALIDA;
    Entry* it=get_position(list,position);
    //atribuir os valores da entrada
    if((*data)!=NULL) (*data) = it->info;
    return SUCESSO;
}

long listas_size(Lista_S* list){
    return list->size;
}

void listas_print(Lista_S* list, void (*visit)(void* data)){
    Entry *it=list->head;
    printf("{");
    while(it!=NULL){
        (*visit)(it->info);
        it=it->next;
    }
    printf("}\n");
}

bool        listas_empty(const Lista_S* list){
    return (list->size==0 && list->head==NULL);
}
