#ifndef TDA_ORDENACAO_H_INCLUDED
#define TDA_ORDENACAO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**Pre condicao
 **Receber um arquivo valido
 **
 **Pos condicao
 **Se houver erro na abertura do arquivo, sair do programa
 **/
void testa_arquivo(FILE *arquivo);
/**Pre condicao
 **Receber um arquivo valido
 **
 **Pos condicao
 **Retornar a quantidade de variaveis presente no arquivo
 **/
int tam_arquivo(FILE *arquivo);
/**Pre condicao
 **Receber um ponteiro valido com valores de ponto flutuante
 **
 **Pos condicao
 **Se o tamanho do arquivo for invalido, sair do programa
 **/
void testa_vetor(float *vetor);
/**Pre condicao
 **Receber um arquivo valido e um ponteiro valido com valores de ponto flutuante
 **
 **Pos condicao
 **Salvar todos os valores presentes no arquivo, no ponteiro do vetor enviado
 **/
int le_arquivo(FILE *arquivo, float *vetor);
/**Pre condicao
 **Receber um arquivo valido e um ponteiro valido com valores de ponto flutuante
 **
 **Pos condicao
 **Salvar todos os valores presentes no ponteiro do vetor em um arquivo, linha por linha
 **/
void imprime_arquivo(FILE *arquivo, float *vetor, int pos);
/**
 **Pre condicao
 **Receber um ponteiro de um vetor com valores em ponto flutuante
 **
 **Pos condicao
 **Liberar a memoria alocada ao ponteiro
 **/
void libera_vetor(float *vetor);
/**
 **Pre condicao
 **Receber um ponteiro de um vetor com valores em ponto flutuante e um inteiro com o tamanho do vetor
 **
 **Pos condicao
 **Salvar o vetor de forma ordenada e crescente
 **/
void ordena(float *vetor, int tamanho);




#endif // TDA_ORDENACAO_H_INCLUDED
