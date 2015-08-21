//Diga a diferença entre os termos erro fatal e erro não-fatal. Por que você poderia desejar a ocorrência de um erro fatal em vez de um erro não-fatal?



#include <stdio.h>

int main(void)
{
	printf("Erro fatal:\nUm erro que faz com que o programa seja encerrado imediatamente sem ter sucesso na realização de sua tarefa.\n\n");
	printf("Erros não-fatais:\nPermitem que os programas sejam executados até o final, produzindo freqüentemente resultados incorretos.\n\n");
	printf("É preferível um erro fatal pelo fato de o programa nãõ funcionar, e não iludir o programador de que não existem erros, dificultando o debug pela inconsistência  do resultado. \n");
}	
