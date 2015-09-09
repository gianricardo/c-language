#include<stdio.h>

int main()
{
    int i, j, lado;
    printf("Entre o tamanho do lado do quadrado: ");
    scanf("%d", &lado);
    for (i=0; i < lado; i++){
        for ( j = 0; j < lado; j++) {
            if ( i == 0 || i == lado-1) {
                printf ("*");
            }else if(j==0 || j==lado-1){
                printf("*");
            }else if(j>0 && j<lado-1){
                printf(" ");
            }
        }
    printf("\n");
    }

    return 0;
}
