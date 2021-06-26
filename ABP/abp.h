/*
Trabalho Final ED Analise de desempenho.
Situacoes escolhidas: Arvore ABP e Lista Simplesmente encadeada.
*/

//Estrutura utilizada para a arvore ABP.
typedef int tipoinfo;
struct TNodoA{
        tipoinfo info;
        struct TNodoA *esq;
        struct TNodoA *dir;
};
typedef struct TNodoA pNodoA;

/* Funcao que insere na arvore ABP, recebe como parametro a arvore, o numero a ser inserido
e a variavel operacoes, que ira contar o numero de operacoes realizadas durante toda a operacao */
pNodoA* InsereArvore(pNodoA *a, tipoinfo ch, double *operacoes);

//Consulta um nodo da arvore.
pNodoA* ConsultaABP(pNodoA *a, tipoinfo chave, double *operacoes);

//Funcao que destroi a arvore utilizada.
void destroi_arvore(pNodoA *arv);
