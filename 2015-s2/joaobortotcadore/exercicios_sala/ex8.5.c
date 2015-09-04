#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main( void )
{

	char car;
	scanf("%c", &car);
	
	printf("isdigit: %d\n",isdigit(car));
	printf("isalpha: %d\n", isalpha(car));
	printf("isalnum: %d\n", isalnum(car));
	printf("isxdigit: %d\n", isxdigit(car));
	printf("islower: %d\n", islower(car));
	printf("isupper: %d\n", isupper(car));
	printf("tolower: %c\n", tolower(car));
	printf("toupper: %c\n", toupper(car));
	printf("isspace: %d\n", isspace(car));
	printf("iscntrl: %d\n", iscntrl(car));
	printf("ispunct: %d\n", ispunct(car));
	printf("isprint: %d\n", isprint(car));
	printf("isgraph: %d\n", isgraph(car));
	return 0;
}
