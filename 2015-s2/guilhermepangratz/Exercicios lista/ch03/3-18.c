#include <stdio.h>

int main () {
	
	int account_number = 0;
	float  balance, charges, credits, limit;
	
	while (1) {
		
		printf("\nEnter account number (-1 to end): ");
		scanf("%d", &account_number);
		
		if (account_number == -1) {
			return 0;
		}
		
		printf("Enter beginning balance: ");
		scanf("%f", &balance);
		
		printf("Enter total charges: ");
		scanf("%f", &charges);
		
		printf("Enter total credits: ");
		scanf("%f", &credits);
		
		printf("Enter credit limit: ");
		scanf("%f", &limit);
		
		balance = balance + charges - credits;
		
		if ( balance > limit ) {
			
			printf("%-14s %-d\n", "Account:", account_number);
			printf("%-14s %-.2f\n", "Credit limit:", limit);
			printf("%-14s %-.2f\n", "Balance", balance);
			printf("Credit Limit Exceeded.");
			
		}		
		
		printf("\n");
		
	} 
	
	return 0;
}
