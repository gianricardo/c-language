#include <stdio.h>

int main () {
	
	int x = 5, y = 8;
	
	if ( y == 8 ){
	if ( x == 5 )
	printf( "@@@@@\n" );
	else {
	printf( "#####\n" );
	}
	printf( "$$$$$\n" );
	printf( "&&&&&&\n" );
	}
	
	printf("\n");
	
	if ( y == 8 )
	if ( x == 5 )
	printf( "@@@@@\n" );
	else{
	printf( "#####\n" );
	printf( "$$$$$\n" );
	printf( "&&&&&&\n" );}
		
	printf("\n");
	
	if ( y == 8 )
	if ( x == 5 )
	printf( "@@@@@\n" );
	else{
	printf( "#####\n" );
	printf( "$$$$$\n" );}
	printf( "&&&&&&\n" );
		
	printf("\n");
	
	x = 5, y = 7;
	
	if ( y == 8 ){
	if ( x == 5 )
	printf( "@@@@@\n" );}
	else{
	printf( "#####\n" );
	printf( "$$$$$\n" );
	printf( "&&&&&&\n" );}
	
	return 0;
}
