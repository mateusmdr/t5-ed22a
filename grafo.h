#ifndef GRAFO_H
#define GRAFO_H
#include "tipos.h"

typedef struct grafo grafo_t;

// Cria uma nova estrutura de grafo com capacidade máxima
grafo_t* grafo_cria(int max_vertices);

// Libera a memória alocada pela estrutura criada
void grafo_destroi(grafo_t* grafo);

// Consulta e imprime o menor caminho e o custo total baseado no custo (em reais) da viagem
void grafo_menor_custo(grafo_t* grafo);

// Consulta e imprime o menor caminho e o custo total baseado no custo (em reais) da tempo
void grafo_menor_tempo(grafo_t* grafo);

// Consulta e imprime o menor caminho e o custo total baseado no custo (em reais) da distancia
void grafo_menor_distancia(grafo_t* grafo);

void grafo_carrega(grafo_t* grafo, char* arquivo);

#endif //GRAFO_H
