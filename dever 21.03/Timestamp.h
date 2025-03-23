#include "Data.h"
#include "Horario.h"
#include <stdio.h>

typedef struct timestamps tTimestamp;

tTimestamp *criarTimestamp(int dia, int mes, int ano, int hora, int minuto);

void imprimirTimestamp(tTimestamp *timestamp);

void destruirTimestamp(tTimestamp *timestamp);

void somarMinutosAoTimestamp(tTimestamp *timestamp, int minutos);

void subtrairMinutosDoTimestamp(tTimestamp *timestamp, int minutos);
