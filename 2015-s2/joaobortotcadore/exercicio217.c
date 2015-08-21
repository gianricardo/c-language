#include <stdio.h>

int main()
{
	/*Declarando algumas variaveis para ter especificadores de conversão para atender a questão b) */	
	int a=1;
	float b=2;
	double c=3;
	char d='4';
	printf("a)Sem especificadores de conversão: 1,2,3,4\n");
	/* Alguns especificadores de conversão:
	%d	Número decimal inteiro (int). Também pode ser usado %i como equivalente a %d.
	%u	Número decimal natural (unsigned int), ou seja, sem sinal.
	%o	Número inteiro representado na base octal. Exemplo: 41367 (corresponde ao decimal 17143).
	%x	Número inteiro representado na base hexadecimal. Exemplo: 42f7 (corresponde ao decimal 17143). Se usarmos %X, as letras serão maiúsculas: 42F7.
	%X	Hexadecimal com letras maiúsculas
	%f	Número decimal de ponto flutuante. No caso da função printf, devido às conversões implícitas da linguagem C, serve tanto para float como para double. No caso da função scanf, %f serve para float e %lf serve para double.
	%e	Número em notação científica, por exemplo 5.97e-12. Podemos usar %E para exibir o E maiúsculo (5.97E-12).
	%E	Número em notação científica com o "e"maiúsculo
	%g	Escolhe automaticamente o mais apropriado entre %f e %e. Novamente, podemos usar %G para escolher entre %f e %E.
	%p	Ponteiro: exibe o endereço de memória do ponteiro em notação hexadecimal.
	%c	Caractere: imprime o caractere que tem o código ASCII correspondente ao valor dado.
	%s	Sequência de caracteres (string, em inglês).
	%%	Imprime um %
	*/
	printf("b)Com especificadores de conversão: %d,%.1f,%.lf,%c\n",a,b,c,d); //%.'valor da precisão' em casas decimais, se deixar apenas o '.' ele imprime o float sem as casas decimais, ou a string com tamanho limitado
	printf("c)Utilizando quatro printf: ");
	printf("1,");
	printf("%.f,",b);
	printf("3,");
	printf("%c",d);
	
	return 0;
}
