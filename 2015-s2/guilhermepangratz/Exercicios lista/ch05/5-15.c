#include <stdio.h>
#include <math.h>

double hyp( double c1, double c2); //retorna a hipotenusa para os catetos fornecidos

int main () {
	
	printf("%10s%10s%10s%10s\n", "Triang", "cateto 1", "cateto 2", "hipot");
	printf("%10d%10.2lf%10.2lf%10.2lf\n", 1, 3.0, 4.0, hyp(3.0, 4.0));
	printf("%10d%10.2lf%10.2lf%10.2lf\n", 2, 5.0, 12.0, hyp(5.0, 12.0));
	printf("%10d%10.2lf%10.2lf%10.2lf\n", 3, 8.0, 15.0, hyp(8.0,15.0));

	return 0;
}

double hyp( double c1, double c2) {
	double hipotenusa = sqrt(pow(c1, 2.0) + pow(c2, 2.0));
	return hipotenusa;
}
