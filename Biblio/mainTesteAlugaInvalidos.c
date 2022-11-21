#include <stdlib.h>
#include <stdio.h>
#include "minunit.h"
#include "alugaLivro.h"


#define NOMEARQ "BaseLivrosAlugaInvalido.txt"

int tests_run = 1;

static char* testesInvalidos(void) {
    puts("Iniciando Testes Validos!!\n");

    mu_assert("Teste alugando um livro ja alugado \n", 0 == alugaLivro(NOMEARQ, 120, 2111295));
    mu_assert("Teste alugando um livro que nao exite \n", 2 == alugaLivro(NOMEARQ, 122, 2111111));

    return 0;
}

static char* testes(void) {
    mu_run_test(testesInvalidos);
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