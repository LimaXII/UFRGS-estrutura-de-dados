/*
Trabalho Final ED Analise de desempenho.
Situacoes escolhidas: Arvore ABP e Lista Simplesmente encadeada.
*/

//Definicao da estrutura utilizada para o programa.
typedef struct tipoNo ptLSE;
struct tipoNo{
    int numero;
    ptLSE *prox;
};

//Funcao que cria a lista.
ptLSE *criaLista(void);

//Funcao que imprime a lista.
void imprime(ptLSE *ptLista);

//Funcao que insere no fim da lista e retorna ptLista.
ptLSE *insereFim(ptLSE* ptLista, int num, double *operacoes);

//Funcao que consulta valores na lista SE
ptLSE *consulta(ptLSE *ptLista, int num, double *operacoes);

//Destroi a lista e libera memoria, retorna NULL
ptLSE *destroi(ptLSE *ptLista);