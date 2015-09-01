#include <stdio.h>

#define STUDENTS 3
#define EXAMS 4

int choice(int *escolha); /*Apresenta as opções ao usuario e pede que ele entre um inteiro para escolher qual deseja*/
void printArray(const int grades[][EXAMS], int pupils, int tests); /*Imprime toda a matriz de notas*/
void minimum(const int grades[][EXAMS], int pupils, int tests); /*Imprime a menor nota da turma*/
void maximum(const int grades[][EXAMS], int pupils, int tests); /*Imprime a maior nota da turma*/
void average(const int grades[][EXAMS], int pupils, int tests); /*Imprime a media das notas de toda a turma*/

int main () {
	
	/*O famoso array de ponteiros para funções*/
	void (*processGrades[4])(const int grades[][EXAMS], int pupils, int tests) = {printArray, minimum, maximum, average}; 
	
	/* initialize student grades for three students (rows) */
   const int studentGrades[ STUDENTS ][ EXAMS ] =  
      { { 77, 68, 86, 73 },
        { 96, 87, 89, 78 },
        { 70, 90, 86, 81 } };
	
	int escolha = 0;	
	
	while (escolha != 4){ /*Evita que o programa seja encerrado antes da escolha 4*/
		choice(&escolha);
		if (escolha >= 0 && escolha <= 4) { /*Não seria necessario se o enuciado não pedisse pela opção 4*/ 
			processGrades[escolha](studentGrades, STUDENTS, EXAMS);
		}		
	}
	
	return 0;
	
}/* End of main*/

int choice(int *escolha) {
	
	
	printf("\nDigite uma escolha:\n"
			"0 - Imprime o array de notas\n"
			"1 - Acha a menor nota\n"
			"2 - Acha a maior nota\n"
			"3 - Imprime a media de todos os testes para cada aluno\n"
			"4 - Encerra o programa\n"
			"\nESCOLHA: ");
	
	scanf("%i", &*escolha);
	printf("\n");
	
	
}/* End of function choice */

/* Print the array */
void printArray( const int grades[][EXAMS], int pupils, int tests )
{
   int i; /* student counter */
   int j; /* exam counter */

   /* output column heads */
   printf( "                [0]  [1]  [2]  [3]" );

   /* output grades in tabular format */
   for ( i = 0; i < pupils; i++ ) {

      /* output label for row */
      printf( "\nstudentGrades[%d] ", i );

      /* output grades for one student */
      for ( j = 0; j < tests; j++ ) {
         printf( "%-5d", grades[ i ][ j ] );
      } /* end inner for */
   } /* end outer for */
   
   printf("\n");
   
} /* end function printArray */



/* Find the minimum grade */
void minimum( const int grades[][EXAMS], int pupils, int tests )
{
   int i; /* student counter */
   int j; /* exam counter */
   int lowGrade = 100; /* initialize to highest possible grade */

   /* loop through rows of grades */
   for ( i = 0; i < pupils; i++ ) {

      /* loop through columns of grades */
      for ( j = 0; j < tests; j++ ) {

         if ( grades[ i ][ j ] < lowGrade ) {
            lowGrade = grades[ i ][ j ];
         } /* end if */
      } /* end inner for */
   } /* end outer for */
   
   printf("A menor nota: %i\n", lowGrade);

} /* end function minimum */



/* Find the maximum grade */
void maximum( const int grades[][EXAMS], int pupils, int tests )
{
   int i; /* student counter */
   int j; /* exam counter */
   int highGrade = 0; /* initialize to lowest possible grade */

   /* loop through rows of grades */
   for ( i = 0; i < pupils; i++ ) {

      /* loop through columns of grades */
      for ( j = 0; j < tests; j++ ) {

         if ( grades[ i ][ j ] > highGrade ) {
            highGrade = grades[ i ][ j ];
         } /* end if */
      } /* end inner for */
   } /* end outer for */
   
   printf("A maior nota: %i\n", highGrade);

} /* end function maximum */




/* Determine the average grade for a particular student */
void average( const int grades[][EXAMS], int pupils, int tests )
{
   int i; /*student counter*/	
   int j; /* exam counter */
   int total = 0; /* sum of test grades */

   /* total all grades for one student */
	for ( i = 0; i < pupils; i++ ) {
		for (j = 0; j < tests; j++) {
			total += grades[i][ j ];
		}
   } /* end for */

	printf("Media da turma: %f\n", 1.f*total/(pupils*tests) );

} /* end function average */



