#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "grafo.h"

int main() {
    char input[64];
    printf("Qual o preço do combustível (R$/L) ? ");
    fgets(input, sizeof(input) - 1, stdin);
    fflush(stdin);
    set_preco_combustivel(atof(input));

    grafo_t* grafo = grafo_cria(30);
    grafo_carrega(grafo, "entrada.txt");

    char origem[64], destino[64];

    while(true) {
        printf("Qual a origem ? ");
        fgets(origem, sizeof(origem) - 1, stdin);
        fflush(stdin);
        origem[strlen(origem)-1] = '\0';
        printf("Qual o destino ? ");
        fgets(destino, sizeof(destino) - 1, stdin);
        fflush(stdin);
        destino[strlen(destino)-1] = '\0';

        grafo_menor_custo(grafo, origem, destino);
        grafo_menor_tempo(grafo, origem, destino);
        grafo_menor_distancia(grafo, origem, destino);

        printf("Deseja fazer mais alguma consulta (S/N) ? ");
        fgets(input, sizeof(input) - 1, stdin);
        fflush(stdin);
        if(input[0] == 'N' || input[0] == 'n') break;
    }

    grafo_destroi(grafo);

    return EXIT_SUCCESS;
}