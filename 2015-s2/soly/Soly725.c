#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

/* function prototypes */
int minimum( const int grades[][ EXAMS ], int pupils, int tests );
int maximum( const int grades[][ EXAMS ], int pupils, int tests );
double average( const int grades[][ EXAMS ], int pupils, int tests );
void printArray( const int grades[][ EXAMS ], int pupils, int tests );

/* function main begins program execution */
int main( void ){
 while(1){
   int student; /* student counter */
   int (*processGrades[4])(const int grades[][ EXAMS ], int pupils, int tests) = {printArray,minimum,maximum,average};/* pointer to function*/
   printf("Digite uma escolha:\n0 imprime o array de notas\n1 Acha a menor nota\n2 Acha a maior nota\n3 Imprime a media de todos os testes para cada aluno\n4 Encerra o programa\n");

   /* initialize student grades for three students (rows) */
   const int studentGrades[ STUDENTS ][ EXAMS ] =
      { { 77, 68, 86, 73 },
        { 96, 87, 89, 78 },
        { 70, 90, 86, 81 } };

    int option;

    printf("Escolha uma opcao: \n");
    scanf("%d", &option);/* after decision of user, check if the value inserted is out of bonds, if not, check if the value is to close the program
     if not, call the matching function*/
    if(option<0 || option>4){
        printf("Valor invalido, por favor escolha novamente");
    }else if(option==4){
        printf("Programa encerrado");/*ends the program*/
       return 0;
    }else{
        processGrades[option](studentGrades, STUDENTS, EXAMS);
    }
 }
   return 0;
} /* end main */

/* Find the minimum grade */
int minimum( const int grades[][ EXAMS ], int pupils, int tests )
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

   printf("%d\n", lowGrade); /* print the lower grade */
} /* end function minimum */

/* Find the maximum grade */
int maximum( const int grades[][ EXAMS ], int pupils, int tests )
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

   printf("%d\n", highGrade); /* print the maximum grade */
} /* end function maximum */

/* Determine the average grade for a particular student */
double average( const int grades[][ EXAMS ], int pupils, int tests )
{
   int i; /*students counter*/
   int j; /*exams counter*/
   double media=0;

   /*total of pupils*/
   for ( i = 0; i < pupils; i++ ) {
     for(j=0;j<tests;j++){/*total of grades */
        media+= grades[i][j];/*sum them to media*/
    } /* end for */
   media = media/4;/*gets the average of a student*/
   printf("media %lf\n", media);
   media=0;/*clear the variable and repeat the process for another student*/
    } /* end function average */
}/* Print the array */

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
