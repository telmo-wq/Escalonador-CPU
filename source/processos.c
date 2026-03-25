#include "biblioteca.h"


void adicionar_processo(Processo **head, char *nome, int periodo, int burst){
    Processo *novo = (Processo *)malloc(sizeof(Processo));

    strcpy(novo->nome, nome);
    novo->periodo = periodo;
    novo->burst = burst;
    novo->deadline = 0;
    novo->tempo_restante = 0;
    novo->proxima_ativacao = 0;
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

