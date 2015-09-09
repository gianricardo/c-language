#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

// os dois tipos abaixos foram retirados do openepos - especificação de cpu
typedef unsigned long Reg32;

typedef union {
	struct {
	    Reg32 version_id:8;
	    Reg32 num_counters:8;
	    Reg32 bit_width:8;
	    Reg32 mask_length:8;
	} split;
	Reg32 full;
    } cpu_reg;
    
void displayBits( unsigned value )
{ 
   unsigned c; 
   unsigned displayMask = 1 << 31;
   printf( "%10u = ", value );
   for ( c = 1; c <= 32; c++ ) { 
      putchar( value & displayMask ? '1' : '0' );
      value <<= 1; 
      if ( c % 8 == 0 ) { 
         putchar( ' ' );
      }
   } 
   putchar( '\n' );
} 
    
int main( void )
{ 
   srand( time( NULL ) );
   int num =1;
   
   cpu_reg registro;
   
   while(num != 0){
     registro.full = ( rand() % UINT_MAX );
     printf("\t\tNumero: %32u\n", registro.full );
     displayBits( registro.full );
     displayBits( registro.split.version_id );
     displayBits( registro.split.num_counters );
     displayBits( registro.split.bit_width );
     displayBits( registro.split.mask_length );
     printf("Deve continuar a gerar números? (0 para encerrar):  ");
     scanf("%d",&num);
   }
   
   return 0;
}
   