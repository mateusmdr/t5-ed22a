#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "grafo.h"
#include "edb.h"

struct grafo {
    int total_vertices;
    int vertices_lidos;
    vertice_t* vertices;
    edb_t* edb;
};

grafo_t* grafo_cria(int total_vertices) {
    grafo_t* grafo = malloc(sizeof(grafo_t));
    if(grafo == NULL) return NULL;

    grafo->total_vertices = total_vertices;
    grafo->vertices_lidos = 0;
    grafo->vertices = malloc(total_vertices * sizeof(vertice_t));
    grafo->edb = edb_cria();

    for(int i=0; i<total_vertices; i++) {
        vertice_t vertice;
        vertice.arestas = lista_cria(); // Cria uma lista de arestas (vazia) para cada vértice
        vertice.visitado = false;

        grafo->vertices[i] = vertice;
    }

    return grafo;
}

void grafo_destroi(grafo_t* grafo) {
    for(int i=0; i < grafo->total_vertices; i++) {
        vertice_t vertice = grafo->vertices[i];
        lista_destroi(vertice.arestas); // Destroi a lista de arestas para cada vértice
    }

    edb_destroi(grafo->edb);
    free(grafo->vertices);
    free(grafo);
}

bool grafo_cria_aresta(grafo_t* grafo, int destino, rodovia_t info) {
    return false;
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
    origem.posicao = grafo->vertices_lidos;

    if(edb_insere(grafo->edb, origem.nome, origem)) { // Insere o vértice de origem, caso não exista
        grafo->vertices_lidos++;
    }

    destino.posicao = grafo->vertices_lidos;
    if(edb_insere(grafo->edb, destino.nome, destino)) { // Insere o vértice de destino, caso não exista
        grafo->vertices_lidos++;
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