#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include "TAD.h"

int main() {
    int numAtletas = 0, opcao, limite;
    tAtleta **vAtletas = NULL;
    tAtleta **vOrdenado = NULL;
    tAtleta **vRanking = NULL;
    do {
        exibirMenu();
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Quantos atletas deseja cadastrar? ");
                scanf("%d", &numAtletas);
                vAtletas = (tAtleta **)malloc(numAtletas * sizeof(tAtleta *));
                for(int i = 0; i < numAtletas; i++) {
                    vAtletas[i] = (tAtleta *)malloc(sizeof(tAtleta));
                    CriarAtleta(vAtletas[i]);
                }
                break;
            case 2:
                printf("\nAtletas na ordem de inclusão:\n");
                ExibirAtletas(vAtletas, numAtletas);
                break;
            case 3:
                printf("\nAtletas ordenados por nome:\n");
                OrdenarPorNome(vAtletas, &vOrdenado, numAtletas);
                ExibirAtletas(vOrdenado, numAtletas);
                break;
            case 4:
                printf("\nRanking por tempo de treino:\n");
                OrdenarRanking(vAtletas, &vRanking, numAtletas);
                ExibirRanking(vAtletas, numAtletas);
                break;
            case 5:
                printf("\nDigite um tempo limite para filtrar atletas: ");
                scanf("%d", &limite);
                FiltrarAtletas(vAtletas, numAtletas, limite);
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 6);
    
    return 0;
}
