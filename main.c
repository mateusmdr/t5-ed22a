#include <stdlib.h>
#include <stdio.h>

int main(void) {
    float preco_combustivel;
    printf("Qual o preço do combustível (R$) ? ");
    scanf("%f", &preco_combustivel);

    printf("\n Preço digitado: %f\n", preco_combustivel);
    return EXIT_SUCCESS;
}