#include <stdlib.h>
#include <stdio.h>

#include "tipos.h"
#include "lista.h"

typedef struct no no_t;
struct no {
    no_t* prox;
    dado_t dado;
};

struct lista {
    no_t* prim;
};

lista_t* lista_cria()
{
    lista_t *l = malloc(sizeof(lista_t));
    if (l == NULL) return NULL;

    l->prim = NULL;

    return l;
}

bool lista_insere(lista_t *l, int pos, dado_t d)
{
    no_t* novo = malloc(sizeof(no_t));
    if(novo == NULL) return false;

    novo->dado = d;

    if(pos == 0) {
        novo->prox = l->prim;
        l->prim = novo;

        return true;
    }

    int cont = 0;
    no_t* it = l->prim;
    while(it->prox != NULL && cont + 1 < pos) {
        cont++;
        it = it->prox;
    }

    if(cont + 1 == pos) { // Está um antes da posição que devemos inserir
        novo->prox = it->prox;
        it->prox = novo;
        return true;
    }

    return false;
}

bool lista_remove(lista_t *l, int pos)
{
    if(lista_vazia(l)) return false;

    int cont = 0;
    no_t* atual = l->prim;
    while(atual != NULL && cont < pos) {
        cont++;
        atual = atual->prox;
    }

    if(cont == pos) {
        free(atual);
        return true;
    }

    return false;
}

void lista_destroi(lista_t *l)
{
    while(!lista_vazia(l)) {
        lista_remove(l, 0);
    }
    free(l);
}

bool lista_vazia(lista_t *l) {
    return l->prim == NULL;
}

bool lista_dado(lista_t *l, int pos, dado_t *pd)
{
    if(lista_vazia(l)) return false;
    int cont = 0;
    no_t* atual = l->prim;
    while(atual->prox != NULL && cont < pos) {
        cont++;
        atual = atual->prox;
    }

    if(cont == pos) {
        *pd = atual->dado;
        return true;
    }

    return false;
}

void lista_imprime(lista_t* l) {
    no_t* atual = l->prim;
    while(atual->prox != NULL) {
        imprime_dado(atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}