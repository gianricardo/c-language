#include <stdio.h>

int main () {
	
	int i , j;
	
	for (i = 0; i < 10; i++) {
		for ( j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
	
	printf("\n");
	
	for (i = 10; i > 0; i--) {
		for ( j = i; j > 0; j--) {
			printf("*");
		}
		printf("\n");
	}
	
	printf("\n");
	
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if ( j < i ) {
				printf(" ");
			} else {
				printf("*");
			}
		}
		printf("\n");
	}
	
	printf("\n");
	
	for (i = 10; i > 0; i--) {
		for (j = 0; j < 10; j++) {
			if ( j < i ) {
				printf(" ");
			} else {
				printf("*");
			}
		}
		printf("\n");
	}
	
	printf("\n");
	
	return 0;
}
