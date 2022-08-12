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
    no_t* ant;
    no_t* it = l->prim;
    while(it != NULL && (cont < pos || pos == -1)) {
        cont++;
        ant = it;
        it = it->prox;
    }
    if(pos == -1 || cont == pos) { // Está na posição de inserção
        ant->prox = novo;
        novo->prox = it;

        return true;
    }

    return false;
}

bool lista_remove(lista_t *l, int pos)
{
    if(lista_vazia(l)) return false;

    if(pos == 0) {
        no_t* vitima = l->prim;
        l->prim = vitima->prox;

        libera_dado(vitima->dado);
        free(vitima);

        return true;
    }

    int cont = 0;
    no_t* it = l->prim;
    no_t* ant;
    while(it->prox != NULL && (cont < pos || pos == -1)) {
        cont++;
        ant = it;
        it = it->prox;
    }

    if(pos == -1 || cont == pos) { // Está na posição a ser removida
        ant->prox = it->prox;
        libera_dado(it->dado);
        free(it);
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

    if(pos == 0) {
        *pd = l->prim->dado;
        return true;
    }

    int cont = 0;
    no_t* it = l->prim;
    while(it->prox != NULL && (cont < pos || pos == -1)) {
        cont++;
        it = it->prox;
    }

    if(pos == -1 || cont == pos) { // Está na posição a ser removida
        *pd = it->dado;
        return true;
    }

    return false;
}

void lista_imprime(lista_t* l) {
    no_t* atual = l->prim;
    while(atual != NULL) {
        imprime_dado(atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}