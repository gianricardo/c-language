#include <stdio.h>

int main() {

	int n;

	printf("Entre um inteiro de 5 digitos: ");
	scanf("%d", &n);

	while (n > 99999 || n < -99999) {
		printf("Entre um numero valido ");
		scanf("%d", &n);
	}

	printf("%3i", n/10000);
	n %= 10000;
	printf("%3i", n / 1000);
	n %= 1000;
	printf("%3i", n / 100);
	n %= 100;
	printf("%3i", n / 10);
	n %= 10;
	printf("%3i\n", n);


}
