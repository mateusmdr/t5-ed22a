#include <stdlib.h>
#include <assert.h>

#include "lista.h"
#include "tipos.h"

void test_lista_insere() {
    lista_t* l = lista_cria();
    assert(lista_insere(l, 0,0));
    assert(lista_insere(l, 1,3));
    assert(lista_insere(l, 1,8));
    assert(lista_insere(l, 3,1));
    assert(lista_insere(l, -1,9));
    assert(lista_insere(l, 2,2));
    dado_t dado;
    assert(lista_dado(l, 0, &dado));
    assert(dado == 0);

    assert(lista_dado(l, 1, &dado));
    assert(dado == 8);

    assert(lista_dado(l, 2, &dado));
    assert(dado == 2);

    assert(lista_dado(l, 3, &dado));
    assert(dado == 3);

    assert(lista_dado(l, 4, &dado));
    assert(dado == 1);

    assert(lista_dado(l, 5, &dado));
    assert(dado == 9);

    lista_destroi(l);
}

void test_lista_remove() {
    lista_t* l = lista_cria();
    assert(lista_insere(l, 0,0));
    assert(lista_insere(l, 1,3));
    assert(lista_insere(l, 1,8));

    assert(lista_remove(l, 2));

    assert(lista_insere(l, 2,1));
    assert(lista_insere(l, -1,9));

    assert(lista_remove(l, 3));

    assert(lista_insere(l, 2,2));
    lista_imprime(l);
    dado_t dado;
    assert(lista_dado(l, 0, &dado));
    assert(dado == 0);

    assert(lista_dado(l, 1, &dado));
    assert(dado == 8);

    assert(lista_dado(l, 2, &dado));
    assert(dado == 2);

    assert(lista_dado(l, 3, &dado));
    assert(dado == 1);

    lista_destroi(l);
}

int main() {
//    float preco_combustivel;
//    printf("Qual o preço do combustível (R$) ? ");
//    scanf("%f", &preco_combustivel);

    test_lista_insere();

    test_lista_remove();

    return EXIT_SUCCESS;
}