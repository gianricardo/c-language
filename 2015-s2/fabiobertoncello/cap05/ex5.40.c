#include<stdio.h>
int main(void){
	static count=1;
	printf("%d\n",count);
	
	//count++;
	main();
	
return 0;
}
