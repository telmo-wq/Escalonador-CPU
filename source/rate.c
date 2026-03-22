#include "biblioteca.h"



void rate(FILE *arquivo){
    char linha[200];
    int total_time;
    Processo *head = NULL;

    fgets(linha, sizeof(linha), arquivo);
    sscanf(linha, "%d", &total_time);

    while(fgets(linha, sizeof(linha), arquivo) != NULL){
        char nome[32];
        int periodo;
        int burst;
        sscanf(linha, "%s %d %d", nome, &periodo, &burst);
        adicionar_processo(&head, nome, periodo, burst);
    }
    fclose(arquivo);

    imprimir_processos(head);
}