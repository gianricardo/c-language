#ifndef AREA_PRIV_H
#define AREA_PRIV_H

/*! \file myheader.h
 * \brief A Documented header file.
 *
 * Details about myheader.h.
 */
#include "area.h"

#define TAMCELS 10 /** \def Macro que determian o tamanho da area */

/*! \struct celula
 * \brief celula para a estrutura lista.
 * Chave é o valor que desejamos armazenar e ant e prox servem para posicionar a key na lista.
 */
struct celula {
    int chave;
    int ant; //!<cursor que indica a posição da celula anterior 
    int prox; //!<cursor que indica a posição da proxima celula
};

/*! \struct area
 * \brief basicamene uma lista de celulas.
 * 
 */
struct area {
    struct celula itens[TAMCELS]; //!< Vetor contendo as celulas
    int primeiro; //!< cursor que aponta o primeiro item da lista
    int ultimo;   //!< cursor que aponta o ultimo item da lista
    int priCelulaDisp; //!< cursor que aponta a primeira celula desocupada
    int numCelOcupadas; //!< indicador da quantidade de celulas ocupadas
};

//! Compara celulas acel e bcel
/*!
 * Retorno: 1 se acel > bcel
 *          0 se acel == bcel
 *          -1 se acel < bcel
 *          2 se acel ou bcel forem nulos
 */
int compCelulas(struct celula *acel, struct celula *bcel);


#endif
