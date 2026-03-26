#include "biblioteca.h"



void rate(FILE *arquivo){
    char linha[200];
    int total_time;
    Processo *head = NULL;

    fgets(linha, sizeof(linha), arquivo);
    sscanf(linha, "%d", &total_time);

    while(fgets(linha, sizeof(linha), arquivo) != NULL){  //alocando cada processo na lista
        char nome[32];
        int periodo;
        int burst;
        sscanf(linha, "%s %d %d", nome, &periodo, &burst);
        adicionar_processo(&head, nome, periodo, burst);
    }

    int menor_periodo;

    Processo *processo_atual = NULL;
    Processo *processo_anterior = NULL;

    int unidades_idle = 0;

    FILE *log = fopen("rate_tmfc.out", "w");
    fprintf(log, "EXECUTION BY RATE\n");
    fprintf(log, "\n");

    for (int t = 0; t < total_time; t++){   //loop principal
        menor_periodo = 100000;
        processo_atual = NULL;


        Processo *aux2 = head;    //checar deadlines vencidos
        while(aux2 != NULL){
            if (aux2->status != 'R'){
                if(aux2->deadline == t && aux2->tempo_restante > 0){
                    aux2->LOST_DEADLINES++;
                    aux2->tempo_restante = 0;
                    aux2->status = 'L';   
                }
            }
            aux2 = aux2->next;
        }

        Processo *aux = head;
        while(aux != NULL){                     //ativa próximas instâncias (checa qual será a próxima instância a ser executada)
            if (aux->proxima_ativacao == t){
                aux->tempo_restante = aux->burst;
                aux->deadline = t + aux->periodo;
                aux->proxima_ativacao = t + aux->periodo;
                
            }
            aux = aux->next;   
        }


        if(processo_anterior != NULL && processo_anterior->status == 'L'){
            fprintf(log, "[%s] for %d units - %c\n", processo_anterior->nome, processo_anterior->unidades_segmento, processo_anterior->status);
            processo_anterior->unidades_segmento = 0;
            processo_anterior->status = 'R';
            processo_anterior = NULL;
        }
        

        Processo *aux3 = head;  
        while(aux3 != NULL){                //percorre a lista de processos e vê qual tem maior prioridade (menor periodo)
            if (aux3->tempo_restante > 0){
                if (aux3->periodo < menor_periodo){
                    menor_periodo = aux3->periodo;
                    processo_atual = aux3;
                }
            }
            aux3 = aux3->next;
        }

        if (processo_atual == NULL){      //caso o processo atual esteja em idle, ele checa se o processo anterior foi finalizado ou se foi preemptado e registra
            unidades_idle++;
            if (processo_anterior != NULL){
                if (processo_anterior->tempo_restante > 0){
                    processo_anterior->status = 'H';
                    fprintf(log, "[%s] for %d units - %c\n", processo_anterior->nome, processo_anterior->unidades_segmento, processo_anterior->status);
                }else {
                    processo_anterior->status = 'F';
                    processo_anterior->COMPLETE_EXECUTION++;
                    fprintf(log, "[%s] for %d units - %c\n", processo_anterior->nome, processo_anterior->unidades_segmento, processo_anterior->status);
                }
                processo_anterior->unidades_segmento = 0;
                processo_anterior = NULL;
            }
        } else if (processo_atual != NULL && unidades_idle > 0){
            fprintf(log, "idle for %d units\n", unidades_idle);
            unidades_idle = 0;
        }

        if (processo_atual != processo_anterior && processo_anterior != NULL){     //se o processo atual for diferente do anterior, então algo aconteceu com ele (preemptado, perdido ou finalizado)
            if(processo_anterior->tempo_restante > 0){
                processo_anterior->status = 'H';


            }else if (processo_anterior->tempo_restante == 0){
                processo_anterior->status = 'F';
                processo_anterior->COMPLETE_EXECUTION++;

            }else{
                processo_anterior->status = 'L';
                processo_anterior->LOST_DEADLINES++;

            }
            fprintf(log, "[%s] for %d units - %c\n", processo_anterior->nome, processo_anterior->unidades_segmento, processo_anterior->status);

            processo_anterior->unidades_segmento = 0;
        }

        if (processo_atual != NULL){
            processo_atual->unidades_segmento++;
            processo_atual->tempo_restante--;

            if(processo_atual->tempo_restante == 0){
                processo_atual->status = 'F';
            }

            processo_anterior = processo_atual;
        }
    }
    Processo *pointer = head;
    while(pointer != NULL){
        if (pointer->tempo_restante > 0){
            pointer->status = 'K';
            pointer->KILLED++;

            fprintf(log, "[%s] for %d units - %c\n", pointer->nome, pointer->unidades_segmento, pointer->status);
        }
        pointer = pointer->next;
    }


    Processo *pointer2 = head;

    fprintf(log, "\nLOST DEADLINES\n");     //checa e exibe as lost_deadlines
    while(pointer2 != NULL){
        fprintf(log, "[%s] - %d\n", pointer2->nome, pointer2->LOST_DEADLINES);
        pointer2 = pointer2->next;
    }

    Processo *pointer3 = head;
    fprintf(log, "\nCOMPLETE EXECUTION\n");

    while(pointer3 != NULL){
        fprintf(log, "[%s] - %d\n", pointer3->nome, pointer3->COMPLETE_EXECUTION);
        pointer3 = pointer3->next;
    }

    Processo *pointer4 = head;
    fprintf(log, "\nKILLED\n");
    while(pointer4 != NULL){             //checa processos abortados depois que o loop acabou (killed)
        if (pointer4->tempo_restante > 0){
            fprintf(log, "[%s] - %d\n", pointer4->nome, pointer4->KILLED);
            pointer4->unidades_segmento = 0;
        }
        pointer4 = pointer4->next;
    }

    fclose(log);
}