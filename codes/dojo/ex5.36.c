#include<stdio.h>

void movern ( int numero_discos,  int pino_inicial, int pino_final, int pino_temp);

int main (void){

    // passar 3 discos do pino 1 para o 3 usando o 2 como temp 
    movern(3, 1, 3, 2);

}
/*

1)mova n-1 discos do pino 1 para o pino 2 ,usando o pino 3 
como area de manutencao temporaria

2) mova o ultimo disco (o maior) do pino 1 para o pino 3

3)mova n-1 discos do pino 2 para o pino 3, usando o pino 1
 como area de manutencao temporararia

 */
void movern ( int numero_discos,  int pino_inicial, int pino_final, int pino_temp)
{
    if (numero_discos==1){
        printf (" %d -> %d\n",pino_inicial,pino_final);
    }else{
        movern(numero_discos - 1, pino_inicial, pino_temp, pino_final );
        printf (" %d -> %d\n", pino_inicial, pino_final);
        movern(numero_discos - 1, pino_temp, pino_final, pino_inicial );
    }
}
