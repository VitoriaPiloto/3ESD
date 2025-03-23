#include "Compromisso.h"

typedef struct {
    Compromisso **compromissos;
    int tamanho, capacidade;
} Agenda;

Agenda *criarAgenda(int capacidade);

void adicionarCompromisso(Agenda *agenda, Compromisso *compromisso);

void listarCompromissos(Agenda *agenda);

void removerCompromisso(Agenda *agenda, int indice);

void consultarCompromissoPorData(Agenda *agenda, int dia, int mes, int ano);

void alterarHorarioCompromisso(Agenda *agenda, int indice, int
    minutos, int adiar);