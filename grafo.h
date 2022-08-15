#ifndef GRAFO_H
#define GRAFO_H
#include "tipos.h"

typedef struct grafo grafo_t;

// Cria uma nova estrutura de grafo com capacidade máxima
grafo_t* grafo_cria(int max_vertices);

// Libera a memória alocada pela estrutura criada
void grafo_destroi(grafo_t* grafo);

// Consulta e imprime o menor caminho e o custo total baseado no custo (em reais) da viagem
void grafo_menor_custo(grafo_t* grafo, char* nome_origem, char* nome_destino);

// Consulta e imprime o menor caminho e o custo total baseado no tempo para chegar da origem ao destino
void grafo_menor_tempo(grafo_t* grafo, char* nome_origem, char* nome_destino);

// Consulta e imprime o menor caminho e o custo total baseado na distância percorrida
void grafo_menor_distancia(grafo_t* grafo, char* nome_origem, char* nome_destino);

void grafo_carrega(grafo_t* grafo, char* arquivo);

void set_preco_combustivel(float preco);

#endif //GRAFO_H
