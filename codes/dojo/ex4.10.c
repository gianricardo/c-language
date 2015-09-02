#include <stdio.h>

int main(void){

    int num, contador=0, acumulador=0;
    float media = 0;

    while (num != 9999){
        printf("Digite um numero (9999 para sair): ");
        scanf("%d", &num);

        if(num == 9999)
        {
            break;
        }

        acumulador+=num;
        contador++;
      
    }
    media = (acumulador/(contador*1.0));
    printf("a media e %.3f\n",media);
return 0;
}

        
        
