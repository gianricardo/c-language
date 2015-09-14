#include<stdio.h>
int main(void){
	int produto,produto1=0,produto2=0,produto3=0,produto4=0,produto5=0;
	printf("informe o produto");
	scanf("%d",&produto);
	switch(produto){
		case 1:
			printf("quandtidade vendida");
			scanf("%d",&produto1);
			break;
		case 2:
			printf("quandtidade vendida");
			scanf("%d",&produto2);
			break;
		case 3:
			printf("quandtidade vendida");
			scanf("%d",&produto3);
			break;
		case 4:
			printf("quandtidade vendida");
			scanf("%d",&produto4);
			break;
		case 5:
			printf("quandtidade vendida");
			scanf("%d",&produto5);
			break;
	}
	printf("os valores vendidos foram: %f \n",(produto5*6.87)+(produto4*4.49)+(produto3*9.98)+(produto2*4.50)+(produto1*2.98));
	
	
	
return 0;
}
