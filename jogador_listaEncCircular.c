#include "jogador_listaEncCircular.h"
#include <stdio.h>
#include <stdlib.h>


ListaEncCircular* criaJogador(){
   ListaEncCircular *lista = (ListaEncCircular*)malloc(sizeof(ListaEncCircular));
   lista->prim = NULL;
   return lista;
}

// Funcao que destroi uma lista
void destroiLista(ListaEncCircular *lista){
   NodoLEncCircular *aux = lista->prim;
   while(aux != NULL){
       NodoLEncCircular *tmp = aux->prox;
       free(aux); // Cuidar ordem do free
       aux = tmp;
   }
   free(lista);
}

// Funcao que imprime todos os nodos de uma lista
void imprimeJogador(ListaEncCircular *lista){
    NodoLEncCircular *aux;
	int flag = 0;
    printf("-----------------------------------------\n");
   
   	for(aux = lista->prim; flag != 1; aux = aux->prox){
   	      	printf("%d | posicao:%d dinheiro: %d familia: %d\n", aux->info.numJogador,
                                                           aux->info.posicao,
                                                           aux->info.dinheiro,
                                                           aux->info.familia);
    	if(aux == lista->fim){
    		flag++;
		}
   		printf("-----------------------------------------\n");
   }
}

// Funcao que insere um nodo no inicio de uma lista
int insereInicioLista(ListaEncCircular *lista, Info info){
    NodoLEncCircular *novo = (NodoLEncCircular*)malloc(sizeof(NodoLEncCircular));
   
    if (lista->prim == NULL){
        novo->info = info;
        lista->prim = novo;
        lista->fim = novo;
        novo->prox = lista->prim;
    return;
    }

    novo->info = info;
    novo->prox = lista->prim;
    lista->prim = novo;
    lista->fim->prox = lista->prim;
    return 1;
}

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEncCircular* buscaInfoLista(ListaEncCircular* lista, int num){
   NodoLEncCircular *aux;
   int i = 0;
   aux = lista->prim;
   for(i = 1; i <= num; i++){
		printf("%d\n", i);
		printf("num %d \n", aux->info.numJogador);
        	aux = aux->prox;
   }
  
   return NULL; 
}

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoLista(ListaEncCircular* lista, int numJogador){
    NodoLEncCircular* ant = NULL;
    NodoLEncCircular *aux = lista->prim; 
    while(aux != NULL && aux->info.numJogador != numJogador){
        ant = aux;
        aux = aux->prox;
    }
    if (aux != NULL){
        if (ant == NULL)
            lista->prim = aux->prox;
        else
            ant->prox = aux->prox;
            free(aux);
            return 1;
    }
    return 0; // Nao encontrou
}

void iniciaJogador(){
	int retorno, numJogadores;
	ListaEncCircular *lista;
	lista = criaJogador();
       
	Info info1 = {1,0,10000,1};
	Info info2 = {2,0,10000,1};
	Info info3 = {3,0,10000,1};
	Info info4 = {4,0,10000,1};

    printf("Quantos jogadores iram jogar?");
    scanf("%d", &numJogadores);
	
    switch (numJogadores)
    {
    case 1:
        retorno = insereInicioLista(lista, info1);
        imprimeJogador(lista);
        break;
    case 2:
        retorno = insereInicioLista(lista, info2); // retorno = 1
	    retorno = insereInicioLista(lista, info1); // retorno = 1
	    imprimeJogador(lista);
        break;
    case 3:
    	retorno = insereInicioLista(lista, info3); // retorno = 1
        retorno = insereInicioLista(lista, info2); // retorno = 1
        retorno = insereInicioLista(lista, info1); // retorno = 1
        imprimeJogador(lista);
        break;
    case 4:
        retorno = insereInicioLista(lista, info4); // retorno = 1
        retorno = insereInicioLista(lista, info3); // retorno = 1
        retorno = insereInicioLista(lista, info2); // retorno = 1
        retorno = insereInicioLista(lista, info1); // retorno = 1
        imprimeJogador(lista);
        break;
    default:
        printf("\n\n\t\tVoce deve escolher um numero de jogadores entre 1 e 4!\n");
        break;
    }
	
}

void fimRoleta(){
	//destroiLista(lista);
}

