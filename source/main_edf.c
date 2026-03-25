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
    edf(arquivo);

    fclose(arquivo);
}