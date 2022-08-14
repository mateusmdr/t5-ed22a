#include <stdlib.h>
#include "grafo.h"

int main() {
//    float preco_combustivel;
//    printf("Qual o preço do combustível (R$) ? ");
//    scanf("%f", &preco_combustivel);

    grafo_t* grafo = grafo_cria(10);
    grafo_carrega(grafo, "entrada.txt");

    return EXIT_SUCCESS;
}