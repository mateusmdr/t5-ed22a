#ifndef GRAFO_H
#define GRAFO_H

typedef struct grafo grafo_t;
typedef struct aresta aresta_t;
typedef struct vertice vertice_t;

grafo_t* grafo_cria();
void grafo_carrega(char* arquivo);



#endif //GRAFO_H
