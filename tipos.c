#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tipos.h"

void imprime_dado(dado_t dado) {
    printf("%i\n", dado.destino);
}

void libera_dado(dado_t dado) {

}

void imprime_valor(valor_t valor) {
    printf("Nome: %s, Posição: %i\n", valor.nome, valor.posicao);
}

// Desaloca o conteúdo armazenado num valor_t (caso necessário)
void libera_valor(valor_t valor) {

};

/**
 * Função para comparar dois valores, que retorna:
 * =0 - se são iguais
 * <0 - se chave corresponde a valor que deve estar antes do valor
 * >0 - se chave corresponde a valor que deve estar depois do valor
 */
int compara_chave_valor(chave_t chave, valor_t valor) {
    return strcmp(valor.nome, chave);
}