/* Fig. 6.22: fig06_22.c
   Double-subscripted array example */

//PROGRAMA EDITADO PARA ATEDER OS REQUISITOS DO EXERCICIO 7.25
#include <stdio.h>
#include <stdlib.h>
#define STUDENTS 3
#define EXAMS 4

/* function prototypes */
void minimum( const int grades[][ EXAMS ], int pupils, int tests );
void maximum( const int grades[][ EXAMS ], int pupils, int tests );
void average( const int grades[][ EXAMS ], int pupils, int tests );
void printArray( const int grades[][ EXAMS ], int pupils, int tests );

/* function main begins program execution */
int main( void )
{
    int student; /* student counter */

    /* initialize student grades for three students (rows) */
    const int studentGrades[ STUDENTS ][ EXAMS ] =
    {
        { 77, 68, 86, 73 },
        { 96, 87, 89, 78 },
        { 70, 90, 86, 81 }
    };

    int opcao; //variavel para armazenar a escolha do usuario
    void (*processGrades[4])(const int grades[][ EXAMS ], int pupils, int tests) = {printArray,minimum,maximum,average}; //array de ponteiro para função, posicao 0 contem a funçao 'imprime array de notas', posicao 1 contem o 'acha menor nota', posicao 2 contem o 'acha maior nota', posicao 3 contem o imprime media de todos os contatos
    while(1)
    {
        printf("Digite a opção:\n0-Imprime array de notas\n1-Acha a menor nota\n2-Acha a maior nota\n3-Imprime média de todos os testes para cada aluno\n4-Encerra o programa\n");
        scanf("%d",&opcao);
        if(opcao == 4 || opcao <0 || opcao >4) //caso o usuario digite opçao invalida ou opçao 4, termina o programa
        {
            exit(-1);
        }
        processGrades[opcao]( studentGrades, STUDENTS, EXAMS );
    }




    return 0; /* indicates successful termination */
} /* end main */

/* Find the minimum grade */
void minimum( const int grades[][ EXAMS ], int pupils, int tests )
{
    int i; /* student counter */
    int j; /* exam counter */
    int lowGrade = 100; /* initialize to highest possible grade */

    /* loop through rows of grades */
    for ( i = 0; i < pupils; i++ )
    {

        /* loop through columns of grades */
        for ( j = 0; j < tests; j++ )
        {

            if ( grades[ i ][ j ] < lowGrade )
            {
                lowGrade = grades[ i ][ j ];
            } /* end if */
        } /* end inner for */
    } /* end outer for */

    /* loop through rows of grades */
    for ( i = 0; i < pupils; i++ )
    {
        /* loop through columns of grades */
        for ( j = 0; j < tests; j++ )
        {
            if ( grades[ i ][ j ] < lowGrade )
            {
                lowGrade = grades[ i ][ j ];
            } /* end if */
        } /* end for */
    } /* end inner for */

    printf("menor nota=%d\n",lowGrade);
    printf("\n"); //nova linha para organizar visual de saida
    return;
} /* end function minimum */

/* Find the maximum grade */
void maximum( const int grades[][ EXAMS ], int pupils, int tests )
{
    int i; /* student counter */
    int j; /* exam counter */
    int highGrade = 0; /* initialize to lowest possible grade */

    /* loop through rows of grades */
    for ( i = 0; i < pupils; i++ )
    {

        /* loop through columns of grades */
        for ( j = 0; j < tests; j++ )
        {

            if ( grades[ i ][ j ] > highGrade )
            {
                highGrade = grades[ i ][ j ];
            } /* end if */
        } /* end inner for */
    } /* end outer for */
    printf("maior nota=%d\n",highGrade);
    printf("\n"); //nova linha para organizar visual de saida
    return;
} /* end function maximum */

/* Determine the average grade for a particular student */
void average( const int grades[][ EXAMS ], int pupils, int tests )
{
    int i,j; /* exam counter */
    int total = 0; /* sum of test grades */
    double result;

    /* total all grades for one student */
    for ( i = 0; i < pupils; i++ )
    {
        for ( j = 0; j<tests; j++)
        {
            total += grades[i][j];
        }
        result = ( double ) total / tests; /* average */
        printf("média aluno %d = %lf\n",i,result);
    }
    printf("\n"); //nova linha para organizar visual de saida
    return;
} /* end function average */

/* Print the array */
void printArray( const int grades[][ EXAMS ], int pupils, int tests )
{
    int i; /* student counter */
    int j; /* exam counter */

    /* output column heads */
    printf( "                 [0]  [1]  [2]  [3]" );

    /* output grades in tabular format */
    for ( i = 0; i < pupils; i++ )
    {

        /* output label for row */
        printf( "\nstudentGrades[%d] ", i );

        /* output grades for one student */
        for ( j = 0; j < tests; j++ )
        {
            printf( "%-5d", grades[ i ][ j ] );
        } /* end inner for */
    } /* end outer for */
    printf("\n\n"); //novas linhas para organizar visual de saida
    return;
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
