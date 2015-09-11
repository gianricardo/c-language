#include <stdio.h>

unsigned compactaCaracteres (char char1, char char2);

unsigned main () {
	
	char char1, char2;
	unsigned compactado;
	
	printf("Informe 2 caracteres: ");
	scanf("%c%c", &char1, &char2);
	
	compactado = compactaCaracteres(char1, char2);
	
	printf("char1: %d - char2: %d - compactado: %d\n\n", char1, char2, compactado);
	
	return 0;
}

unsigned compactaCaracteres (char char1, char char2) {
	
	unsigned unit;
	
	unit = char1 << 8;
	unit |= char2;
	
	return unit;
	
	
}
