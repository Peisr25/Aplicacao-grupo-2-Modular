#include <stdio.h>
#include <stdlib.h>
#include "abreArquivo.h"
#define TAMLIV 21
#define TAMEDI 15

//retorna 1 quando o livro é cadastrado com sucesso
//retorna 0 quando livro ja existe na base
int addLivro(char *nomeArq, int id, char *nomeLivro, char *editora)
{
    // buscar livro para saber se ja existe
    int comp = 0;
    FILE *arq;
    arq = openFile(nomeArq, "r");
    char nomeLivroTemp[TAMLIV], editoraTemp[TAMEDI];
    int idArq,ret,alugadoTemp, matrTemp;
    while (!feof(arq))
    {
        ret = fscanf(arq, "%d , %[^,] , %[^,] , %d , %d", &idArq, nomeLivroTemp, editoraTemp, &alugadoTemp, &matrTemp);
        if (ret == -1)
            break;
        if (idArq == id)
        {
            // retorna 0 se livro existe na base
            return 0;
        }
        
    }
    fclose(arq);
    if (comp == 0)
    {
        //cadastra um novo livro
        int alugado = 0;
        arq = openFile(nomeArq, "a");
        fprintf(arq, "%d, %s, %s, %d", id, nomeLivro, editora, alugado);
        fclose(arq);
    }
    return 1;
}