#include <stdio.h>
#include "biblioteca.h"


void rate(FILE *arquivo){
    printf("Lendo o arquivo em modo rate\n");

    fclose(arquivo);
}


void edf(FILE *arquivo){
    printf("Lendo o arquivo em modo edf\n");

    fclose(arquivo);
}