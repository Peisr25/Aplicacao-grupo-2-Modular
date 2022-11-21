#include <stdlib.h>
#include <stdio.h>
#include "minunit.h"
#include "removeLivro.h"
#include "addLivro.h"
#include "abreArquivo.h"

#define NOMEARQ "BaseLivrosInvalidos.txt"

int tests_run = 1;

static char * testesInvalidos(void){
    puts("Iniciando testes Invalidos!!\n");

    mu_assert("Teste removendo livro que está alugado", 2==removeLivro(NOMEARQ,121));
    mu_assert("Teste adicionando livro que ja existe", 0==addLivro(NOMEARQ, 122,"Diário de Um Banana", "VR Editora",23232231));
}

static char *testes(void) {
    mu_run_test(testesInvalidos);

    return 0;

}

int main(void){;

    char *saida;

    saida = testes();

    if(0!=saida) {
        puts(saida);
        return EXIT_FAILURE;
    }

    puts("TESTES EXECUTADOS COM SUCESSO");
    printf("Testes executados: %d\n", tests_run);

    return EXIT_SUCCESS;

    return 0;
}