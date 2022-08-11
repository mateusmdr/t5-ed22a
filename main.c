#include <stdlib.h>
#include <stdio.h>

#include "lista.h"
#include "tipos.h"

int main(void) {
//    float preco_combustivel;
//    printf("Qual o preço do combustível (R$) ? ");
//    scanf("%f", &preco_combustivel);

    lista_t* l = lista_cria();

    lista_insere(l, 0,1);
    lista_insere(l, 0,3);
    lista_insere(l, 0,1);
    lista_insere(l, 0,8);
    lista_insere(l, 0,20);

    dado_t dado;

//    lista_dado(l, 1, &dado);
//    printf("%i",dado);
//
//    lista_dado(l, 4, &dado);
//    printf("%i",dado);
//
//    lista_dado(l, 3, &dado);
//    printf("%i",dado);
//
//    lista_dado(l, 5, &dado);
//    printf("%i",dado);

    lista_imprime(l);
    return EXIT_SUCCESS;
}