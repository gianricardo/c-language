#include <stdio.h>

#define SIZE 5

int main () {
	
	unsigned int value[SIZE]  = {2, 4, 6, 8, 10}; //a
	
	unsigned int *vPtr = value; //b
	
	int i;
	
	printf("\nElementos do array value: \n"); //c
	for (i = 0; i < SIZE; i++) {
		printf("%d ", value[i]);
	}
	
	printf("\n\n%d ", vPtr); //d
	vPtr = &value[0];
	printf("\n%d ", vPtr);
	vPtr = &value;
	printf("\n%d\n\n", vPtr);
	
	for (i = 0; i < SIZE; i++) { //e
		printf("%d ", *vPtr);
		vPtr++;
	}
	
	printf("\n\n");
	
	for (i = 0; i < SIZE; i++) { //f
		printf("%d ", *(value + i));
	}
	
	printf("\n\n");
	
	vPtr = value;
	
	for (i = 0; i < SIZE; i++) { //g
		printf("%d ", vPtr[i]);
	}
	
	printf("\n\n");
	//h
	printf("values[4] = %d\n", value[4]);
	printf("*(values + 3)= %d\n", *(value + 4));
	printf("vPtr[4] = %d\n", vPtr[4]);
	printf("*(vPtr+4) = %d\n", *(vPtr+4));
	
	printf("*(vPtr+3) = %d\n", *(vPtr+3)); //i -> vPtr + 3 = 1002524 onde está o valor 8;
	
	printf("\n\n");
	
	printf("Se vPtr = &value[4]: \n");
	vPtr = &value[4];
	printf("*(vPtr-4) = %d\n", *(vPtr-4));//j -> 1002468 onde está a variavel 2;
	
	return 0;
}
