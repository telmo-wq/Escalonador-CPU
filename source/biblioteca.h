#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char nome[32];
    int periodo;
    int burst;
    int tempo_restante;
    int deadline;
} Processo;

void rate(FILE *arquivo);


void edf(FILE *arquivo);




#endif
