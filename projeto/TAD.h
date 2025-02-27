typedef struct atleta {
    int codigo, tempo;
    char *nome;
} tAtleta;

void exibirMenu();
void CriarAtleta(tAtleta *atleta);
void ObtemNome(char **nome);
void ExibirAtletas(tAtleta **vetorAtletas, int numAtletas);
void OrdenarRanking(tAtleta **vetorAtletas, int numAtletas);
void ExibirRanking(tAtleta **vetorAtletas, int numAtletas);
void OrdenarPorNome(tAtleta **vAtletas, tAtleta ***vOrdenado, int numAtletas);
void FiltrarAtletas(tAtleta **vAtletas, int numAtletas, int limite);
void ExibirAtletasOrdenado(tAtleta **vetorAtletas, int numAtletas);