#include "Timestamp.h"
#include "Data.h"
#include "Horario.h"

struct timestamps {
    tData *data;
    tHorario *horario;
};

tTimestamp *criarTimestamp(int dia, int mes, int ano, int hora, int minuto) {
    tTimestamp *novoTimestamp = (tTimestamp *)malloc(sizeof(tTimestamp));
    novoTimestamp->data = criarData(dia, mes, ano);
    novoTimestamp->horario = criarHorario(hora, minuto);
    return novoTimestamp;
}

void imprimirTimestamp(tTimestamp *timestamp) {
    imprimirData(timestamp->data);
    printf(" ");
    imprimirHorario(timestamp->horario);
}

void destruirTimestamp(tTimestamp *timestamp) {
    destruirData(timestamp->data);
    destruirHorario(timestamp->horario);
    free(timestamp);
}

void somarMinutosAoTimestamp(tTimestamp *timestamp, int minutos) {
    somarMinutos(timestamp->horario, minutos);
    if (timestamp->horario->hora >= 24) {
        timestamp->horario->hora -= 24;
        somarDias(timestamp->data, 1);
    }
}

void subtrairMinutosDoTimestamp(tTimestamp *timestamp, int minutos) {
    subtrairMinutos(timestamp->horario, minutos);
    if (timestamp->horario->hora < 0) {
        timestamp->horario->hora += 24;
        subtrairDias(timestamp->data, 1);
    }
}

