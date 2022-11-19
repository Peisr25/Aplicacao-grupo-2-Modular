#include <stdlib.h>
#include <stdio.h>
#include "minunit.h"
#include "removeLivro.h"
#include "addLivro.h"
#include "abreArquivo.h"

#define NOMEARQ "BaseLivros.txt"

int tests_run = 0;

static char *testesValidos(void){
    puts("Iniciando Testes Validos!!\n");

    mu_assert("Teste adicionando um novo livro \n", 1==addLivro(NOMEARQ, 120,"Jogos Vorazes", "Rocco",2111295));
    mu_assert("Teste adicionando um novo livro \n", 1==addLivro(NOMEARQ, 121,"Crônicas de Gelo Fogo", "Leya",2321223));
    mu_assert("Teste adicionando um novo livro \n", 1==addLivro(NOMEARQ, 122,"Diário de Um Banana", "VR Editora",23232231));
    mu_assert("Teste removendo o livro de código 121 \n", 1==removeLivro(NOMEARQ, 121));
    mu_assert("Teste removendo o livro de código 122 \n", 1==removeLivro(NOMEARQ, 122));

}

static char * testesInvalidos(void){
    puts("Iniciando testes Invalidos!!\n");

    mu_assert("Teste removendo livro que está alugado", 2==removeLivro(NOMEARQ,121));
    mu_assert("Teste adicionando livro que ja existe", 0==addLivro(NOMEARQ, 122,"Diário de Um Banana", "VR Editora",23232231));
}

static char *testes(void) {
    mu_run_test(testesValidos);
    //mu_run_test(testesInvalidos);

    return 0;

}

int main(void){

    //FILE* arq = openFile(NOMEARQ, "w");

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