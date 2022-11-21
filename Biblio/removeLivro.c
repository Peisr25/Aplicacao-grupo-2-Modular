#include <stdio.h>
#include <stdlib.h>
#include "abreArquivo.h"
#define TAMLIV 21
#define TAMEDI 15
#define NOMEARQAUX "auxiliar.txt"

// retorna 2 quano o livro ja esta alugado 
// retorna 1 quando o livro é removido com sucesso
// retorna 0 quando livro nao foi removido da base
int removeLivro(char *nomeArq, int idRemover)
{
    // buscar livro para saber se ja existe
    FILE *arq;
    FILE *arqAux;
    arq = openFile(nomeArq, "r");
    arqAux = openFile(NOMEARQAUX, "w");
    char nomeLivro[TAMLIV], editora[TAMEDI];
    int idArq,alugado, matr, ret;
    while (!feof(arq))
    {
        ret = fscanf(arq, "%d , %[^,] , %[^,] , %d , %d", &idArq, nomeLivro, editora, &alugado, &matr);
        if (ret == -1) break;        
        // ler todo o arquivo se n for a linha a ser deletada, escreve
        // se for a linha a ser deletada não
        if (idArq != idRemover){
            // escreve no auxiliar
            fprintf(arqAux, "%d, %s, %s, %d, %d\n", idArq, nomeLivro, editora, alugado, matr);
        }

        else if (idArq == idRemover) {
            if (alugado == 1) {
                //retorna 2 se o livro estiver alugado
                return 2;
            }
        }

    }
    fclose(arq);
    fclose(arqAux);

    arq = openFile(nomeArq, "w");
    arqAux = openFile(NOMEARQAUX,"r");

    while (!feof(arqAux))
    {
        //le do arquivo auxiliar e escreve no principal
        ret = fscanf(arqAux, "%d , %[^,] , %[^,] , %d , %d", &idArq, nomeLivro, editora, &alugado, &matr);
        if (ret == -1) break;
        fprintf(arq,"%d, %s, %s, %d, %d\n", idArq, nomeLivro, editora, alugado, matr);
    }

    fclose(arq);
    fclose(arqAux);

    arq = openFile(nomeArq, "r");

    while (fscanf(arq, "%d , %[^,] , %[^,] , %d , %d", &idArq, nomeLivro, editora, &alugado, &matr) != EOF)
    {
        // ler todo o arquivo principal para verificar se o id foi excluido corretamente
        //se nao foi removido retorna 0
        if (idArq == idRemover)
        {
            return 0;
        }
    }
    fclose(arq);

    return 1;
}