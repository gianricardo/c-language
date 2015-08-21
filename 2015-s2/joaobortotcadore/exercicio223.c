/*2.23 Maiores e menores inteiros. Escreva um programa que leia cinco inteiros e depois determine e imprima o maior e o menor inteiro no grupo. Use apenas as técnicas de programação que você aprendeu neste capítulo.*/

#include <stdio.h>

#define TAM 5

//prototipos da funçãõ
int retorna_maior(int v[], int tam); //funçãõ que retorna o maior valor de um vetor de inteiros
int retorna_menor(int v[], int tam); //funçãõ que retorna o menor valor de um vetor de inteiros

int main(void)
{
	int i, numeros_inteiros[TAM];
	for(i=0;i<TAM;i++) //trecho que faz a leitura dos valores inteiros e armazena no vetor
	{
		printf("Digite o num%d:\n",i);	
		scanf("%d", &numeros_inteiros[i]);
	}
	printf("Maior número: %d\n",retorna_maior(numeros_inteiros,TAM));
	printf("Menor número: %d\n",retorna_menor(numeros_inteiros,TAM));
}
//implementação das funções
int retorna_maior(int v[], int tam){
	tam=TAM;
	int i,maior=v[0]; 
	for(i=1;i<TAM;i++)
	{
		if(maior<v[i])
			maior=v[i];
	}
	return maior;
}
int retorna_menor(int v[], int tam)
{
	tam=TAM;
	int i,menor=v[0]; 
	for(i=1;i<TAM;i++)
	{
		if(menor>v[i])
			menor=v[i];
	}
	return menor;
}

