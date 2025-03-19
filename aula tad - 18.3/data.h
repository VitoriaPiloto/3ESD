typedef struct data tData;

/* Funções exportadas */

/* Função cria - Aloca e retorna uma data dia/mês/ano */

tData* dta_cria(int dia, int mes, int ano);

/* Função libera – Libera memória de uma Data criada */

void dta_libera(tData* p);

/* Função acessa - Retorna os valores de uma Data */

void dta_acessa(tData* p, int* dia, int* mes, int* ano);

/* Função atribui - Atribui novos valores à Data */

void dta_atribui(tData* p, int dia, int mes, int ano);

/* Função intervalo - Retorna a data após X dias */

tData* dta_intervalo(tData* p1, int X);

/* Função exibe – Escreve na tela a data no formato dd/mm/aaaa */

tData* dta_exibe(tData* p1);

/* Função getData - Retorna uma string com a data no formato dd/mm/aaaa*/

char* dta_getData(tData* p);