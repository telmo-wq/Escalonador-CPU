#include "biblioteca.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
    FILE *arquivo = fopen(argv[1], "r");
    rate(arquivo);

    fclose(arquivo);
}