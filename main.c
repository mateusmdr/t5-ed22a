#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"

int main() {
    float preco_combustivel;
    printf("Qual o preço do combustível (R$) ? ");
    scanf("%f", &preco_combustivel);

    grafo_t* grafo = grafo_cria(10);
    grafo_carrega(grafo, "entrada.txt");

    chave_t origem, destino;
    char resposta;

    while(true) {
        printf("Qual a cidade de origem ? ");
        scanf("%s", origem);
        printf("Qual a cidade de destino ? ");
        scanf("%s", destino);

        grafo_menor_custo(grafo);
        grafo_menor_tempo(grafo);
        grafo_menor_distancia(grafo);

        printf("Deseja fazer mais alguma consulta (S/N) ? ");
        scanf(" %c", &resposta);
        if(resposta == 'N' || resposta == 'n') break;
    }

    grafo_destroi(grafo);

    return EXIT_SUCCESS;
}