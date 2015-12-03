/*! \file stdio.h
 * \brief Standard input-output
 */
#include <stdio.h>
#include <stdlib.h>

/*! \file lista_dev.h
 * \brief TDA lista duplamente encadeada usando vetor.
 * TDA a ser testado nesta aplicação
 */
 #include "area.h"


//! Função principal - teste do TDA
/*!
 * Rotina criada para testar a Funcionalidade do TDA
 */
int main() {
    Area *a = cria_area_vazia();
    if (a != NULL) printf("AREA CRIADA COM SUCESSO!\n");
    printf("a = "); imprime_area(a); printf("\n");
    printf("\nquantidade de celulas ocupadas: %d\n", celulas_ocupadas(a)); 
    
    int v[] = {3, 65, 2, 3, 65, 23, 12, 32 , 87, 11, 54, 3, 1, 5, 12, 32, 12, 12, 43, 20};
    
    int i;
    printf("\nv = { ");
    for (i = 0 ; i < 20 ; i++) {
        printf("%d ", v[i]);
    }
    printf("}\n");
    
    printf("\ninserir:\n");
    for (i = 0; i < 20; i++) {
        printf("%d valor - %d :", i, v[i]);
        if (inserir(a, v[i]) == SUCCESS) printf("SUCCESS\n");
        else if (inserir(a, v[i]) == OVERFLOW) printf("OVERFLOW\n");
    }
    printf("\nquantidade de celulas ocupadas: %d\n", celulas_ocupadas(a)); 
 
    printf("\na = "); imprime_area(a); printf("\n");  
        
    printf("\nretirar_primeiro:\n");
    for (i = 0; i < 20; i++) {
        if (retirar_primeiro(a, &v[i]) == SUCCESS) printf("%i retirado (SUCCESS)\n", v[i]);
        else if (retirar_primeiro(a, &v[i]) == UNDERFLOW) printf("UNDERFLOW\n");
    }
 
    printf("\na = "); imprime_area(a); printf("\n"); 
	printf("\nquantidade de celulas ocupadas: %d\n", celulas_ocupadas(a)); 
	
    printf("\ninserir:\n");
    for (i = 0; i < 20; i++) {
        printf("%d valor - %d :", i, v[19-i]);
        if (inserir(a, v[19-i]) == SUCCESS) printf("SUCCESS\n");
        else if (inserir(a, v[i]) == OVERFLOW) printf("OVERFLOW\n");
    }
 
    printf("\na = "); imprime_area(a); printf("\n");
    printf("\nquantidade de celulas ocupadas: %d\n", celulas_ocupadas(a)); 
    
    printf("\nretirar_ultimo:\n");
    for (i = 0; i < 20; i++) {
        if (retirar_ultimo(a, &v[19-i]) == SUCCESS) printf("%i retirado (SUCCESS)\n", v[19-i]);
        else if (retirar_ultimo(a, &v[i]) == UNDERFLOW) printf("UNDERFLOW\n");
    }
    
    printf("\nv = { ");
    for (i = 0 ; i < 20 ; i++) {
        printf("%d ", v[i]);
    }
    
    printf("\ninserir:\n");
    for (i = 0; i < 8; i++) {
        printf("%d valor - %d :", i, v[19-i]);
        if (inserir(a, v[19-i]) == SUCCESS) printf("SUCCESS\n");
        else if (inserir(a, v[i]) == OVERFLOW) printf("OVERFLOW\n");
    }
 
    printf("\na = "); imprime_area(a); printf("\n");
    printf("\nquantidade de celulas ocupadas: %d\n", celulas_ocupadas(a)); 
    
    printf("\nretirar_ultimo:\n");
    for (i = 0; i < 3; i++) {
        if (retirar_ultimo(a, &v[19-i]) == SUCCESS) printf("%i retirado (SUCCESS)\n", v[19-i]);
        else if (retirar_ultimo(a, &v[i]) == UNDERFLOW) printf("UNDERFLOW\n");
    }
    printf("\nretirar_primeiro:\n");
    for (i = 0; i < 3; i++) {
        if (retirar_primeiro(a, &v[i]) == SUCCESS) printf("%i retirado (SUCCESS)\n", v[i]);
        else if (retirar_primeiro(a, &v[i]) == UNDERFLOW) printf("UNDERFLOW\n");
    }
    
    printf("\ninserir:\n");
    for (i = 0; i < 8; i++) {
        printf("%d valor - %d :", i, v[19-i]);
        if (inserir(a, v[19-i]) == SUCCESS) printf("SUCCESS\n");
        else if (inserir(a, v[i]) == OVERFLOW) printf("OVERFLOW\n");
    }
    
    printf("\na = "); imprime_area(a); printf("\n");
    
    printf("\nv = { ");
    for (i = 0 ; i < 20 ; i++) {
        printf("%d ", v[i]);
    }
    
    inserir(a, 3);
    printf("\\nn3 inserido\n");
    printf("\na = "); imprime_area(a); printf("\n");
    printf("\nquantidade de celulas ocupadas: %d\n", celulas_ocupadas(a)); 
    int x;
    retirar_ultimo(a, &x);
    printf("\nUltimo retirado\n");
    printf("\na = "); imprime_area(a); printf("\n");
    printf("\nquantidade de celulas ocupadas: %d\n", celulas_ocupadas(a));
    
    printf("\nv = { ");
    for (i = 0 ; i < 20 ; i++) {
        printf("%d ", v[i]);
    }
    printf("}\n");
    
    destroi_area(&a);
    if (a == NULL) printf("\nArea destruida com sucesso!!!\n");
    printf("\nquantidade de celulas ocupadas: %d\n(-1 se o ponteiro para area é nullo)\n", celulas_ocupadas(a)); 
    
}
