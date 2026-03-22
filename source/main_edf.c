#include "biblioteca.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
    FILE *arquivo = fopen(argv[2], "r");
    if (strcmp(argv[1], "edf") == 0){
        edf(arquivo);
    }
}