#include <stdbool.h>

#include "lista.h"
#include "grafo.h"



struct vertice {
    char* chave;
    bool visitado;
    lista_t* arestas;
};