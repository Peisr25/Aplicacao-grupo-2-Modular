#include <stdio.h>
#include <stdlib.h>
#include "abreArquivo.h"
#define TAMLIV 21
#define TAMEDI 15

//retorna 1 quando o livro é cadastrado com sucesso
//retorna 0 quando livro ja existe na base
int removeLivro(char *nomeArq, int idRemover)
{
    // buscar livro para saber se ja existe
    int comp = 0;
    FILE *arq;
    FILE *arqAux;
    arq = openFile(nomeArq, "r");
    arqAux = openFile("auxiliar.txt","a");
    int idArq;
    char nomeLivro[TAMLIV], editora[TAMEDI];
    int id, alugado, matr;
    while (!feof(arq))
    {
        //ler todo o arquivo se n for a linha a ser deletada, escreve
        //se for a linha a ser deletada não 
        if (fscanf(arq, "%[^,]", idArq) != 1)
            break;
        if (idArq != idRemover)
        {
            fscanf(arqAux,"%d , %[^,] , %[^,] , %d , %d",&id, nomeLivro, editora, &alugado, &matr);
            //escreve no auxiliar
           fprintf(arqAux, "%d, %s, %s, %d, %d", id, nomeLivro, editora, alugado, matr);
        }
    }
    fclose(arq);
    if (comp == 1)
    {
        //remove o livro 
        int alugado = 0;
        arq = openFile(nomeArq, "a");
        fprintf(arq, "%d, %s, %s, %d, %d", id, nomeLivro, editora, alugado, matr);
        fclose(arq);
    }
    return 1;
}