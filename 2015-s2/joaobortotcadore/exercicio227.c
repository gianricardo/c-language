//Desenhe um padrão tipo tabuleiro de xadrez utilizando instruções printf

#include <stdio.h>

int main(void)
{
	int i;
	for(i=0;i<8;i++)
	{
		if(i%2==0)
			printf("*   *   *   *   *   *   *   *\n");
		else
			printf("   *   *   *   *   *   *   *   *\n");
	}
}	
