#include <stdio.h>

double power(double, int);

int main () {
	
	double x;
	int y;
	printf("base x (x^y): ");
	scanf("%lf", &x);
	printf("expoente inteiro positivo y (x^y): ");
	scanf("%d", &y);	
	
	printf(" x ^ y : %lf\n", power(x, y));
	
	return 0;
}

double power(double base, int expoente) {
	
	double pot;
	
	if ( expoente == 0) {
		return 1;
	} else if ( expoente == 1) {
		return base;
	} else {
		pot = base * power(base, expoente - 1);
		return pot;
	}
}
