#include <stdio.h>

unsigned int compactaCaracteres (char char1, char char2);


int main()
{

    char char1, char2;
    unsigned int compactado;
    printf("Informe 2 caracteres: ");
    scanf("%c%c", &char1, &char2);
    compactado = compactaCaracteres(char1,char2);
    printf ("%d %d %d\n", ((int)char1), ((int)char2), compactado);
  
    return 0;
}

unsigned int compactaCaracteres (char char1, char char2)
{

    unsigned int unit1=0;

    unit1=char1<<8;
    unit1|=char2;
    return unit1;
}
