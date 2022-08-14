#ifndef TIPOS_H
#define TIPOS_H
#include "lista.h"

typedef struct {
    char trecho[64];
    float distancia;
    int classe;
    float despesas;
} rodovia_t;

typedef struct aresta aresta_t;

typedef struct {
    bool visitado;
    lista_t* arestas;
} vertice_t;

struct aresta {
    int destino;
    rodovia_t info;
};

/**
 * Funções auxiliares de dado_t (usado em lista.c)
 */
void imprime_dado(dado_t dado);
void libera_dado(dado_t dado);

typedef char chave_t[64];

typedef struct {
    int posicao;
    chave_t nome;
} valor_t;

/**
 * Funções auxiliares de valor_t (usado em edb.c)
 */
// Imprime o conteúdo de um valor_t
void imprime_valor(valor_t valor);

// Desaloca o conteúdo armazenado num valor_t (caso necessário)
void libera_valor(valor_t valor);

/**
 * Função para comparar dois valores, que retorna:
 * =0 - se são iguais
 * <0 - se chave corresponde a valor que deve estar antes do valor
 * >0 - se chave corresponde a valor que deve estar depois do valor
 */
int compara_chave_valor(chave_t chave, valor_t valor);

#endif //TIPOS_H
