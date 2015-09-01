//Verificar o que o programa imprime

#include <stdio.h>

int main () {
	
	int x = 1, total = 0, y;
	
	while ( x <= 10 ) {
		y = x * x;
		printf( "%d\n", y );
		total += y;
		++x;
	}
	
	printf("Total is %d\n", total);
	return 0;
	
}

//O laço while vai variar o valor de x de 1 até 10, devido ao incremento no final do laço
//cada vez que o laço for executado ele vai exibir o quadrado do valor de x, e vai acrescentar
//o valor do quadrado a uma variavel que vai armazenar a soma desses valores...
//no final teremos na tela os numeros de 1 a 10 e os seus quadrados, e então a doma desses quadrados
