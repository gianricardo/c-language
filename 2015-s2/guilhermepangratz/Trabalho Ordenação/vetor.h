#include "arquivo.h" /**Incluido aqui o arquivo.h pelos headers que estão lá*/

double *criaVetor(int n); /**Aloca memoria para um vetor de n floats e retorna um ponteiro para o local do vetor*/
double *importaValores(FILE *f, int n);/**Coloca os valores do arquivo com 10 numeros por linha em um vetor de até n elementos*/
