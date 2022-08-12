#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdbool.h>

#include "tipos.h"

typedef struct lista lista_t;

lista_t* lista_cria();
void lista_destroi(lista_t *l);

// retorna true se a lista está vazia
bool lista_vazia(lista_t *l);
// coloca em *pd o dado na posição pos da lista l sem removê-lo, retorna TRUE se bem-sucedido
bool lista_dado(lista_t *l, int pos, dado_t *pd);
// insere d na posicao pos da lista l (começando do 0, -1 para último), retorna TRUE se bem-sucedido
bool lista_insere(lista_t *l, int pos, dado_t d);
// remove o dado na posição pos da lista l (começando do 0, -1 para último), retorna TRUE se bem-sucedido
bool lista_remove(lista_t *l, int pos);
// imprime toda a lista
void lista_imprime(lista_t* l);
#endif //_LISTA_H_
