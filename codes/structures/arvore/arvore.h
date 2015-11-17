#ifndef ARVORE_H
#define ARVORE_H

#include "../common/5603_common.h"

typedef struct no No;
typedef struct arvore Arvore;

Arvore* cria_arvore();
Arvore* cria_arvore_com_raiz(long valor);
No* cria_no(long valor);
Error_code valor_no(No* no,long *dado);
Error_code arvore_insere_esq(Arvore *arv, No *no, long dado);
Error_code arvore_insere_dir(Arvore *arv, No *no, long dado);
Error_code arvore_remove_esq(Arvore *arv, No *no);
Error_code arvore_remove_dir(Arvore *arv, No *no);
Error_code arvore_remove_esq(Arvore *arv, No *no);
Error_code arvore_remove_dir(Arvore *arv, No *no);
void destroi_arvore(Arvore *arv);
int arvore_vazia(Arvore *arv);

/*Para implementar*/

/*
/ *Retorna o número de nós da árvore * /
long arv_tamanho(Arvore *arv);

/ *Retorna o nó raiz da árvore * /
No* raiz(Arvore *arv);

/ *Retorna 1 se o nó for folha, do contrário 0 * /
int eh_folha(const No *no);

/ *Retorna o filho esquerdo ou direito* /
No* arv_esquerdo(No *no);
No* arv_direito(No *no);

/ * 
 * Implemente os 3 percursos usando a árvore binária encadeada vista em aula
 * Monte uma árvore binária de expressão usando a forma pós fixa
 * Use o percurso em pós-ordem para ler a expressão na forma pós-fixa
 * Avalie o resultado da expressão com o uso auxiliar de uma pilha
 * /

*/

#endif
