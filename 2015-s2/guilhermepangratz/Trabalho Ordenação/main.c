#include <time.h>
#include "arquivo.h"
#include "vetor.h"
#include "sort.h"

int main(int argc, char *argv[]) {
	
	time_t t2 = time(NULL);
	
	if (argc != 3) {
		printf("./%s %s %s\n", argv[0], "arq_entrada", "arq_saida");
		return 0;
	}
	
	FILE *fEntrada, *fSaida;
	double *vetor;
	long int linhas, nmax;
		
	long int n = (sizeof(double) * 10 + 11); /**Tamanho maximo das linhas do arquivo 
	(tamanho do double mais 10 espaços + \n)*/
	
	/**Abrir o arquivo de saida logo no inicio evida que realizemos trabalho 
	computacional sendo que depois não poderemos salar o resultado da forma desejada*/
	fEntrada = abreArquivos(argv[1], "r");
	fSaida = abreArquivos(argv[2], "w");
	if(fEntrada == NULL || fSaida == NULL) return 0;
	
	printf("ARQUIVOS OK!\nLENDO DE %s ...\n", argv[1]);
		
	/**conta o numero de linhas do arquivo para definir o tamanho do array para
	importação dos valores*/
	linhas = contaLinhas(fEntrada);
		
	/**Já que teremos 10 num por linha podemos calcular a 
	quantidade total de valores:*/
	nmax = linhas * 10;
	
	vetor = importaValores(fEntrada, nmax);
		
	fclose(fEntrada);
	
	printf("VALORES ADQUIRIDOS!\nORDENANDO...\n");
	
	quicksort(vetor, 0, nmax - 1);
	
	printf("VALORES ORDENADOS!\nESCREVENDO EM %s ...\n", argv[2]);
	
	escreverVetor(vetor, nmax, fSaida);
	
	fclose(fSaida);
	
	printf("CONCLUIDO!\n");
	
	time_t t1 = time(NULL);
	
	printf("Tempo de execucao: %lf\n", difftime(t1,t2));
	
	
	return 0;
}