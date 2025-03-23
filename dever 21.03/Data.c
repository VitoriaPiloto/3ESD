#include "Data.h"

struct data {
    int dia, mes, ano;
};

int ehBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int diasNoMes(int mes, int ano) {
    int diasMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (mes == 2 && ehBissexto(ano)) return 29;
    return diasMes[mes - 1];
}

tData *criarData(int dia, int mes, int ano) {
    tData *novaData = (tData *)malloc(sizeof(tData));
    novaData->dia = dia;
    novaData->mes = mes;
    novaData->ano = ano;
    return novaData;
}

void imprimirData(tData *data) {
    printf("%02d/%02d/%04d", data->dia, data->mes, data->ano);
}

void destruirData(tData *data) {
    free(data);
}

void somarDias(tData *data, int dias) {
    while (dias > 0) {
        int diasRestantes = diasNoMes(data->mes, data->ano) - data->dia;
        if (dias > diasRestantes) {
            dias -= (diasRestantes + 1);
            data->dia = 1;
            if (++data->mes > 12) {
                data->mes = 1;
                data->ano++;
            }
        } else {
            data->dia += dias;
            dias = 0;
        }
    }
}

void subtrairDias(tData *data, int dias) {
    while (dias > 0) {
        if (dias >= data->dia) {
            dias -= data->dia;
            if (--data->mes < 1) {
                data->mes = 12;
                data->ano--;
            }
            data->dia = diasNoMes(data->mes, data->ano);
        } else {
            data->dia -= dias;
            dias = 0;
        }
    }
}