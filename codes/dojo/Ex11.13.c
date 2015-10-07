#include<stdio.h>
#include<string.h>

int salva_arquivo (FILE *arquivo, char *palavra);

//void combina_palavras(char *alfa,char *num)
const char ALFABETO[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y'};
    
void combine(char * digits, char* buf, int pos, FILE * file);

int main (void)
{
    
    FILE *arquivo;
    if((arquivo=fopen("out.txt","w"))==NULL)
    {
		printf("Erro de leitura de arquivo\n");
		exit(-1);
	}
    char telefone[10]; //8+1 pro '\0' + 1 pro -
    printf ("digite o número de seu telefone: ");
    scanf ("%s", telefone);
    
    char digitos[9];
	char buf[9];
    
    strncpy(digitos, telefone, 4);
    strncpy(digitos+4, telefone+5, 4);
    digitos[8] = '\0';

    printf("%s\n", digitos);

    combine(digitos, buf, 0, arquivo);

    fclose(arquivo);

}

void combine(char * digits, char* buf, int pos, FILE * file)
{
	int i;
	int iteracao = 3;
	
	if((int)digits[pos] == 0x37) //0x37 = 7 em ASCII
		iteracao=4;
	
	for(i = 0; i < iteracao; i++)
	{
		int alfaIndex = (digits[pos]) - '2'; //0x32 = 2 em ASCII
		
		int offset=0;
		if(alfaIndex > 5)
			offset = 1;
		
		buf[pos] = ALFABETO[alfaIndex * 3 + i + offset];
		if(pos == 7)
		{
			buf[8] = '\0';
			fprintf(file, "%s\n", buf);
		}
		else
		{	
			combine(digits, buf, pos+1, file);
		}
	}
}

/*
void combina_palavras(char *alfa,char *num){
    char aux[2];
    aux[1]='\0';
    int i,cont=0;
    aux[0]=num[0];
    while(cont<8){//Para percorrer os numeros do telefone
        for(i=cont //para percorrer a matriz do alfabeto
    }
    
}
*/

