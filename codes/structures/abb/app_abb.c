#include "abb.h"
#include "long_data.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
    ArvBB *arv= arv_criar(mostra_long,NULL,compara_long);
    long chave = 10;
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
    printf("\nBUSCA\n");
    if(arv_busca_bin(arv,&chave)){ printf("Encontrou %ld\n",chave);}else{printf("NAO encontrou %ld\n",chave);}
    chave=11;
    if(arv_busca_bin(arv,&chave)){ printf("Encontrou %ld\n",chave);}else{printf("NAO encontrou %ld\n",chave);}
    chave=7;
    if(arv_busca_bin(arv,&chave)){ printf("Encontrou %ld\n",chave);}else{printf("NAO encontrou %ld\n",chave);}
    chave=97;
    if(arv_busca_bin(arv,&chave)){ printf("Encontrou %ld\n",chave);}else{printf("NAO encontrou %ld\n",chave);}
    printf("\nREMOVE\n");
    printf("Tamanho: [%ld]\n",arv_tamanho(arv));
    printf("Remove: %s\n",codigo_erro_cstr(arv_remove2(arv,data[4])));
    printf("Tamanho: [%ld]\n",arv_tamanho(arv));
    printf("\n");
    arv_preordem(arv);
    chave=42;
    printf("Remove: %s\n",codigo_erro_cstr(arv_remove2(arv,&chave)));
    printf("Tamanho: [%ld]\n",arv_tamanho(arv));
//    arv_inordem(arv);
    printf("\n");
    arv_preordem(arv);
    arv_destruir(&arv);
    for(int i=0;i<10;i++){
        destroi_long(data[i]);
    }
    return 0;
}
