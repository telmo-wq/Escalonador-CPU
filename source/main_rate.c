#include "biblioteca.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
    if (argc > 2){
        printf("ERRO! Certifique-se de passar apenas dois parâmetros!\n");
        return 0;
    }
    FILE *arquivo = fopen(argv[1], "r");

    if (arquivo == NULL){
        printf("ERRO! Certifique-se de passar um arquivo existente\n");
        return 0;
    }

    char *tipo_de_arquivo = strstr(argv[1], ".txt");

    if (tipo_de_arquivo == NULL){
        printf("ARQUIVO INVÁLIDO! Certifique-se que o arquivo passado seja do tipo .txt\n");
        return 0;
    }

    rate(arquivo);

    fclose(arquivo);
}