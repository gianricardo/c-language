#include "tda_ordenacao.h"
#include "tda_ordenacao_funcoes.h"
#include "tda_ordena.h"
#include <time.h>

int main(int argc, char *argv[]){

    FILE *arquivo_entrada;
    FILE *arquivo_ordenado;
    /**Abertura de arquivo pela linha de comando
     **/
        if(argc != 3)
    {
        printf("./%s arquivo_entrada.txt arquivo_saida.txt",argv[0]);
        exit(-1);
    }

    if((arquivo_entrada = fopen(argv[1],"r+")) == NULL)
    {
        printf("Erro na leitura do arquivo de entrada.");
        exit(-1);
    }
    if((arquivo_ordenado = fopen(argv[2],"w")) == NULL)
    {
        printf("Erro na leitura do arquivo ordenado.");
        exit(-1);
    }

    int i=0,j=0;

    /** Abrir o arquivo de entrada apenas como leitura\n
     ** - Testa se o arquivo abre corretamente\n
     **/

    testa_arquivo(arquivo_entrada);

     /** Abre o arquivo ordenado apenas como escrita\n
     ** - Testa se o arquivo abre corretamente\n
     **/

    testa_arquivo(arquivo_ordenado);

    /** Chama a funcao que encontra o numero de valores presentes no arquivo\n
     ** - Salva em uma variavel
     **/

    i = tam_arquivo(arquivo_entrada);

    /**Cria de um ponteiro para armazenar os valores presentes no arquivo de entrada\n
     **- Aloca memoria suficiente para criar um vetor de float da quantidade de variaveis presentes no arquivo de entrada\n
     **- Checa se a memoria alocada e suficiente\n
     **/

    float *v;
    v = malloc (i*sizeof(float));
    testa_vetor(v);

    /**Chama a funcao para ler o arquivo\n
     **- Os valores do arquivo sao salvos no ponteiro v\n
     **- Retorna o tamanho do vetor\n
     **/

    j = le_arquivo(arquivo_entrada, v);

    /**Funcao para ordenacao presente aqui\n
     **\tRadixSort\n
     **- Recebe o ponteiro do vetor com os valores e o tamanho dele\n
     **- Vetor e ordenado dentro da funcao\n
     **/

    ordena(v,j);

    /**Chama a funcao que escreve os valores ordenados\n
     **- Recebe o arquivo de saida, o vetor do ponteiro, e o tamanho do vetor
     **/

    imprime_arquivo(arquivo_ordenado, v, j);

    /**Chama a funcao que libera a memoria alocadapara o vetor\n
     **- Recebe o ponteiro do vetor\n
     **- Libera a memoria alocada\n
     **/

    libera_vetor(v);


    /**Fecha os arquivos\n
     **/

    fclose(arquivo_entrada);
    fclose(arquivo_ordenado);

    return 0;
}
