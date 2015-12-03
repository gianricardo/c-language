#include <stdio.h>
#include <stdlib.h>

/*! \file myheader.h
 * \brief A Documented header file.
 *
 * Details about myheader.h.
 */
#include "area_priv.h"

int compCelulas(struct celula *acel, struct celula *bcel){
    if (acel == NULL || bcel == NULL) return 2;
    if (acel->chave > bcel->chave) return 1;
    if (acel->chave == bcel->chave) return 0;
    if (acel->chave < bcel->chave) return -1;
}

//! \class cria_area_vazia Cria uma area vazia e inicializa seus elementos para que eles funcionem da maneira desejada
/*!
 * Cria a lista com tamnho definido pela macro TAMCELS do arquivo privado.
 * @return ponteiro para a área criada
 */
Area *cria_area_vazia(){
    Area *a = NULL;
	a = (Area*)malloc(sizeof(Area));
	if (a == NULL) return a;
    a->primeiro = -1;
    a->ultimo = -1;
    a->priCelulaDisp = 0;
    a->numCelOcupadas = 0;
    int i;
    for (i=0; i < TAMCELS - 1 ; i++) {
        a->itens[i].ant = -1;
        a->itens[i].prox = i + 1;
    }
    a->itens[TAMCELS - 1].ant = -1;
    a->itens[TAMCELS - 1].prox = -1;
    return a;
}

//! \class celulas_ocupadas Retorna a quantidade de celulas ocupadas, e -1 se for uma area nula
/*!
 * @return numero de celulas ocupadas, -1 se a area for nula
 */
int celulas_ocupadas(Area *a){
	if (a == NULL) return -1;
    return a->numCelOcupadas;
}

//! \class inserir insere uma elemento na lista de forma ordenada na Area a
/*!
 * O novo elemento e colcoado de forma ordenada na lista
 * @return SUCCES se bem sucedido, INVALID se a lista for nula e OVERFLOW se a lista estiver cheia
 */
Error_code inserir(Area *a, int valor){
    if (a == NULL) return INVALID;
    if (a->numCelOcupadas == TAMCELS) return OVERFLOW;
    if (a->numCelOcupadas == 0) { //caso a area esteja vazia
        int lugar = a->priCelulaDisp;
        a->itens[lugar].chave = valor;
        a->primeiro = lugar;
        a->ultimo = lugar;
        a->priCelulaDisp = a->itens[lugar].prox;
        a->numCelOcupadas = 1;
        a->itens[lugar].ant = -1;
        a->itens[lugar].prox = -1;
    } else {
        int it = a->primeiro;
        while (a->itens[it].chave < valor && a->itens[it].prox != -1) {
            it = a->itens[it].prox;
        }
        int atual = a->priCelulaDisp;
        a->priCelulaDisp = a->itens[atual].prox;
        //testa se a chave do it é maior que o valor
        if (a->itens[it].chave > valor) {
            //printf("INSERIR ANTES DE IT o valor = %d\n", valor);
            // posiciona antes do it
            // liga atual na lista
            a->itens[atual].prox = it;
            a->itens[atual].ant = a->itens[it].ant;
            // atribui o valor para a chave do atual
            a->itens[atual].chave = valor;
            // arruma o cursor do anterior, se o anterior existir
            if (a->itens[atual].ant != -1) a->itens[a->itens[atual].ant].prox = atual;
            // arruma o cursor do prox 
            a->itens[a->itens[atual].prox].ant = atual;
            //verificar necessidade de alterar o primeiro
            if (a->primeiro == it) a->primeiro = atual;
        //testa se a chave do it é menor ou igual ao valor   
        } else if (a->itens[it].chave <= valor) {
            // posicionar depois do it
            // liga atual na lista
            a->itens[atual].ant = it;
            a->itens[atual].prox = a->itens[it].prox;
            // atribui o valor para a chave do atual
            a->itens[atual].chave = valor;
            // arruma o cursor do anterior
            a->itens[it].prox = atual;
            // arruma o cursor do prox se este existir
            if (a->itens[atual].prox != -1) a->itens[a->itens[atual].prox].ant = atual;
            //verificar necessidade de alterar o ultimo
            if (a->ultimo == it) a->ultimo = atual;
        }
        //incrementar o contador
        a->numCelOcupadas++;
    }
    return SUCCESS;
}

//! \class retirar_primeiro  Retira o primeiro, ou seja, o menor elemento da Area a e o coloca na váriavel apontada por valor
/*!
 *  @return SUCCES se bem sucedido, INVALID se a lista for nula e UNDERFLOW se a lista estiver vazia
 */
Error_code retirar_primeiro(Area *a, int *valor){
     if (a == NULL) return INVALID;
     if (a->numCelOcupadas == 0) return UNDERFLOW;
     if (a != NULL) *valor = a->itens[a->primeiro].chave; //!< atribui o conteudo da chave do primeiro para o parametro valor
     int rmv = a->primeiro;
     //remove o primerio da lista
     a->primeiro = a->itens[rmv].prox;
     if (a->primeiro != -1) a->itens[a->primeiro].ant = -1;
     //coloca a celula removida na lista de disponiveis
     a->itens[rmv].prox = a->priCelulaDisp;
     a->priCelulaDisp = rmv;
     //ajeita a quantidade de celulas ocupadas e se necessário a ultima celula
     a->numCelOcupadas -= 1;
     if (a->numCelOcupadas == 0) a->ultimo = -1;    
     return SUCCESS; 
}

//! \class retirar_ultimo Retira o ultimo, ou seja, o maior elemento da Area a e o coloca na váriavel apontada por valor
/*!
 *  @return SUCCES se bem sucedido, INVALID se a lista for nula e UNDERFLOW se a lista estiver vazia
 */
Error_code retirar_ultimo(Area *a, int *valor){
    if (a == NULL) return INVALID;
    if (a->numCelOcupadas == 0) return UNDERFLOW;
    if (a != NULL) *valor = a->itens[a->ultimo].chave; //!< atribui o conteudo da chave do ultimo para o parametro valor
    int rmv = a->ultimo;
    //remove o ultimo da lista
    a->ultimo = a->itens[rmv].ant;
    if (a->ultimo != -1) a->itens[a->ultimo].prox = -1;
    //coloca a celula removida na lista de disponiveis
    a->itens[rmv].prox = a->priCelulaDisp;
    a->itens[rmv].ant = -1;
    a->priCelulaDisp = rmv;
    //ajeita a quantidade de celulas ocupadas e se necessário a ultima celula
    a->numCelOcupadas -= 1;
    if (a->numCelOcupadas == 0) a->primeiro = -1;
    return SUCCESS;
}

//! \class imprime_area Imprime o conteudo da area
/*!
 * Exemplos impressão: { 1 2 3 }
 * 					   { VAZIA } ->quando vazia
 */
void imprime_area(Area *a){
	if (a == NULL) return;
    int it = a->primeiro;
    if (it == -1) {
        printf("{VAZIA}");
        return;
    }
    printf("{ ");
    while (it != -1) {
        printf("%d ", a->itens[it].chave);
        it = a->itens[it].prox;
    }
    printf("}");
}

//! \class destroi_area Libera a memoria alocada para a area criada anteriormente e seta o ponteiro para NULL
/*!
 * 
 */
void destroi_area(Area **a){
	if (*a != NULL) {
		free(*a);
		*a = NULL;
	}
}

