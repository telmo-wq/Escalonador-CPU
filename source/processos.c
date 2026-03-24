#include "biblioteca.h"


void adicionar_processo(Processo **head, char *nome, int periodo, int burst){
    Processo *novo = (Processo *)malloc(sizeof(Processo));

    strcpy(novo->nome, nome);
    novo->periodo = periodo;
    novo->burst = burst;
    novo->deadline = periodo;
    novo->tempo_restante = burst;
    novo->proxima_ativacao = periodo;
    novo->LOST_DEADLINES = 0;
    novo->COMPLETE_EXECUTION = 0;
    novo->KILLED = 0;
    novo->status = 'R';
    novo->unidades_segmento = 0;
    novo->next = NULL;

    if (novo != NULL){
        if (*head == NULL){
            *head = novo;
        }else {
            Processo *aux = *head;
            while(aux->next != NULL){
                aux = aux->next;
            }
            aux->next = novo;
        }
    }
}


void imprimir_processos(Processo *head){
    Processo *aux = head;

    while(aux != NULL){
        printf("%s %d %d\n", aux->nome, aux->periodo, aux->burst);
        aux = aux->next;
    }
}