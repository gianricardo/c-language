#include<stdio.h>

int mdc(int x ,int y);
int main(void){
	printf("%d           %d\n",mdc(27,8),27%8);
return 0;
}

int mdc(int x ,int y){
	if(y==0){
		return x;
	
	}
	else{
		 mdc(y,x%y);
		//return y;
	}

}
