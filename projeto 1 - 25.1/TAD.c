#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include "TAD.h"
#include "auxiliar.h"

void exibirMenu(){
    printf("\n===== Sistema de Gerenciamento de Atletas =====\n");
    printf("1 - Incluir Atletas\n");
    printf("2 - Exibir Atletas na Ordem de Inclusão\n");
    printf("3 - Exibir Atletas Ordenados por Nome\n");
    printf("4 - Exibir Ranking por Tempo de Treino\n");
    printf("5 - Filtrar Atletas por Tempo\n");
    printf("6 - Sair\n");
    printf("Escolha uma opção: ");
}

void CriarAtleta(tAtleta * atleta){
    printf("\nDigite a matrícula do atleta:");
	scanf("%i",&atleta->codigo);

	printf("\nDigite o tempo em minutos:");
	scanf("%i",&atleta->tempo);

	ObtemNome(&atleta->nome);
}

void ObtemNome(char **nome){
    char temp[100];
    int tam = 0;
    
    printf("\nDigite o nome do atleta:");
    scanf("%s", temp);
    
    tam = strlen(temp) + 1;
    
    *nome = (char*)malloc(tam * sizeof(char));
    
    strcpy(*nome,temp);
}

void ExibirAtletas(tAtleta **vetorAtletas, int numAtletas){
    int horas = 0, minutos = 0;
    
    for (int i = 0; i<numAtletas ; i++){
        horas = 0;
        minutos = 0;
        
        horario(vetorAtletas[i]->tempo, &horas, &minutos);
        
        printf("\n\nCódigo: %d | Nome: %s | Tempo: %d:%d\n",
            vetorAtletas[i]->codigo, vetorAtletas[i]->nome, horas, minutos);
    }
}

void OrdenarRanking(tAtleta **vetorAtletas, tAtleta ***vRanking, int numAtletas){
    tAtleta *temp;
    int ultimaTroca;

    for (int i = numAtletas - 1 ; i > 0; i = ultimaTroca) {
        ultimaTroca = 0;
        for (int j = 0; j < i ; j++) {
            if (vetorAtletas[j]->tempo > vetorAtletas[j + 1]->tempo) {
                temp = vetorAtletas[j];
                vetorAtletas[j] = vetorAtletas[j + 1];
                vetorAtletas[j + 1] = temp;
                ultimaTroca = j;
            }
        }
    }

    *vRanking = vetorAtletas;
}

void ExibirRanking(tAtleta **vetorAtletas, int numAtletas){
    int horas = 0, minutos = 0;
    
    printf("\n--- Ranking dos Atletas ---\n");
    for (int i = 0; i < numAtletas; i++) {
        horas = 0;
        minutos = 0;
        
        horario(vetorAtletas[i]->tempo, &horas, &minutos);
        
        printf("\n\n%dº Lugar: \n NOME: %s \n MATRICULA: %d \n TEMPO: %d:%d",
               i + 1, vetorAtletas[i]->nome, vetorAtletas[i]->codigo, horas, minutos);
    }
}

void OrdenarPorNome(tAtleta **vAtletas, tAtleta ***vOrdenado, int numAtletas){
    tAtleta *temp;
    int ultimaTroca = 0;

    *vOrdenado = (tAtleta**)malloc(numAtletas * sizeof(char*));
    for (int i = numAtletas - 1; i > 0; i = ultimaTroca) {
        ultimaTroca = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(vAtletas[j]->nome, vAtletas[j+1]->nome) > 0 || 
                (strcmp(vAtletas[j]->nome, vAtletas[j+1]->nome) == 0 && vAtletas[j]->codigo > vAtletas[j+1]->codigo)) {
                    temp = vAtletas[j];
                    vAtletas[j] = vAtletas[j+1];
                    vAtletas[j+1] = temp;
                    ultimaTroca = j;
            }
        }
    }

    *vOrdenado = vAtletas;
}

void FiltrarAtletas(tAtleta **vAtletas, tAtleta ***vPiores, int numAtletas, int limite){
    int horas, minutos;

    printf("\nAtletas com tempo superior a %d minutos:\n", limite);
    for (int i = 0; i < numAtletas; i++) {
        if (vAtletas[i]->tempo > limite) {
            horas = 0;
            minutos = 0;

            horario(vAtletas[i]->tempo, &horas, &minutos);
            
            printf("Código: %d | Nome: %s | Tempo: %02d:%02d\n", 
                   vAtletas[i]->codigo, vAtletas[i]->nome, horas, minutos);
        }
    }

    *vPiores = vAtletas;
}