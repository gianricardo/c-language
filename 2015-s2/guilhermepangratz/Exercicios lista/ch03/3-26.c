#include <stdio.h>

int main () {
	
	int  i = 3;
	
	printf("%-2c\t%3s\t%3s\t%3s\n", 'A', "A+2", "A+4", "A+6");
	
	for (; i <= 15; i +=3) {
		printf("%-2d\t%-3d\t%-3d\t%-3d\n", i, i+2, i+4, i+6);
	}
	
	return 0;
}
