#include <stdio.h>

void printArray(int tam,int array[]);

int main(void){

    int vetor[4]={1,2,3,4},tamanho=4;

    
    printArray(tamanho,vetor);
    



}

void printArray(int tam,int array[]){
    if(tam==0){
        return;
    }else{
    printf("\n%d\n",array[tam-1]);
    tam=tam-1;
    printArray(tam,array);
    }
    


}
