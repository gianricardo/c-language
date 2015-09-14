#include<stdio.h>
#define N 5
int main(void){
	int i,fatorial=1;
	for(i=1;i<=N;i++){
		fatorial*=i;
		printf("%d\t%d\n",i,fatorial);
	
	}

return 0;
}
