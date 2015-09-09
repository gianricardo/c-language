#include <stdio.h>

int main(void)
{
    int dias=0;
    float taxa=0,principal=0,juros=0;

    while (principal!=-1){
    printf("informe o valor principal do emprestimo(-1 para terminar): ");
    scanf("%f",&principal);
    if (principal ==-1) continue;
    printf("informe a taxa de juros: ");
    scanf("%f",&taxa);
    printf("informe o prazo de emprestimo em dias: ");
    scanf("%d",&dias);
    juros=(principal*taxa*dias)/365;
    printf("o valor do juros é de R$%.2f: \n", juros);
    }
        
    return 0;
    


}
