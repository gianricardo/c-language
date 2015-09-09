#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( void )
{ 
   srand( time( NULL ) );
   int num =1;
   
   while(num != 0){
     printf("\t\tEXERCICIO ESCOLHIDO: %d\n", ( 1 + ( rand() % 164 )));
     printf("Deve continuar a gerar números? (0 para encerrar):  ");
     scanf("%d",&num);
   }
   
   return 0;
}
   