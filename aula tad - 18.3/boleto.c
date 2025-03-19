#include "data.h"
#include "boleto.h"
#include <stdio.h>

struct boleto {
    tData *dt;
    float valor;
    int n;
};

tBoleto* bol_cria(int n, float valor, tData* dtVenc){
    tBoleto* boleto = (tBoleto*)malloc(sizeof(tBoleto));

    if (boleto == NULL){
        printf("não tem memoria, irmao");
        return 1;
    }
        
    boleto-> n = n;
    boleto-> valor = valor;       
    boleto-> dt = dta_cria(2,11,2002);

    return boleto;
}

void bol_libera(tBoleto* p){
    dta_libera(p->dt);
    free(p);
}

void bol_acessa(tBoleto* p, int* n, float* val, tData* dtVenc){
    *n = p->n;
    *val = p->valor;
    dta_acessa(p->dt, 2, 11, 2002);
}