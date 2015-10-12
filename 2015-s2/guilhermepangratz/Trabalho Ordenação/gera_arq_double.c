#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <float.h>
#include <limits.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	unsigned long int bytes = 0;
	unsigned long int num, dec, i = 0;
	double numd;
	unsigned long int total_bytes;
	char tmp[11];

	if(argc != 3) {
		printf("./%s numero_de_bytes nome_do_arquivo\n", argv[0]);
		exit(-1);
	}

	srand(time(NULL));

	if((fp = fopen(argv[2], "w")) == NULL) {
		printf("Impossivel abrir o arquivo %s\n", argv[2]);
		exit(-1);
	}

	total_bytes = atoi(argv[1]);

	while(bytes <= total_bytes) {
		num = rand() % (unsigned long int)DBL_MAX;
		dec = rand() % (unsigned long int)DBL_MAX;
		numd = (num*1.0) * (dec*1.0 / (double)RAND_MAX);
		fprintf(fp, "%lf", numd);

		i++;		

		sprintf(tmp, "%lf", numd);
		bytes += strlen(tmp);
		tmp[0] = '\0';

		if(i % 10 == 0) {
			i = 0;			
			fprintf(fp, "\n");
		} else
			fprintf(fp, " ");				
	}

	if(i != 0) {
		for(;i < 10; i++) {
			num = rand() % (unsigned long int)DBL_MAX;
			dec = rand() % (unsigned long int)DBL_MAX;
			numd = (num*1.0) * (dec*1.0 / (double)RAND_MAX);
			fprintf(fp, "%lf ", numd);
			sprintf(tmp, "%lf", numd);
			bytes += strlen(tmp);
			tmp[0] = '\0';
		}
	}

	fprintf(fp, "\n");
	printf("Escritos %ld bytes em %s\n", bytes, argv[2]);

	return 0;
}
