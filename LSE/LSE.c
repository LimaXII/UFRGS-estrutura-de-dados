/*
Trabalho Final ED Analise de desempenho.
Situacoes escolhidas: Arvore ABP e Lista Simplesmente encadeada.
*/

#include <stdio.h>
#include <stdlib.h> //Biblioteca utilizada pra usar a funcao rand()
#include <time.h> //Biblioteca utilizada para usar a funcao clock() e time().
#include "LSE.h" //Arquivo header, contendo o cabecalho das funcoes.

//Funcao que cria a lista.
ptLSE *criaLista(void){
    return NULL;
}

//Funcao que imprime a lista.
void imprime(ptLSE *ptLista){
    ptLSE *ptaux;
    //Caso a ptlista aponte para NULL, a lista esta vazia.
    if (ptLista == NULL){
        printf("\nLista vazia. \n");
    }
    else{
        for(ptaux = ptLista; ptaux != NULL; ptaux = ptaux->prox){
            printf(" | %d ", ptaux->numero);
        }
        printf("\n");
    }
}

//Funcao que insere no fim da lista.
ptLSE *insereFim(ptLSE* ptLista, int num, double *operacoes){
    ptLSE *novo, *ptAux=ptLista;
    novo = (ptLSE*) malloc(sizeof(ptLSE));
    novo->numero = num;

    if(ptLista == NULL){ //Caso a lista esteja vazia. Ira inserir no inicio.
        novo->prox = ptLista;
        ptLista = novo;
    }
    else{
        while(ptAux->prox != NULL){ 
            *operacoes = *operacoes + 1;                       
            ptAux = ptAux->prox;
        }
        ptAux->prox = novo;
        novo->prox = NULL;
    }

    return ptLista; //Retorna ptLista
}

//Funcao que consulta valores na lista SE
ptLSE *consulta(ptLSE *ptLista, int num, double *operacoes){
    ptLSE *ptAux = ptLista;
    //Caso a ptlista aponte para NULL, a lista esta vazia.    
    if (ptLista == NULL){
        printf("\n Lista vazia. Nao existem valores para consultar. \n");
    }
    else{
        while(ptAux != NULL){            
            *operacoes = *operacoes + 1;
            if(ptAux->numero == num){
                *operacoes = *operacoes + 1;
                return ptAux;
            }
            else{
                *operacoes = *operacoes + 1;
                ptAux = ptAux->prox;
            }
        }
        return NULL;                           
    }
}

//Funcao que destroi a lista.
ptLSE *destroi(ptLSE *ptLista){
    ptLSE *ptaux;

    while (ptLista != NULL){ //Ira percorrer a lista.
        ptaux = ptLista;
        ptLista = ptLista->prox;        
        free(ptaux); //Libera a memoria utilizada.
    }
    return NULL; //Retorna NULL
}
