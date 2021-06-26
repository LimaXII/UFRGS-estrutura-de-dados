/*
Trabalho Final ED Analise de desempenho.
Situacoes escolhidas: Arvore ABP e Lista Simplesmente encadeada.
*/

#include <stdio.h>
#include <stdlib.h> //Biblioteca utilizada pra usar a funcao rand()
#include <time.h> //Biblioteca utilizada para usar a funcao clock() e time().
#include <windows.h> //Biblioteca utilizada para usar a funcao sleep().
#include "abp.h" //Arquivo header, contendo o cabecalho das funcoes.
#define qtd_valores 1000000 //Quantidade de valores que serao inseridos na arvore.

int main()
{
    //Declaracao de variaveis.
    pNodoA *arv = NULL, *arv1 = NULL, *nodo_consultado = NULL;
    double cpu_time_used;
    int i, nodo, operacoes_totais = 0;
    double operacoes = 0, tempo_total = 0;    
    clock_t start, end; //Variaveis que irao controlar o tempo decorrido durante a execucao do programa.

    //---------------------------Teste de tempo de insercao com valores aleatorios---------------------------
    printf("\n------ Teste de tempo com valores aleatorios. ------\n");

    //Inicia a contagem do tempo.   
    start = clock();

    /* Inicializa o gerador de números aleatorios com o valor da função time(NULL). 
    Este valor eh calculado como sendo o total de segundos passados desde 1 de janeiro de 1970 ate a data atual do sistema. */
    srand(time(NULL)); 
    for(i = 0; i < qtd_valores; i++)
    {        
        operacoes++;    
        arv = InsereArvore(arv,(rand() % 1000000), &operacoes);        
    }
    //Finaliza a contagem do tempo.
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    //Informa o tempo que levou para a execucao do prograna.
    printf("Tempo para inserir %d valores aleatorios: %f (em segundos).\n", qtd_valores, cpu_time_used);
    //Informa o numero de operacoes durante o programa (==, !=, <, <=, >, >=).
    printf("Numero de operacoes realizadas: %.0lf\n\n", operacoes);

    //Zera o conteudo das variaveis. 
    start = 0;
    end = 0;
    operacoes = 0;
    cpu_time_used = 0;

    //---------------------------Teste de tempo de consulta com valores aleatorios---------------------------
    printf("\n------ Teste de consulta com valores aleatorios. ------\n");

    //Funcao Sleep() utilizada para atrasar o programa. Deste modo, os numeros aleatorios serao gerados de maneira diferente.
    Sleep(2000);
    //Conforme explicado anteriormente, o horario atual ira criar uma ordem aleatoria nova para a geracao dos numeros.
    srand(time(NULL));

    //For utilizado para consultar 5 valores.
    for(i = 0; i < 5; i++){  
        printf(" %d ", i);   
        //Gera o numero aleatorio.   
        nodo = (rand() % 1000000);          
        //Inicia a contagem do tempo.
        start = clock();
        //Chama a funcao procurando o valor.
        nodo_consultado = ConsultaABP(arv, nodo, &operacoes);

        //Apos achar o valor, pausa o relogio e calcula o tempo de execucao.
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        
        //Informa para o usuario o tempo de execucao e a quantidade de operacoes realizadas.
        printf("Tempo para consultar o valor %d na arvore: %f (em segundos).\n", nodo, cpu_time_used);
        printf("Numero de operacoes realizadas: %.0lf\n", operacoes);

        //Zera as variaveis novamente, para testar o proximo valor.
        //Aqui, tambem eh utilizado duas variaveis acumuladoras, as quais serao explicadas em breve.
        start = 0;
        end = 0;
        operacoes_totais = operacoes_totais + operacoes;
        operacoes = 0;
        tempo_total = tempo_total + cpu_time_used;
        cpu_time_used = 0;
    }

    //Utiliza a variavel acumuladora tempo_real para adquirir a media do tempo das 5 consultas realizadas.
    //Informa o tempo medio para o usuario.
    printf("\nMedia do tempo para a realizacao das 5 consultas:");
    tempo_total = (tempo_total / 5);
    printf(" %lf (em segundos) \n", tempo_total);

    //Utiliza a variavel acumuladora operacoes_totais para adquirir a media das operacoes feitas nas 5 consultas realizadas.
    //Informa as operacoes medias para o usuario.
    printf("\nMedia das operacoes realizadas nas 5 consultas:");
    operacoes_totais = (operacoes_totais / 5);
    printf(" %d \n", operacoes_totais);

    //Chama a funcao destroi_arvore para limpar a memoria alocada do sistema.
    destroi_arvore(arv);    

    //---------------------------Teste de tempo com valores ordenados---------------------------
    printf("\n------ Teste de tempo com valores ordenados. ------\n");

    //Inicia a contagem do tempo.  
    start = clock();

    //Insere os valores ordenados na arvore.
    for(i=0; i<qtd_valores; i++)
    {        
        operacoes++; 
        arv1 = InsereArvore(arv1, i, &operacoes);        
    }

    //Finaliza a contagem do tempo.
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    //Informa o tempo que levou para a execucao do prograna.
    printf("\nTempo para inserir %d valores ordenados: %f (em segundos).\n", qtd_valores, cpu_time_used);
    //Informa o numero de operacoes durante o programa (==, !=, <, <=, >, >=).
    printf("Numero de operacoes realizadas: %.0lf\n", operacoes);

    //Zera o conteudo das variaveis. 
    start = 0;
    end = 0;
    operacoes = 0;
    cpu_time_used = 0;

    //---------------------------Teste de tempo de consulta com valores ordenados---------------------------
    printf("\n------ Teste de consulta com valores ordenados. ------\n");
    //Consulta do primeiro nodo. Este nodo sempre sera o numero 0.
    start = clock();
    nodo_consultado = ConsultaABP(arv1, 0, &operacoes);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    //Informa para o usuario o tempo para consultar o primeiro valor da arvore.
    printf("\nTempo para consultar o valor 0 na arvore: %f (em segundos).\n", cpu_time_used);
    printf("Numero de operacoes realizadas: %.0lf", operacoes);
    start = 0;
    end = 0;
    operacoes = 0;
    cpu_time_used = 0;

    //Consulta o nodo do meio da arvore.
    start = clock();
    nodo = ((qtd_valores -1)/ 2);
    nodo_consultado = ConsultaABP(arv1, nodo, &operacoes);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    //Informa para o usuario o tempo para consultar o valor medio da arvore.
    printf("\n\nTempo para consultar o valor %d na arvore: %f (em segundos).\n", nodo, cpu_time_used);
    printf("Numero de operacoes realizadas: %.0lf", operacoes);
    start = 0;
    end = 0;
    operacoes = 0;
    cpu_time_used = 0;

    //Consulta o ultimo nodo da arvore.
    start = clock();    
    nodo = (qtd_valores - 1);
    nodo_consultado = ConsultaABP(arv1, nodo, &operacoes);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    //Informa para o usuario o tempo para consultar o ultimo valor da arvore.
    printf("\n\nTempo para consultar o valor %d na arvore: %f (em segundos).\n", nodo, cpu_time_used);
    printf("Numero de operacoes realizadas: %.0lf", operacoes);
    start = 0;
    end = 0;
    operacoes = 0;
    cpu_time_used = 0;

    //Chama a funcao destroi_arvore para limpar a memoria alocada do sistema.
    destroi_arvore(arv1);

    //Fim do programa.
    return 0;
}
