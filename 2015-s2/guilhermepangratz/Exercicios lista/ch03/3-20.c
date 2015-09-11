#include <stdio.h>

int main () {
	
	float principal, rate;
	int days;
	
	while (1) {
		printf("\nEnter loan principal (-1 to end): ");
		scanf("%f", &principal);
		
		if (principal == -1) {
			return 0;
		}
	
		printf("Enter interest rate: ");
		scanf("%f", &rate);
	
		printf("Enter term of the loan in days: ");
		scanf("%d", &days);
		
		printf("The interest charge is $%.2f\n ",  principal * rate * days / 365);

	}
	
	
	return 0; 
}
