#include "Timestamp.h"

typedef struct compromisso tCompromisso;

tCompromisso *criarCompromisso(tTimestamp *dia, char *descricao);

void imprimirCompromisso(tCompromisso *compromisso);

void destruirCompromisso(tCompromisso *compromisso);

void adiarCompromisso(tCompromisso *compromisso, int dias);

void anteciparCompromisso(tCompromisso *compromisso, int dias);

