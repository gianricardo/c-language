#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>


const char ALFABETO[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y'};
    
void combine(char * digits, char* buf, int pos, int size);

int main (void)
{
    
    srand( (int) time(0) );

    for( int i = 4; i <= 20; i++ )
    {
        char digitos[i+1];
        char buf[i+1];
                
        for( int j = 0; j < i; j++ )
        {   
            digitos[j] = (char)('2' + (rand() % 8));
        }
        
        digitos[i] = '\0';
        
        time_t prev;
        time(&prev);
        
        combine(digitos, buf, 0, i );
        
        printf("%d digits in %.2lfs\n", i, difftime(time(0), prev));
    }    
    

}

void combine(char * digits, char* buf, int pos, int size, FILE * file)
{
	int i;
	int iteracao = 3;
	
	if((int)digits[pos] == '7') //0x37 = 7 em ASCII
		iteracao=4;
	
	for(i = 0; i < iteracao; i++)
	{
		int alfaIndex = (digits[pos]) - '2'; //0x32 = 2 em ASCII
		
		int offset=0;
		if(alfaIndex > 5)
			offset = 1;
		
		buf[pos] = ALFABETO[alfaIndex * 3 + i + offset];
		if(pos == (size - 1))
		{
			buf[size] = '\0';
			// you could print it or something here
		}
		else
		{	
			combine(digits, buf, pos+1, size);
		}
	}
}
