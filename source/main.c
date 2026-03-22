#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "biblioteca.h"


int main(int argc, char *argv[]){
    FILE *arquivo = fopen(argv[2], "r");
    if (strcmp(argv[1], "rate") == 0){
        rate(arquivo);

    }else if (strcmp(argv[1], "edf") == 0){
        edf(arquivo);
    }
}