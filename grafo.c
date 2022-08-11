#include <stdbool.h>

#include "grafo.h"

typedef struct {
    char* trecho;
    float distancia;
    unsigned int classe;
    float despesas;
} rodovia_t;

struct aresta {
    char* destino;
    rodovia_t info;
};

struct vertice {
    char* chave;
    bool visitado;
    lista_t* arestas;
};