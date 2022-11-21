#include <stdlib.h>
#include <stdio.h>
#include "minunit.h"
#include "alugaLivro.h"


#define NOMEARQ "BaseLivrosAlugaValido.txt"

int tests_run = 1;

static char* testesValidos(void) {
    puts("Iniciando Testes Validos!!\n");

    mu_assert("Teste alugando um livro \n", 1 == alugaLivro(NOMEARQ, 120, 2111295));
    mu_assert("Teste alugando um livro \n", 1 == alugaLivro(NOMEARQ, 121, 2111111));

    return 0;
}

static char* testes(void) {
    mu_run_test(testesValidos);
    return 0;

}

int main(void) {

    char* saida;

    saida = testes();

    if (0 != saida) {
        puts(saida);
        return EXIT_FAILURE;
    }

    puts("TESTES EXECUTADOS COM SUCESSO");
    printf("Testes executados: %d\n", tests_run);

    return EXIT_SUCCESS;

    return 0;
}