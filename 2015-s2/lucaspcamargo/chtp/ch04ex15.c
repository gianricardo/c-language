/* Fig. 4.6: fig04_06.c
Calculating compound interest */
#include <stdio.h>
#include <math.h>
/* function main begins program execution */
int main( void )
{
    for(int rateP = 5; rateP <= 10; rateP++ )
    {
        double rate = rateP * 0.01; /* annual interest rate */
     
        printf("\nInterest rate is %d%%\n", rateP);
     
        double amount; /* amount on deposit */
        double principal = 1000.0; /* starting principal */
        int year; /* year counter */
        /* output table column head */
        printf( "%4s%21s\n", "Year", "Amount on deposit" );
        /* calculate amount on deposit for each of ten years */
        for ( year = 1; year <= 10; year++ ) {
            /* calculate new amount for specified year */
            amount = principal * pow( 1.0 + rate, year );
            /* output one table row */
            printf( "%4d%21.2f\n", year, amount );
        } /* end for */
    }
    return 0; /* indicate program ended successfully */
} /* end function main */
