#include "Agenda.h"

Agenda *criarAgenda(int capacidade) {
    Agenda *novaAgenda = (Agenda *)malloc(sizeof(Agenda));
    novaAgenda->compromissos = (Compromisso **)malloc(capacidade * sizeof(Compromisso *));
    novaAgenda->tamanho = 0;
    novaAgenda->capacidade = capacidade;
    return novaAgenda;
}

void adicionarCompromisso(Agenda *agenda, Compromisso *compromisso) {
    if (agenda->tamanho < agenda->capacidade) {
       agenda->compromissos[agenda->tamanho++] = compromisso;
    }
}

void listarCompromissos(Agenda *agenda) {
    for (int i = 0; i < agenda->tamanho; i++) {
        printf("%d - ", i + 1);
        imprimirCompromisso(agenda->compromissos[i]);
        printf("\n");
    }
}

void removerCompromisso(Agenda *agenda, int indice) {
    if (indice >= 0 && indice < agenda->tamanho) {
        destruirCompromisso(agenda->compromissos[indice]);
        for (int i = indice; i < agenda->tamanho - 1; i++) {
            agenda->compromissos[i] = agenda->compromissos[i + 1];
        }
        agenda->tamanho--;
    }
}

void consultarCompromissoPorData(Agenda *agenda, int dia, int mes, int ano) {
    for (int i = 0; i < agenda->tamanho; i++) {
        if (agenda->compromissos[i]->dia->data->dia == dia &&
            agenda->compromissos[i]->dia->data->mes == mes &&
            agenda->compromissos[i]->dia->data->ano == ano) {
            imprimirCompromisso(agenda->compromissos[i]);
            printf("\n");
        }
    }
}

void alterarHorarioCompromisso(Agenda *agenda, int indice, int minutos, int adiar) {
    if (indice >= 0 && indice < agenda->tamanho) {
        if (adiar) {
            somarMinutosAoTimestamp(agenda->compromissos[indice]->dia, minutos);
        } else {
            subtrairMinutosDoTimestamp(agenda->compromissos[indice]->dia, minutos);
        }
    }
}

