#include <stdio.h>
#include "addLivro.h"
#include "removeLivro.h"
#include "alugaLivro.h"

#define NOMEARQLIVROS "BaseLivros.txt"
#define TAMLIV 21
#define TAMEDI 15


void menuBiblio(int tipo_usuario, char* matr)
{
    int opcao;
    int id,ret;
    char nomeLivro[TAMLIV], editora[TAMEDI];
    while(opcao != -1)
    {
        printf("Escolha uma das opcoes :\n");
        printf("1. Adicionar novo livro\n");
        printf("2. Remover Livro\n");
        printf("3. Alugar livro\n");
        printf("4. Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            // chama funcao de adiciona livro 
            // vendo qual tipo de usuario para ver o que esta
            // sendo procurado
            if(tipo_usuario == 1){

                puts("Entre com o Id, Nome do livro, Editora:");
                scanf("%d,%[^\n],%[^\n]",&id,nomeLivro,editora);

                ret = addLivro(NOMEARQLIVROS,id,nomeLivro,editora);

                if(ret == 1) puts("Livro adicionado com sucesso!");
                else puts("Livro ja existe na base!");
            }
            puts("Voce nao tem permissao para essa ação");
            break;
        case 2:
        // chama funcao de remover livro
            if (tipo_usuario == 1)
            {
                puts("Entre com o Id do livro a ser removido:");
                scanf("%d",&id);

                ret = removeLivro(NOMEARQLIVROS,id);
                switch (ret)
                {
                case 2:
                    puts("O livro a ser removido nao pode ser removido pois esta alugado");
                    break;

                case 0:
                    puts("O livro nao foi removido da base!");
                    break;
                case 1:
                    puts("Livro removido com sucesso!");
                    break;
                }
            }
            puts("Voce nao tem permissao para essa ação");
            break;
        case 3: // Alugar livro
            if(tipo_usuario == 0){
                puts("Entre com o id a ser alugado");
                scanf("%d %d",&id);

                ret = alugaLivro(NOMEARQLIVROS,id,matr);

                switch (ret)
                {
                case 2:
                    puts("Livro a ser alugado nao foi encontrado!");
                    break;
                case 1:
                    puts("Livro alugado com sucesso!");
                    break;
                case 0:
                    puts("Livro a ser alugado ja esta alugado");
                default:
                    break;
                }
            }
            break;

        case 4: //Sair
            opcao = -1;
            break;
            
        default: // escolha diferente das existentes
            puts("Escolha invalida\nTente novamente");
            opcao = 0;
            break;
        }

    }

}
