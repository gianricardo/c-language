// Tenenbaum 6.5.4
//a)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    
    srand((int)time(0));
    
    const int sizeA = 10, sizeB = 10;
    
    int vetA[sizeA], vetB[sizeB], vetC[sizeA+sizeB];
    
    int i, j, c = 0; //contadores
    
    //preenche e imprime o vetA
    printf("Vetor A: [ ");
    for (i = 0; i < sizeA ; i++) {
        vetA[i] = rand() % 10;
        if ( i > 0 ) {
            if (vetA[i] <= vetA[i-1]) {
                vetA[i] = vetA[i] + vetA[i - 1];
            }            
        }
        printf("%d ", vetA[i]);
    }
    
    //preenche e imprime o vetB
    printf("]\n\nVetor B: [ ");
    for (i = 0; i < sizeB ; i++) {
        vetB[i] = rand() % 10;
        if ( i > 0) {
            if (vetB[i] <= vetB[i-1] ) {
                vetB[i] = vetB[i] + vetB[i - 1];
            }
        }
        printf("%d ", vetB[i]);
    }
    
    int e = 0, m, d; //esquerda meio e direita   
    
    //busca binaria
    for (i = 0 ; i < sizeB ; i++ ) {
        d = (sizeA -1);
        j = e;
        while (e <= d) {
            m = (e + d) / 2;
            if (vetB[i] < vetA[m]){
                d = m;
            } else if (vetB[i] > vetA[m]) {
                e = m;
            } 
            if (vetB[i] == vetA[m] || e == d - 1 || e == d) {
                e = m + 1;
                break;
            }
        }
        for (; j <= m; j++) {
            vetC[c] = vetA[j];
            c++;
        }
        vetC[c] = vetB[i];
        c++;
    }
    
    printf("]\n\nVetor C: [");
    for (i = 0; i < (sizeA + sizeB) ; i++) {
        printf("%3d", vetC[i]);
    }
    printf("]\n");
    
    return 0;
}

//Depende da sitaução, se na intercalação usassemos o quic ksort, esse metodo
//seria melhor eque o pior caso do quick sort, mas geralmente o quick sort se sairia melhor.
