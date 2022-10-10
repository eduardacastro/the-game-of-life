#include "jogador_listaEncCircular.h"
#include <stdio.h>
#include <stdlib.h>


// Funcao que cria uma lista
ListaEncCircularJogador* criaJogador(){
   ListaEncCircularJogador *jogador = (ListaEncCircularJogador*)malloc(sizeof(ListaEncCircularJogador));
   jogador->prim = NULL;
   return jogador;
}


// Funcao que destroi uma lista
void destroiListaCircularJogador(ListaEncCircularJogador *lista){
   NodoLEncCircularJogador *aux = lista->prim;
   while(aux != NULL){
       NodoLEncCircularJogador *tmp = aux->prox;
       free(aux); // Cuidar ordem do free
       aux = tmp;
   }
   free(lista);
}


// Funcao que imprime todos os nodos de uma lista
void imprimeJogador(ListaEncCircularJogador *jogadores){
    NodoLEncCircularJogador *aux;
	int flag = 0;
    printf("\n\t-----------------------------------------------------\n");

   	for(aux = jogadores->prim; flag != 1; aux = aux->prox){
   	      	printf("\t%d | posicao:%d dinheiro: %d familia: %d salario: %d\n", aux->info.numJogador,
                                                           aux->info.posicao,
                                                           aux->info.dinheiro,
                                                           aux->info.familia,
                                                           aux->info.salario);
    	if(aux == jogadores->fim){
    		flag++; // quando chega no fim da lista a flag se torna 1 e com isso, nao ha mais interaçoes do for
		}
   		printf("\t-----------------------------------------------------\n");
   }
}


// Funcao que insere um nodo no inicio de uma lista
int insereInicioListaJogador(ListaEncCircularJogador *jogador, InfoJogador info){
    NodoLEncCircularJogador *novo = (NodoLEncCircularJogador*)malloc(sizeof(NodoLEncCircularJogador));

    if (jogador->prim == NULL){
        novo->info = info;
        jogador->prim = novo;
        jogador->fim = novo;
        novo->prox = jogador->prim;
    return 1;
    }

    novo->info = info;
    novo->prox = jogador->prim;
    jogador->prim = novo;
    jogador->fim->prox = jogador->prim;
    return 1;
}


// Funcao que inicia os Jogadores
ListaEncCircularJogador* iniciaJogadores(){
	int retorno;
	ListaEncCircularJogador *lista;
	lista = criaJogador();

	InfoJogador info1 = {1,0,0,10000,1};
	InfoJogador info2 = {2,0,0,10000,1};

    retorno = insereInicioListaJogador(lista, info2); // retorno = 1
	retorno = insereInicioListaJogador(lista, info1); // retorno = 1
    imprimeJogador(lista);

    return lista;
}

