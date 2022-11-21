#include <stdio.h>
#include <string.h>
#include "menuLogin.h"
#include "menuBiblio.h"

#define TAMUSU 21

int main(void)
{
    int retorno, tipo_usuario = -1;
    int check = -1;
    FILE *arq;
    char matr[TAMUSU];
    while (tipo_usuario == -1)
    {
        printf("Esolha o tipo da sua conta :\n");
        printf("1. Usuario\n");
        printf("2. Funcionario\n");
        scanf("%d", &tipo_usuario);
        if (tipo_usuario != 1 && tipo_usuario != 2)
        {
            printf("Escolha invalida\n");
            tipo_usuario = -1;
        }
    }

    // chama menuLogin
    // pergunto a matricula e senha dentro da funcao
    // pego de volta para usar aqui
    strcpy(matr, fazLogin(tipo_usuario, &check));
    printf("Matr : %s\n", matr);
    // login bem sucedido
    // chama menu sau com tipo de usuario
    // tudo vai ser feito dentro do modulo menusau
    // menusau chama as outras funcoes
    if(check == 0)
        menuBiblio(tipo_usuario, matr);
    // quando voltar eh porque quer sair
    return 0;
}

// para sair do while colocar valor qualquer na variavel
// tipo usuario e assim vai terminar o programa
// pessoa ja vai ter feito tudo que deseja dentro da pla
// taforma