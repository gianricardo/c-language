/* Fig. 6.22: fig06_22.c
   Double-subscripted array example */
#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

/* function prototypes */
void minimum(const int grades[][ EXAMS ], int pupils, int tests );
void maximum( const int grades[][ EXAMS ], int pupils, int tests );
void average( const int grades[][ EXAMS ], int pupils, int tests  );
void printArray( const int grades[][ EXAMS ], int pupils, int tests );

/* function main begins program execution */
int main( void )
{
   
   void (*processGrades[4])( const int grades[][ EXAMS ], int pupils, int tests  )={printArray,minimum,maximum,average};
   int indexMenu=4;
   /* initialize student grades for three students (rows) */
   const int studentGrades[ STUDENTS ][ EXAMS ] =  
      { { 77, 68, 86, 73 },
        { 96, 87, 89, 78 },
        { 70, 90, 86, 81 } };
	printf("Digite uma escolha: \n  0 Imprime o array de notas\n  1 Achaa menor nota\n  2 Acha a maior nota\n  3 Imprime a media de todos os testes para cada aluno\n  4 Encerra o programa\n\n");
	scanf("%d",&indexMenu);
	if(indexMenu<4){
	(*processGrades[indexMenu])( studentGrades, STUDENTS, EXAMS );
	
	}
	
   while((indexMenu>=0) && (indexMenu<4)) {
   	printf("Digite uma escolha: \n  0 Imprime o array de notas\n  1 Achaa menor nota\n  2 Acha a maior nota\n  3 Imprime a media de todos os testes para cada aluno\n  4 Encerra o programa\n\n");
	scanf("%d",&indexMenu);
   if(indexMenu<4){
	(*processGrades[indexMenu])( studentGrades, STUDENTS, EXAMS );
	
	}  
	};
   /* calculate average grade for each student */
    
      
   /* end for */

   return 0; /* indicates successful termination */
} /* end main */

/* Find the minimum grade */
void minimum( const int grades[][ EXAMS ], int pupils, int tests )
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

   printf("\n\nLowest grade: %d\n",lowGrade) ; /* return minimum grade */ 
} /* end function minimum */

/* Find the maximum grade */
void maximum( const int grades[][ EXAMS ], int pupils, int tests )
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

   printf("\n\nHighest grade: %d\n",highGrade) ; /* return maximum grade */
} /* end function maximum */

/* Determine the average grade for a particular student */
void average( const int grades[][ EXAMS ], int pupils, int tests )
{
   int i; /* exam counter */
   
   int student; /* student counter */
   /* total all grades for one student */
   for ( student = 0; student < pupils; student++ ){
   	   int total = 0; /* sum of test grades */
	   for ( i = 0; i < tests; i++ ) {
		  total += grades[ student ][i];
	   } /* end for */
	   printf( "The average grade for student %d is %.2f\n", 
       student, ( double ) total / tests );
	}
} /* end function average */

/* Print the array */
void printArray( const int grades[][ EXAMS ], int pupils, int tests )
{
   int i; /* student counter */
   int j; /* exam counter */

   /* output column heads */
   printf( "                 [0]  [1]  [2]  [3]" );

   /* output grades in tabular format */
   for ( i = 0; i < pupils; i++ ) {

      /* output label for row */
      printf( "\nstudentGrades[%d] ", i );

      /* output grades for one student */
      for ( j = 0; j < tests; j++ ) {
         printf( "%-5d", grades[ i ][ j ] );
      } /* end inner for */
   } /* end outer for */
} /* end function printArray */



/**************************************************************************
 * (C) Copyright 1992-2010 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/

