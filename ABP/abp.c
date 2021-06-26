/*
Trabalho Final ED Analise de desempenho.
Situacoes escolhidas: Arvore ABP e Lista Simplesmente encadeada.
*/

#include <stdio.h>
#include <stdlib.h> //Biblioteca utilizada pra usar a funcao rand()
#include <time.h> //Biblioteca utilizada para usar a funcao clock() e time().
#include "abp.h" //Arquivo header, contendo o cabecalho das funcoes.

//Funcao que insere nodos na arvore.
pNodoA* InsereArvore(pNodoA *a, tipoinfo ch, double *operacoes)
{
    //Aloca memoria do novo nodo que sera inserido na arvore.
    pNodoA *novo;
    novo =  (pNodoA*) malloc(sizeof(pNodoA));    
    novo->info = ch;
    novo->dir = NULL;
    novo->esq = NULL;   

    //Caso a arvore nao tenha nenhum nodo, a raiz ira receber o nodo novo.
    if(a == NULL){
        //Adiciona mais um ao numero de operacoes totais realizadas.
        *operacoes = *operacoes + 1;
        a = novo;
    }
    //Caso a arvore nao esteja vazia.
    else{
        //Declaracao de dois ponteiros do tipo pNodoA, para percorrerem a arvore.
        pNodoA *atual = a;
        pNodoA *ant = NULL;

        //Enquanto o ponteiro atual nao estiver apontando para NULL.
        while(atual != NULL){
            *operacoes = *operacoes + 1;
            //O ponteiro anterior sempre estara uma posicao atras do ponteiro atual.
            ant = atual;
            //Caso o valor a ser colocado seja maior ou igual ao nodo atual da arvore, vai para a direita.
            if(ch >= atual->info){
                *operacoes = *operacoes + 1;
                atual = atual->dir;
            }
            //Caso o valor a ser colocado seja menor do que o nodo atual da arvore, vai para a esquerda.
            else if (ch < atual->info){
                *operacoes = *operacoes + 1;
                atual = atual->esq;
            }
        }
        //Quando atual == NULL, o programa ira testar em qual folha devera ser colocado o novo nodo.
        //Se o valor a ser colocado for maior ou igual que o anterior->info, coloca o valor no nodo da direita.
        if(ch >= ant->info){
            *operacoes = *operacoes + 1;
            ant->dir = novo;
        }
        //Se o valor a ser colocado for menor que o anterior->info, coloca o valor no nodo da esquerda.
        else if (ch < ant->info){
            *operacoes = *operacoes + 1;
            ant->esq = novo;
        }
    }
    //Retorna a arvore.
    return a;
}

//Consulta um nodo da arvore.
pNodoA* ConsultaABP(pNodoA *a, tipoinfo chave, double *operacoes){
    //Enquanto o ponteiro nao estiver apontando para NULL...
    while (a != NULL){
        ////Adiciona mais um ao numero de operacoes totais realizadas.
        *operacoes = *operacoes + 1;
        //Se o valor a ser procurado for igual ao valor apontado pelo ponteiro a->info, retorna a arvore.
        if (a->info == chave){
            *operacoes = *operacoes + 1;
            return a;
        }       
        //Senao, testa se o valor procurado eh menor ou maior que o nodo atual para qual o ponteiro esta apontando.     
        else{
            //Se for menor, vai para a esquerda.
            if(a->info > chave){
                *operacoes = *operacoes + 1;
                a = a->esq;
            }         
            //Se for maior, vai para a direita.       
            else{
                *operacoes = *operacoes + 1;
                a = a->dir;
            }
        }
    }
    //Caso nao encontre o valor, retorna NULL.
    return NULL;
}
  
//Funcao que destroi a arvore.
void destroi_arvore(pNodoA *arv)
{
    //Caso a arvore aponte para NULL, retorna.
    if(arv == NULL){
        return;
    }

    //Chama recursivamente a arvore para a esquerda e direita e volta limpando a memoria alocada.
    destroi_arvore(arv->esq);
    destroi_arvore(arv->dir);
    free(arv);
}
