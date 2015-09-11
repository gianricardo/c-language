#include <stdio.h>

int main () {
	
	int i = 2;
	
	while (1) {
		printf("%12d\n", i);
		i *= 2;
	}
	
	return 0;
}

// o programa rapidamente estoura a variavel i e passa a exibir sempre o mesmo fvalor 0;
