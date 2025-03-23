#include "Compromisso.h"
#include "Timestamp.h"

struct compromisso {
    tTimestamp *dia;
    char descricao[100];
};

tCompromisso *criarCompromisso(tTimestamp *dia, char *descricao) {
    tCompromisso *novoCompromisso = (tCompromisso *)malloc(sizeof(tCompromisso));
    novoCompromisso->dia = dia;
    strcpy(novoCompromisso->descricao, descricao);
    return novoCompromisso;
}

void imprimirCompromisso(tCompromisso *compromisso) {
    imprimirTimestamp(compromisso->dia);
    printf(" - %s", compromisso->descricao);
}

void destruirCompromisso(tCompromisso *compromisso) {
    destruirTimestamp(compromisso->dia);
    free(compromisso);
}

void adiarCompromisso(tCompromisso *compromisso, int dias) {
    somarDias(compromisso->dia->data, dias);
}

void anteciparCompromisso(tCompromisso *compromisso, int dias) {
    subtrairDias(compromisso->dia->data, dias);
}

