#include <stdio.h>


int main( void )
{
    int bd, bm, by;
    int cd, cm, cy;
    
    printf("Enter birthday (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &bd, &bm, &by);
    
    printf("Enter today's date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &cd, &cm, &cy);
    
    int diffDays = (cy - by) * 365;
    diffDays += (cm - bm) * 30;
    diffDays += (cd - bd);
    
    int age = diffDays / 365;
    int maxRate = 220 - age;
    
    printf("You are %d years old\n", age);
    printf("Your maximum heart rate is %d bpm\n", maxRate);
    printf("Your target heart rate is between %d and %d bpm\n", ((int) (maxRate * 0.5f)), ((int) (maxRate * 0.85f)));
    
    return 0;
}
