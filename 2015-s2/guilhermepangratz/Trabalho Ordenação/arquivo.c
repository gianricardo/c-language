#include "arquivo.h"

FILE *abreArquivos(char *nome, char *modo){
	FILE *file;
	if ((file = fopen(nome, modo)) == NULL){
		printf("Não foi possivel abrir o arquivo \"%s\" no modo \"%s\"\n", nome, modo);
	}
	return file;
}

int contaLinhas(FILE *f){
	rewind(f);
	long int i = 0;
	char x;
	while (!feof(f)) {
		x = fgetc(f);
		if ( x == '\n') {
			i++;
		}
	}
	rewind(f);
	return i;
	
}

void escreverVetor(double *vetor, long int size, FILE *f) {
	long int i;
	for (i = 0; i  < size; i++) {
		fprintf(f, "%lf\n", vetor[i]);
	}
}