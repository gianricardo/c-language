#include <stdio.h>

int main(void){

	int N, N1, N2, N3;

	printf("N\t N*10\t N*100\t N*1000\n\n");

	for (N = 1; N <= 10; N++){

		N1 = N * 10;
		N2 = N * 100;
		N3 = N * 1000;

		printf("%d\t %d\t %d\t %d\n", N, N1, N2, N3);
	}

	return 0;
}