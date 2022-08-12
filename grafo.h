#ifndef GRAFO_H
#define GRAFO_H

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

typedef struct grafo grafo_t;
typedef struct aresta aresta_t;
typedef struct vertice vertice_t;

grafo_t* grafo_cria();
void grafo_carrega(char* arquivo);

#endif //GRAFO_H
