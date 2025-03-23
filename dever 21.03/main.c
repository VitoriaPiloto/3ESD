#include "Agenda.h"
#include "Compromisso.h"
#include "Timestamp.h"
#include "Data.h"
#include <stdio.h>

int main(){
    int opcao;
    Agenda *agenda;
    do {
        printf("1 - Criar agenda\n");
        printf("2 - Adicionar compromisso\n");
        printf("3 - Listar compromissos\n");
        printf("4 - Remover compromisso\n");
        printf("5 - Consultar compromisso por data\n");
        printf("6 - Alterar horario do compromisso\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: {
                int capacidade;
                printf("Capacidade da agenda: ");
                scanf("%d", &capacidade);
                agenda = criarAgenda(capacidade);
                break;
            }
            case 2: {
                int dia, mes, ano, hora, minuto;
                char descricao[100];
                printf("Dia: ");
                scanf("%d", &dia);
                printf("Mes: ");
                scanf("%d", &mes);
                printf("Ano: ");
                scanf("%d", &ano);
                printf("Hora: ");
                scanf("%d", &hora);
                printf("Minuto: ");
                scanf("%d", &minuto);
                printf("Descricao: ");
                scanf(" %[^\n]", descricao);
                Timestamp *timestamp = criarTimestamp(dia, mes, ano, hora, minuto);
                Compromisso *compromisso = criarCompromisso(timestamp, descricao);
                adicionarCompromisso(agenda, compromisso);
                break;
            }
            case 3: {
                listarCompromissos(agenda);
                break;
            }
            case 4: {
                int indice;
                printf("Indice: ");
                scanf("%d", &indice);
                removerCompromisso(agenda, indice - 1);
                break;
            }
            case 5: {
                int dia, mes, ano;
                printf("Dia: ");
                scanf("%d", &dia);
                printf("Mes: ");
                scanf("%d", &mes);
                printf("Ano: ");
                scanf("%d", &ano);
                consultarCompromissoPorData(agenda, dia, mes, ano);
                break;
            }
            case 6: {
                int indice, minutos, adiar;
                printf("Indice: ");
                scanf("%d", &indice);
            }
        }
    } while (opcao != 0);
    return 0;
}
