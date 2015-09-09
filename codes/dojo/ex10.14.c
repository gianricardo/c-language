#include <stdio.h>

void descompactaCaracteres (int src, char *char1, char *char2);


int main()
{

    char char1, char2;
    unsigned int compactado;

    printf("Informe o inteiro: ");
    scanf("%d", &compactado);

    descompactaCaracteres(compactado, &char1, &char2);
    printf ("%d %d\n", ((int)char1), ((int)char2));
  
    return 0;
}

void descompactaCaracteres (int src, char *char1, char *char2)
{
    (*char2) = src & 0xff;
    (*char1) = (src & 0xff00) >> 8;
}
