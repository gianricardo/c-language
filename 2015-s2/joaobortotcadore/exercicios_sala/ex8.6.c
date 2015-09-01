#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
	char sentence[100];
	int i=0;

	printf("insira a sentenca a ser convertida\n");
	fgets(sentence,100,stdin);

	for(;sentence[i]!='\0';i++){
		printf("%c", toupper(sentence[i]));

	}
	printf("\n");
	for(i=0;sentence[i]!='\0';i++){
		printf("%c", tolower(sentence[i]));
	

	}
	printf("\n");
	return 0;



}
