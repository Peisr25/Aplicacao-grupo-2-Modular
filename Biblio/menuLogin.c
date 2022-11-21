#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "menuLogin.h"
#include "login.h"
#include "abreArquivo.h"
#include "cadastro.h"
#include "trocaSenha.h"

#define TAMUSU 21
#define TAMSE 15
#define TAMNOMEARQ 100
#define ARQUSU "../cadastroSauUsu.txt"
#define ARQFUNC "../cadastroSauFunc.txt"

// faz login de usuario ou cadastra
// plataforma desejada vai chamar esse modulo
// check serve para saber se pessoa conseguiu fazer login
char* fazLogin(int tipo_usuario, int *check)
{
    int opcao, retorno;
    FILE* arq;
    char *matr, senha[TAMSE];
    matr = (char*)malloc(sizeof(char)*TAMUSU);
    char nomeArq[100];
    printf("Voce deseja :\n");
    printf("1. Fazer login\n");
    printf("2. Fazer cadastro\n");
    printf("3. Trocar senha\n");
    scanf("%d", &opcao);
    if(tipo_usuario == 1)
        strcpy(nomeArq, ARQUSU);
    else
        strcpy(nomeArq, ARQFUNC);

    while(opcao != -1)
    {
        printf("Entre com o usuario : \n");
        scanf(" %[^\n]", matr);
        printf("Entre com a senha : \n");
        scanf(" %[^\n]", senha);
        switch (opcao)
        {
        case 1:
            // abre arquivo so para leitura 
            arq = openFile(nomeArq, "r");
            retorno = buscaArq(arq, matr, senha); // manda arquivo aberto 
            if(retorno == 0 )
            {
                printf("Login bem sucedido\n");
                opcao = -1;
                *check = 0;
                // login bem sucedido entao sai do while
            }
            else 
            {
                printf("Usuario ou senha invalida\n");
                printf("1. Tentar novamente\n2. Trocar senha\n");
                scanf("%d", &opcao);
                if(opcao == 2)
                {
                    opcao = 3; // volta o while e entra no caso 3
                }
            }
            fclose(arq);
            break;
        case 2:
            // tenho que mandar o nome do arquivo para a funcao
            // abrir e fechar arquivo dentro da funcao 
            retorno = cadastrar(nomeArq, matr, senha);
            if(retorno == 1)
            {
                printf("Cadastrado com sucesso ");
                printf("Deseja fazer login :\n");
                printf("1. Sim\n2. Nao\n");
                scanf("%d", &opcao);
                if (opcao == 2)
                    opcao = -1; // sai do while
            }
            else if(retorno == 0)
            // retorna 0 usuario ja existe e vc esta tentando cadastrar de novo com senha errada        
            // quer cadastrar senha ou tentar cadastrar novamente 
            {
                printf("Usuario ja existe com senha diferente\n\n");
                printf("Deseja :\n");
                printf("1. Fazer login novamente\n2. Trocar senha\n");
                scanf("%d", &opcao);
                if(opcao == 2)
                    opcao = 3;

            }
            else 
            {
                printf("Usuario e senha ja foram cadastrados previamente\n");
                printf("Deseja fazer login\n");
                printf("1. Sim\n2. Nao\n");
                scanf("%d", &opcao);
                if(opcao == 2)
                    opcao = -1; // sai do while 
            }
            break;
        case 3:
        // mando o nome arquivo e abro ele na funcao 
        // porque vou ter que abrir o mesmo arquivo 2 vezes
            trocaSenha(nomeArq, matr, senha);
            printf("Deseja fazer login :\n");
            printf("1. Sim\n2. Nao\n");
            scanf("%d", &opcao);
            if (opcao == 2)
                opcao = -1;
            break; // sai do while
        default:
            printf("Escolha invalida\nTente novamente : \n");
            scanf("%d", &opcao); // volta para o while
            break;
        }
    }
    return matr;
    // se o programa continuar eh porque fez login
}
