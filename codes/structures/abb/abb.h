#ifndef _ABB_H
#define _ABB_H

#include "../common/comum.h"
#include <stdbool.h>

typedef struct arvorebb_t ArvBB;

/**
 * Criar árvore binária de busca.
 *
 * @param mostrar
 * @param destruir
 * @param compara
 * @return
 */
ArvBB*      arv_criar       (void (*mostrar)(void *data),
                             void (*destruir)(void *data),
                             int (*compara)(void *key1, void* key2));
/**
 * Destruir a árvore binária de busca.
 *
 * @param arv
 * @return
 */
codigo_erro arv_destruir    (ArvBB** arv);
/**
 * Verifica se a árvore está vazia.
 *
 * @param arv
 * @return
 */
bool        arv_vazia       (const ArvBB* arv);
/**
 * Consulta o tamnho da árvore, em quantidades de itens inseridos e não repetidos.
 *
 * @param arv
 */
long        arv_tamanho     (const ArvBB* arv);
/**
 * Insere um item na árvore.
 *
 * @param arv
 * @param data
 * @return
 */
codigo_erro arv_insere      (ArvBB* arv, void* data);
/**
 * Remove um item da árvore (se ele existir).
 *
 * @param arv
 * @param data
 * @return
 */
codigo_erro arv_remove       (ArvBB* arv, void* data);
codigo_erro arv_remove2      (ArvBB* arv, void* data);
//Caminhamentos
void        arv_preordem    (const ArvBB* arv);
void        arv_inordem     (const ArvBB* arv);
void        arv_posordem    (const ArvBB* arv);
bool        arv_busca       (const ArvBB* arv, void* info);
bool        arv_busca_bin   (const ArvBB* arv, void* info);
void        arv_mostra_busca(const ArvBB* arv);
void        arv_preordem_it (const ArvBB* arv);

#endif
