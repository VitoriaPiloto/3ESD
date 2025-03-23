#include "Horario.h"

struct horario {
    int hora, minuto;
};

tHorario *criarHorario(int hora, int minuto) {
    tHorario *novoHorario = (tHorario *)malloc(sizeof(tHorario));
    novoHorario->hora = hora;
    novoHorario->minuto = minuto;
    return novoHorario;
}

void acessarHorario(tHorario *novoHorario,int * hora, int* minuto) {
    
    *hora=novoHorario->hora ;
    *minuto =novoHorario->minuto;
    return ;
}
void atribuirHorario(tHorario *novoHorario,int  hora, int minuto) {
    novoHorario->hora = hora;
    novoHorario->minuto = minuto;
    return;
}

void imprimirHorario(tHorario *horario) {
    printf("%02d:%02d", horario->hora, horario->minuto);
}

void destruirHorario(tHorario *horario) {
    free(horario);
}

void somarMinutos(tHorario *horario, int minutos) {
    horario->minuto += minutos;
    while (horario->minuto >= 60) {
        horario->minuto -= 60;
        horario->hora++;
    }
}

void subtrairMinutos(tHorario *horario, int minutos) {
    horario->minuto -= minutos;
    while (horario->minuto < 0) {
        horario->minuto += 60;
        horario->hora--;
    }
}
