#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct data tData;

tData *criarData(int dia, int mes, int ano);
void imprimirData(tData *data);
void destruirData(tData *data);
void somarDias(tData *data, int dias);
void subtrairDias(tData *data, int dias);

#endif