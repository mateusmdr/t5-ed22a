#ifndef GRAFO_H
#define GRAFO_H
#include "tipos.h"

typedef struct grafo grafo_t;

grafo_t* grafo_cria(int n_vertices);
void grafo_destroi(grafo_t* grafo);

bool grafo_cria_aresta(grafo_t* grafo, int destino, rodovia_t info);

void grafo_carrega(grafo_t* grafo, char* arquivo);

#endif //GRAFO_H
