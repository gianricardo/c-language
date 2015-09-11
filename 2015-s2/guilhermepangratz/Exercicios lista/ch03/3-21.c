#include <stdio.h>

int main () {
	
	int hours;
	float hourly_rate, salary;
	
	while (1) { 
		
		printf("\nEnter # of hours worked (-1 to end): "); 
		scanf("%d", &hours);
		
		if (hours == -1) {
			return 0;
		}
		
		printf("\Enter hourly rate of the worker ($00.00): "); 
		scanf("%f", &hourly_rate);
		
		if (hours <=40) {
			salary = hours * hourly_rate;
		} else {
			salary = (40 * hourly_rate) + ((hours - 40) * (hourly_rate * 1.5));
		}		
		
		printf("Salary is $%.2f\n ", salary); 
		
	}
	return 0;
}
