#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include "grafo.h"
#include "edb.h"

struct grafo {
    int max_vertices;
    int total_vertices;
    vertice_t* vertices;
    edb_t* edb;
};

grafo_t* grafo_cria(int max_vertices) {
    grafo_t* grafo = malloc(sizeof(grafo_t));
    if(grafo == NULL) return NULL;

    grafo->max_vertices = max_vertices;
    grafo->total_vertices = 0;
    grafo->vertices = malloc(max_vertices * sizeof(vertice_t));
    grafo->edb = edb_cria();

    for(int i=0; i<max_vertices; i++) {
        vertice_t vertice;
        vertice.arestas = lista_cria(); // Cria uma lista de arestas (vazia) para cada vértice
        vertice.visitado = false;

        grafo->vertices[i] = vertice;
    }

    return grafo;
}

void grafo_destroi(grafo_t* grafo) {
    for(int i=0; i < grafo->max_vertices; i++) {
        vertice_t vertice = grafo->vertices[i];
        lista_destroi(vertice.arestas); // Destroi a lista de arestas para cada vértice
    }

    edb_destroi(grafo->edb);
    free(grafo->vertices);
    free(grafo);
}

void grafo_carrega_linha(grafo_t* grafo, char* linha) {
    rodovia_t info;

    char* posicoes[7];

    /**
    * Divide a linha em cada entrada separada por vírgula
    */
    char* token = strtok(linha, ",");
    for(int entrada = 0; entrada < 7; entrada++){
        posicoes[entrada] = token;
        token = strtok(NULL, ",");
    }

    valor_t origem, destino;
    strcpy(info.trecho, posicoes[0]);
    strcpy(origem.nome, posicoes[1]);
    strcpy(destino.nome, posicoes[2]);
    bool dupla = atoi(posicoes[3]) == 2;
    info.distancia = atof(posicoes[4]);
    info.classe = atoi(posicoes[5]);
    info.despesas = atof(posicoes[6]);

    // Inserção dos vértices:
    origem.posicao = grafo->total_vertices;

    if(edb_insere(grafo->edb, origem.nome, origem)) { // Insere o vértice de origem, caso não exista
        grafo->total_vertices++;
    }

    destino.posicao = grafo->total_vertices;
    if(edb_insere(grafo->edb, destino.nome, destino)) { // Insere o vértice de destino, caso não exista
        grafo->total_vertices++;
    }

    // Inserção das arestas:

    assert(edb_busca(grafo->edb, destino.nome, &destino));
    assert(edb_busca(grafo->edb, origem.nome, &origem));

    aresta_t aresta;
    aresta.info = info;

    aresta.destino = destino.posicao;
    assert(lista_insere(grafo->vertices[origem.posicao].arestas, 0, aresta));

    if(dupla) {
        aresta.destino = origem.posicao;
        assert(lista_insere(grafo->vertices[destino.posicao].arestas, 0, aresta));
    }
}

void grafo_carrega(grafo_t* grafo, char* nome) {
    FILE* arquivo = fopen(nome, "r");
    if(arquivo == NULL) return;
    char linha[256];
    while(fgets(linha, sizeof(linha)-1, arquivo) != NULL) {
        grafo_carrega_linha(grafo, linha);
    }

    fclose(arquivo);
}

int vertice_encontra(grafo_t* grafo, char* nome) {
    valor_t vertice;
    if(!edb_busca(grafo->edb, nome, &vertice)) {
        printf("Erro: cidade não encontrada!");
        return -1;
    }

    return vertice.posicao;
}

typedef struct {
    float* distancia;
    int* pai;
} dijkstra_t;

/**
 *
 * @param grafo Grafo usado na busca
 * @param origem Index do vértice de origem da busca
 * @param peso Ponteiro para função que retorna o peso de uma aresta
 */
dijkstra_t dijkstra(grafo_t* grafo, int origem, float(*peso)(aresta_t)) {
    int total_vertices = grafo->total_vertices;
    vertice_t* vertices = grafo->vertices;
    float distancia[total_vertices];
    int pai[total_vertices];

    /**
     * Inicia os nós como não visitados, com distância infinita
     */
    for(int i=0; i < total_vertices; i++) {
        vertices[i].visitado = false;
        distancia[i] = INFINITY;
        pai[i] = -1;
    }
    // Exceto o nó de origem
    distancia[origem] = 0;
    vertices[origem].visitado = true;

    int visitados = 0;
    while(visitados < total_vertices) {
        float dist_min = INFINITY;
        int n;
        for(int i=0; i < total_vertices; i++) {
            if(vertices[i].visitado) continue;

            if(distancia[i] < dist_min) {
                dist_min = distancia[i];
                n = i;
                visitados++;
            }
        }
        vertices[n].visitado = true;

        aresta_t aresta;
        for(int i=0; lista_dado(vertices[n].arestas, i, &aresta); i++) {
            int d = aresta.destino;
            float n_dist = distancia[n] + peso(aresta);
            if(n_dist < distancia[d]) {
                distancia[d] = n_dist;
                pai[d] = n;
            }
        }
    }
    dijkstra_t resultado;
    resultado.pai = malloc(sizeof(int) * total_vertices);
    resultado.distancia = malloc(sizeof(float) * total_vertices);

    memcpy(resultado.pai, pai, sizeof(int) * total_vertices);
    memcpy(resultado.distancia, distancia, sizeof(float) * total_vertices);

    return resultado;
}

float get_consumo_aresta(aresta_t aresta) {
    /**
     * Para o cálculo do custo em R$, considere os pedágios e o consumo de combustível médio,
     * que varia de acordo com a classe do trecho, entre 12km/l para a classe 5 e
     * 1 km/l a menos para cada classe subsequente.
     */
    int consumo = 12 - (5 - aresta.info.classe);

    return aresta.info.despesas;
}

float get_tempo_aresta(aresta_t aresta) {
    /**
     * Para o cálculo do custo em tempo,
     * considere que a velocidade média de acordo com a classe do trecho, 100km/h para classe 5 e
     * 12km/h a menos para cada classe subsequente.
     */
    int velocidade = 100 - 12 * (5 - aresta.info.classe);

    return aresta.info.distancia / (float)velocidade;
}

float get_distancia_aresta(aresta_t aresta) {
    return aresta.info.distancia;
}

// Consulta e imprime o menor caminho e o custo total baseado no custo (em reais) da viagem
void grafo_menor_custo(grafo_t* grafo, char* nome_origem, char* nome_destino, float preco_combustivel) {
    int origem = vertice_encontra(grafo, nome_origem);
    int destino = vertice_encontra(grafo, nome_destino);

    dijkstra(grafo, origem, get_consumo_aresta);
}

// Consulta e imprime o menor caminho e o custo total baseado no custo (em reais) da tempo
void grafo_menor_tempo(grafo_t* grafo, char* origem, char* destino) {

}

// Consulta e imprime o menor caminho e o custo total baseado no custo (em reais) da distancia
void grafo_menor_distancia(grafo_t* grafo, char* origem, char* destino) {

}