#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *abreArquivos(char *nome, char *modo); /**Abre os arquivos de entrada e saida. Retorna 1 em caso de sucesso, e 0 em caso de falha*/
int contaLinhas(FILE *f); /**Retorna a quantidade de linhas de um arquivo. Posiciona o cursor no inicio do arquivo antes e depois da contagem*/
void escreverVetor(double *vetor, long int size, FILE *f); /**Escreve os size elementos do vetor no arquivo f, um por linha*/
