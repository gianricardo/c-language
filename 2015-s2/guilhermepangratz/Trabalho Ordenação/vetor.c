#include "vetor.h"

double *criaVetor(int n) {
	double *vetor = (double *)calloc(n, sizeof(double));
	if (vetor == NULL) printf("ERRO AO ALOCAR MEMORIA!\n");
	return vetor;
}

double *importaValores(FILE *f, int n){
	double *vetor = criaVetor(n);
	int j, i = -10;
	
	while(!feof(f)){
		i += 10;
		fscanf(f, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n", &vetor[i], &vetor[i+1], &vetor[i+2], 
		&vetor[i+3], &vetor[i+4], &vetor[i+5], &vetor[i+6], &vetor[i+7], &vetor[i+8], 
		&vetor[i+9]);
	}
	
	return vetor;
}