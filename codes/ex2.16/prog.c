#include <stdio.h>

int main (void){
    int variavel1=0, variavel2=0;
    //mostra mensagem
    printf("Usuário, digite dois números inteiros: ");
    //le os numeros do teclado
    scanf("%d %d",&variavel1, &variavel2);
    //realiza as operações solicitadas
    printf("Lidos: %5d%5d\n",variavel1,variavel2);//mostra os numeros lidos
    printf("Soma : %d\n",variavel1+variavel2);//mostra o resultado da soma
    printf("Subtração : %d\n",variavel1-variavel2);//mostra o resultado da subtracao
    printf("Multiplicação : %d\n",variavel1*variavel2);//mostra o resultado da multiplicacao
    printf("Divisão : %d\n",variavel1/variavel2);//mostra o resultado da divisão inteira
    printf("Resto : %d\n",variavel1%variavel2);//mostra o resto da divisão
    //fim
	return 0;
}
