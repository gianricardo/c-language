//Lê 5 inteiros e mostra o maior e o menor

#include <stdio.h>

int main () {
	
	int a,b,c,d,e;
	
	printf("entre 5 inteiros: ");
	scanf("%i%i%i%i%i", &a, &b, &c, &d, &e);
	
	if ( a > b && a > c && a > d && a > e ) {
		printf("\nMaior: %i", a);
	} else if ( b > c && b > d && b > e ) {
		printf("\nMaior: %i", b);
	} else if ( c > d && c > e ) {
		printf("\nMaior: %i", c);
	} else if ( d > e ) {
		printf("\nMaior: %i", d);
	} else {
		printf("\nMaior: %i", e);
	}
	
	if ( a < b && a < c && a < d && a < e ) {
		printf("\nMenor: %i", a);
	} else if ( b < c && b < d && b < e ) {
		printf("\nMenor: %i", b);
	} else if ( c < d && c < e ) {
		printf("\nMenor: %i", c);
	} else if ( d < e ) {
		printf("\nMenor: %i", d);
	} else {
		printf("\nMenor: %i", e);
	}
	
}
