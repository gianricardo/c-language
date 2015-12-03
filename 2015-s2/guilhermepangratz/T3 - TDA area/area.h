#ifndef AREA_H
#define AREA_H

#include "5603_common.h"

typedef struct area Area; //<! Estrutura definida no arquivo privado

//! \class cria_area_vazia Cria uma area vazia e inicializa seus elementos para que eles funcionem da maneira desejada
/*!
 * Cria a lista com tamnho definido pela macro TAMCELS do arquivo privado.
 * @return ponteiro para a área criada
 */
Area *cria_area_vazia();

//! \class celulas_ocupadas Retorna a quantidade de celulas ocupadas, e -1 se for uma area nula
/*!
 * @return numero de celulas ocupadas, -1 se a area for nula
 */
int celulas_ocupadas(Area *a);

//! \class inserir insere uma elemento na lista de forma ordenada na Area a
/*!
 * O novo elemento e colcoado de forma ordenada na lista
 * @return SUCCES se bem sucedido, INVALID se a lista for nula e OVERFLOW se a lista estiver cheia
 */
Error_code inserir(Area *a, int valor);

//! \class retirar_primeiro  Retira o primeiro, ou seja, o menor elemento da Area a e o coloca na váriavel apontada por valor
/*!
 *  @return SUCCES se bem sucedido, INVALID se a lista for nula e UNDERFLOW se a lista estiver vazia
 */
Error_code retirar_primeiro(Area *a, int *valor);

//! \class retirar_ultimo Retira o ultimo, ou seja, o maior elemento da Area a e o coloca na váriavel apontada por valor
/*!
 *  @return SUCCES se bem sucedido, INVALID se a lista for nula e UNDERFLOW se a lista estiver vazia
 */
Error_code retirar_ultimo(Area *a, int *valor);

//! \class imprime_area Imprime o conteudo da area
/*!
 * Exemplos impressão: { 1 2 3 }
 * 					   { VAZIA } ->quando vazia
 */
void imprime_area(Area *a);

//! \class destroi_area Libera a memoria alocada para a area criada anteriormente e seta o ponteiro para NULL
/*!
 * 
 */
void destroi_area(Area **a);

#endif
