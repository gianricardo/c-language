#include <stdio.h>

int main(){
    int num, i=1, j;
    
    for (; i<=5; i++){

        printf("insira o %d, de 5, de 1 a 30", i);
        scanf("%d",&num);
        while (num>30 || num<1){
            printf("numero nao aceito: ");
            scanf("%d",&num);
        }
        for (j=0; j<num; j++) {
            printf("*");
            
        }
        printf("\n");
        }
        return 0;

}
