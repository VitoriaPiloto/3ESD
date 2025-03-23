#ifndef HORARIO_H
#define HORARIO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct horario tHorario;

tHorario *criarHorario(int hora, int minuto);
void acessarHorario(tHorario *novoHorario,int * hora, int* minuto);
void atribuirHorario(tHorario *novoHorario,int  hora, int minuto) ;
void imprimirHorario(tHorario *horario);
void destruirHorario(tHorario *horario);
void somarMinutos(tHorario *horario, int minutos);
void subtrairMinutos(tHorario *horario, int minutos);

#endif