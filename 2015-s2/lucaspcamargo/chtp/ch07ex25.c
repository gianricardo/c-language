/**
 * c02ex16.c - Calculates numerical relationships between two numbers
 * © Lucas Pires Camargo
 * 
 * See LICENSE file at the root of this repository.
 */

#include <stdio.h>

#define STUDENTS 3
#define EXAMS 4

/* function prototypes */
int minimum( const int grades[][ EXAMS ], int pupils, int tests );
int maximum( const int grades[][ EXAMS ], int pupils, int tests );
double average( const int setOfGrades[], int tests );
void printArray( const int grades[][ EXAMS ], int pupils, int tests );

/* menu action function type */
typedef void MenuFunction( const int grades[][ EXAMS ], int pupils, int tests ); 

/* function definition shorthands */
MenuFunction menuPrint, menuMinimum, menuMaximum, menuAverages;

#define MENU_COUNT 5

    
/* function main begins program execution */
int main( void )
{

    /* Function pointer array for menu actions */
    MenuFunction *menuFuncs[] = {menuPrint, menuMaximum, menuMinimum, menuAverages, 0};    

    /* String array for menu descriptions */
    const char * menuStr[MENU_COUNT] = {
        "Print the array of grades", 
        "Find the maximum grade", 
        "Find the minimum grade", 
        "Print the average on all tests for each student", 
        "Quit"};
    
    /* initialize student grades for three students (rows) */
    const int studentGrades[ STUDENTS ][ EXAMS ] =
    { { 77, 68, 86, 73 },
    { 96, 87, 89, 78 },
    { 70, 90, 86, 81 } };
    

    for(;;) /* present menu forever */
    {
        int choice;
        
        printf("\n\nChoose an option:\n");
        for(int i = 0; i < MENU_COUNT; i++)
        {
            printf("  %d) %s\n", i, menuStr[i]);  /* present menu item */
        }
        
        scanf("%d", &choice);  /* read user option */
        
         /* validate user option */
        if(choice < 0 || choice > (MENU_COUNT - 1))
            printf("\n\nInvalid choice\n");
        else
        {
            MenuFunction *fptr = menuFuncs[choice];  /* access array as defined by index */
            if(fptr)
                (*fptr)(studentGrades, STUDENTS, EXAMS);  /* menu is valid function */
            else
                break; /* end program execution */
        }
    }
    
    return 0; /* indicates successful termination */
    
} /* end main */

void menuPrint( const int grades[][ EXAMS ], int pupils, int tests )
{
    /* output array studentGrades */
    printf( "The array is:\n" );
    printArray( grades, STUDENTS, EXAMS );
}

void menuMaximum( const int grades[][ EXAMS ], int pupils, int tests )
{
    /* determine largest grade value */
    printf( "\n\nHighest grade: %d\n",
            maximum( grades, pupils, tests ));
}

void menuMinimum( const int grades[][ EXAMS ], int pupils, int tests )
{
    /* determine lowest grade value */
    printf( "\n\nLowest grade: %d\n",
            minimum( grades, pupils, tests ));
    
}

void menuAverages( const int grades[][ EXAMS ], int pupils, int tests )
{
    /* calculate average grade for each student */
    for ( int student = 0; student < pupils; student++ ) {
        printf( "The average grade for student %d is %.2f\n",
                student, average( grades[ student ], tests ) );
    } /* end for */
}


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
    return lowGrade; /* return minimum grade */
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
    return highGrade; /* return maximum grade */
} /* end function maximum */

/* Determine the average grade for a particular student */
double average( const int setOfGrades[], int tests )
{
    int i; /* exam counter */
    int total = 0; /* sum of test grades */
    /* total all grades for one student */
    for ( i = 0; i < tests; i++ ) {
        total += setOfGrades[ i ];
    } /* end for */
    return ( double ) total / tests; /* average */
} /* end function average */

/* Print the array */
void printArray( const int grades[][ EXAMS ], int pupils, int tests )
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
} /* end function printArray */
