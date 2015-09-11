#include<stdio.h>
int main(void){
	int multiplicador=1,numero=1543767177,contador_7=0;
	printf("informe o valor : %d\n",numero);
	scanf("%d",&numero);
	while(1){
		printf("   %d   ",((numero%(10*multiplicador))/(multiplicador)));
		if(((numero%(10*multiplicador))/(multiplicador))==7){
			contador_7++;
		
		}
		
		
		
		multiplicador*=10;
		
		printf("%d :\n",contador_7);
	
	}
	
	

return 0;
}
