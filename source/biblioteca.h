#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Processo {
    char *nome;
    int periodo;
    int burst;
    int tempo_restante;
    int deadline;
    int proxima_ativacao;
    int LOST_DEADLINES;
    int COMPLETE_EXECUTION;
    int KILLED;
    char status;
    int unidades_segmento;
    struct Processo *next;
} Processo;

void rate(FILE *arquivo);


void edf(FILE *arquivo);

void adicionar_processo(Processo **head, char *nome, int periodo, int burst);

void imprimir_processos(Processo *head);


#endif
