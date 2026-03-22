#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Processo {
    char nome[32];
    int periodo;
    int burst;
    int tempo_restante;
    int deadline;
    struct Processo *next;
} Processo;

void rate(FILE *arquivo);


void edf(FILE *arquivo);

void adicionar_processo(Processo **head, char *nome, int periodo, int burst);

void imprimir_processos(Processo *head);


#endif
