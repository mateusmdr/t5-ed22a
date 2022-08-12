#include <stdio.h>
#include <stdlib.h>

#include "tipos.h"

void imprime_dado(dado_t dado) {
    printf("%s\n", dado.destino);
}

void libera_dado(dado_t dado) {
    free(dado.destino);
}