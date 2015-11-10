#include "sort.h"


void quicksort(double *vetor, long int esq, long int dir) {
	
	long int i = esq;
	long int j = dir;
    double meio, hold;
	
	meio = vetor[(esq+dir)/2]; /**O pivo vai ser o elemento do meio do array*/
	
	while (i <= j) {
		while (vetor[i] < meio && i < dir) i++;
		while (vetor[j] > meio && j > esq) j--;
		if (i<=j) {
			hold = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = hold;
			i++;
			j--;
		}
	}
	
	if ( j > esq ) quicksort(vetor, esq, j);
	if ( i < dir ) quicksort(vetor, i, dir);
		
}