#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "grafo.h"

int main() {
    char input[64];
    printf("Qual o preço do combustível (R$/L) ? ");
    fgets(input, sizeof(input) - 1, stdin);
    float preco_combustivel = atof(input);

    grafo_t* grafo = grafo_cria(10);
    grafo_carrega(grafo, "entrada.txt");

    char origem[64], destino[64];
    char resposta;

    while(true) {
        fflush(stdin);
        printf("Qual a origem ? ");
        fgets(origem, sizeof(origem) - 1, stdin);
        origem[strlen(origem)-1] = '\0';
        printf("Qual o destino ? ");
        fgets(destino, sizeof(destino) - 1, stdin);
        destino[strlen(destino)-1] = '\0';

        grafo_menor_custo(grafo, origem, destino, preco_combustivel);
        grafo_menor_tempo(grafo, origem, destino);
        grafo_menor_distancia(grafo, origem, destino);

        printf("Deseja fazer mais alguma consulta (S/N) ? ");
        resposta = (char)fgetc(stdin);
        if(resposta == 'N' || resposta == 'n') break;
    }

    grafo_destroi(grafo);

    return EXIT_SUCCESS;
}