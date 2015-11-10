#include "tda_ordenacao.h"



/**Funcao para ordenar o vetor**/


void ordena(float *vetor, int tamanho) {
     int i;
     float *b;
     float maior = vetor[0];
     int exp = 1;

     b = malloc(tamanho*sizeof(int));
     for(i=0;i<tamanho;i++) b[i] = 0;

     for (i = 0; i < tamanho; i++) {
         if (vetor[i] > maior)
     	    maior = vetor[i];
     }

     while (maior/exp > 0) {
         int balde[10] = { 0 };
     	for (i = 0; i < tamanho; i++)
     	    balde[(int)(vetor[i] / exp) % 10]++;
     	for (i = 1; i < 10; i++)
     	    balde[i] += balde[i - 1];
     	for (i = tamanho - 1; i >= 0; i--)
     	    b[--balde[(int)(vetor[i] / exp) % 10]] = vetor[i];
     	for (i = 0; i < tamanho; i++)
     	    vetor[i] = b[i];
     	exp *= 10;
     }
}
