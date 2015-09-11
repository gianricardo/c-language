#include <stdio.h>

int main () {
	
	int dn, mn, an, da, ma, aa;
	
	printf("Data de nascimento (dd mm aaaa): ");
	scanf("%d%d%d", &dn, &mn, &an);
	
	printf("Data atual (dd mm aaaa): ");
	scanf("%d%d%d", &da, &ma, &aa);
	
	float idade = ( aa - an*1.0 ) + ( (ma - mn) / 12.0) + ( ( da - dn ) / 365.0 );
	
	printf("\nIdade: %f anos\n", idade);
	
	printf("\nFrequencia cardiaca maxima: %f bpm\n", 220 - idade);
	
	printf("\nFrequencia cardiaca media: %f ~ %f bpm\n", 0.5 * (220 - idade) , 0.85 * (220 - idade));
	
	return 0;
}
