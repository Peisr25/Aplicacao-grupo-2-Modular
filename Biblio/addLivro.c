#include <stdio.h>
#include <stdlib.h>
#include "abreArquivo.h"
#define TAMLIV 21
#define TAMEDI 15

//retorna 1 quando o livro é cadastrado com sucesso
//retorna 0 quando livro ja existe na base
int addLivro(char *nomeArq, int id, char *nomeLivro, char *editora, int matr)
{
    // buscar livro para saber se ja existe
    int comp = 0;
    FILE *arq;
    arq = openFile(nomeArq, "r");
    int idArq;
    while (!feof(arq))
    {
        if (fscanf(arq, "%[^,]", idArq) != 1)
            break;
        if (idArq == id)
        {
            // retorna 0 se livro existe na base
            comp = 1;
            return 0;
        }
    }
    fclose(arq);
    if (comp == 0)
    {
        //cadastra um novo livro
        int alugado = 0;
        arq = openFile(nomeArq, "a");
        fprintf(arq, "%d, %s, %s, %d, %d", id, nomeLivro, editora, alugado, matr);
        fclose(arq);
    }
    return 1;
}