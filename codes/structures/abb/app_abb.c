#include "abb.h"
#include "long_data.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
    ArvBB *arv= arv_criar(mostra_long,NULL,compara_long);
    //int data[]={32,16,34,1,87,13,7,18,14,19,23,24,41,5,53};
    long* data[]={crial(42),crial(11),crial(28),crial(15),
                  crial(86),crial(53),crial(97),crial(63),
                  crial(35),crial(55)};
    for(int i=0;i<10;i++){
        arv_insere(arv,data[i]);
    }
    arv_inordem(arv);
    printf("\n");
    arv_preordem(arv);
    printf("\nREMOVE\n");
    arv_remove(arv,data[4]);
    arv_inordem(arv);
    printf("\n");
    arv_preordem(arv);
    arv_destruir(&arv);
    for(int i=0;i<10;i++){
        destroi_long(data[i]);
    }
    return 0;
}
