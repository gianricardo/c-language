#include "tda_ordenacao.h"


/** Funcao para testar se o arquivo abre corretamente
 ** Deve receber um arquivo valido
 ** Nao retorna valor nenhum
 ** Apenas sai do programa (exit(-1)) se ocorrer algum erro ao abrir o programa
 **/

void testa_arquivo(FILE *arquivo){

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo de entrada.\n");
        exit(-1);
    }

}

/** Funcao para definir a quantidade de valores double/float estão presentes no arquivo **/

int tam_arquivo(FILE *arquivo){

    int i=0,aux;
    //fseek (arquivo , 0 , SEEK_END);
    //while((fscanf(arquivo, "%n", &i))!=EOF){
     //   printf("%d", i);
    //}
    while((fscanf(arquivo, "%f\n",&aux))!=EOF){
      i++;
    }
    rewind(arquivo);


    return i;
}

/** Funcao para checar se o ponteiro alocado não excede o valor maximo de memoria **/

void testa_vetor(float *v){

    if (v == NULL)  {
        printf("Memória insuficiente!\n");
        exit(1);
    }
}

/** Funcao para ler o arquivo e salvar as variaveis no ponteiro **/

int le_arquivo(FILE *arquivo, float *vetor){

    int j=0;
    while((fscanf(arquivo, "%f\n", &vetor[j]))!=EOF){
           // printf("%f\n", vetor[j]);
            j++;
    }
    return j;


}

/**Funcao para imprimir o vetor ordenado no arquivo**/

void imprime_arquivo(FILE *arquivo, float *vetor, int pos){
    int i;
    for(i=0 ;i<pos;i++){
        fprintf(arquivo,"%f\n", vetor[i]);
    }
}
/**Funcao para liberar a memoria alocada do vetor**/

void libera_vetor(float *vetor){
    free(vetor);
    vetor = NULL;
}
