/* 
 * File:   bolha.c
 * Author: GuilhermeAugusto
 *
 * Created on 22 de Setembro de 2015, 15:26
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    
    int idade, matricula;
    
} idade_matricula;

void bolha(idade_matricula vetor[], int n);

int main() {

    srand((int)time(0));
    
    idade_matricula individuos[100];
    
    int  i;
    
    printf("vetor original: [");
    
    for ( i= 0 ; i < 100 ; i++) {
        individuos[i].idade = rand() % 100 + 1;
        individuos[i].matricula = rand() % i + 100;
        printf ("%d: Idade - %d ; Matricula - %d \n", i, individuos[i].idade, individuos[i].matricula);
    }
    
    
    bolha(individuos, 100);
    
    printf("]\n\nReorganizados: [");
    for ( i= 0 ; i < 100 ; i++) {
        printf ("%d: Idade - %d ; Matricula - %d \n", i, individuos[i].idade, individuos[i].matricula);
    }
    printf("]\n");
    
    
    return 0;
}

void bolha(idade_matricula x[], int n) {
    idade_matricula hold;
    int j, pass;
    int switched = 1;
    for (pass = 0; (pass < n - 1) && (switched == 1); pass++) {
        switched = 0;
        for (j = 0 ; j < n -1 - pass; j++) {
            if (x[j].idade > x[j+1].idade) {
                switched = 1;
                hold = x[j];
                x[j] = x[j+1];
                x[j+1] = hold;
            }
        }
    }
}
