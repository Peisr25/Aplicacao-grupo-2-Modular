#include <stdio.h>
#include <stdlib.h>
#include "abreArquivo.h"
#define NOMEARQAUX "auxiliar.txt"
#define TAMLIV 21
#define TAMEDI 15

// retorna 2 quando o livro não foi encontrado 
// retorna 1 quando foi possivel alugar o livro
// retorna 0 quando o livro a ser alugado já está alugado
int alugaLivro(char* nomeArq, int idLivro,int matr){
    FILE* arq = openFile(nomeArq,"r");
    FILE* arqAux = openFile(NOMEARQAUX,"w");
    char nomeLivroTemp[TAMLIV], editoraTemp[TAMEDI];
    int idArq,ret,alugadoTemp, matrTemp, comp = 0;

    while (!feof(arq))
    {
        ret = fscanf(arq, "%d , %[^,] , %[^,] , %d , %d", &idArq, nomeLivroTemp, editoraTemp, &alugadoTemp, &matrTemp);
        if (ret == -1)
            break;
        if(idArq == idLivro){
            //achou o livro a ser alugado
            if(alugadoTemp == 1){
                //verifica se o livro já está alugado
                //e retorna 0 se ja esta alugado
                return 0;
            }
            alugadoTemp = 1;
            comp = 1; // variavel utilizada para verificar se o livro a ser alugado foi encontrado 
            fprintf(arqAux, "%d, %s, %s, %d, %d", idArq, nomeLivroTemp, editoraTemp, alugadoTemp, matr);
        }
        //não achou o livro a ser alugado
        fprintf(arqAux, "%d, %s, %s, %d, %d", idArq, nomeLivroTemp, editoraTemp, alugadoTemp, matrTemp);
    }
    fclose(arq);
    fclose(arqAux);

    if(comp == 0){
        //retorna 2 quando o livro a ser alugado nao foi encontrado
        return 2;
    }

    arq = openFile(nomeArq, "w");
    arqAux = openFile(NOMEARQAUX,"r");

    while (!feof(arqAux))
    {
        //le do arquivo auxiliar e escreve no principal
        ret = fscanf(arqAux, "%d , %[^,] , %[^,] , %d , %d", &idArq, nomeLivroTemp, editoraTemp, &alugadoTemp, &matr);
        if (ret == -1) break;
        fprintf(arq,"%d, %s, %s, %d, %d", idArq, nomeLivroTemp, editoraTemp, alugadoTemp, matr);
    }

    fclose(arq);
    fclose(arqAux);
    return 1;

}