#include <stdio.h>

int main(){
float prod1=2.98,prod2=4.50,prod3=9.98,prod4=4.49,prod5=6.87;
int num, quant,i = 0, total=0;

printf("insira o produto e a quantidade vendida em um dia: ");
scanf("%d%d", &num, &quant);

while(i<7){
    printf ("digite 6 para encerrar o dia\n");
    printf("insira o produto e a quantidade vendida em um dia: ");
    scanf("%d%d", &num, &quant);
    switch (num){
        case 1:{
                total+=prod1*quant;
                break;         
        }        
        case 2:{
                total+=prod2*quant;
                break;         
        }
        case 3:{
                total+=prod3*quant;
                break;         
        }
        case 4:{
                total+=prod4*quant;
                break;         
        }
        case 5:{
                total+=prod5*quant;
                break; 
        }
        default :
              
    }
    printf ("total da semana: %d", total);
    return 0;
    }
}

        
