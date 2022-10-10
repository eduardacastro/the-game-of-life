#include "roleta_listaEncCircular.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funcao que cria uma lista
ListaEncCircularRoleta* criaLista(){
   ListaEncCircularRoleta *lista = (ListaEncCircularRoleta*)malloc(sizeof(ListaEncCircularRoleta));
   lista->prim = NULL;
   return lista;
}

// Funcao que insere um nodo no inicio de uma lista
int insereInicioListaRoleta(ListaEncCircularRoleta *lista, InfoRoleta info){
   NodoLEncCircularRoleta *novo = (NodoLEncCircularRoleta*)malloc(sizeof(NodoLEncCircularRoleta));

	if (lista->prim == NULL){
		novo->info = info;
    	lista->prim = novo;
    	lista->fim = novo;
	    novo->prox = lista->prim;
	    return 1;
   }

	novo->info = info;
	novo->prox = lista->prim;
	lista->prim = novo;
	lista->fim->prox = lista->prim;
	return 1;
}

// Funcao que sorteia o numero randomicamente
int sorteiaNumero(){
    int r;
    srand(time(NULL));

    r = rand() % 21;    // Escolhemos 21 paea a roleta rodar mais de uma vez
    if (r == 0){
        r++;
    }
    return r;
}

// Funcao que inicia a roleta
ListaEncCircularRoleta* iniciaRoleta(){
	int retorno;
	ListaEncCircularRoleta *lista;
	lista = criaLista();

	InfoRoleta info1 = {1};
	InfoRoleta info2 = {2};
	InfoRoleta info3 = {3};
	InfoRoleta info4 = {4};
	InfoRoleta info5 = {5};
    InfoRoleta info6 = {6};
    InfoRoleta info7 = {7};
    InfoRoleta info8 = {8};
    InfoRoleta info9 = {9};
    InfoRoleta info10 = {10};

    retorno = insereInicioListaRoleta(lista, info10); // retorno = 1
    retorno = insereInicioListaRoleta(lista, info9); // retorno = 1
    retorno = insereInicioListaRoleta(lista, info8); // retorno = 1
    retorno = insereInicioListaRoleta(lista, info7); // retorno = 1
    retorno = insereInicioListaRoleta(lista, info6);
	retorno = insereInicioListaRoleta(lista, info5); // retorno = 1
	retorno = insereInicioListaRoleta(lista, info4); // retorno = 1
	retorno = insereInicioListaRoleta(lista, info3); // retorno = 1
    retorno = insereInicioListaRoleta(lista, info2); // retorno = 1
	retorno = insereInicioListaRoleta(lista, info1); // retorno = 1

    return lista;
}


// Funcao que destroi uma lista
void destroiLista(ListaEncCircularRoleta *lista){
   NodoLEncCircularRoleta *aux = lista->prim;
   while(aux != NULL){
       NodoLEncCircularRoleta *tmp = aux->prox;
       free(aux);
       aux = tmp;
   }
   free(lista);
}


// Função para dar um delay entre os prints da roleta
void delay(int ms)
{
    int tempo;
    tempo = clock();

    while (clock() < tempo+ms);
}


// Funcao que recebe o numero sorteado e printa a roleta (ta com O(n2), mas ficou legal visualmente)
NodoLEncCircularRoleta* giraRoleta (ListaEncCircularRoleta *roleta){
     int aleat, numSorteado, i = 0;

     aleat = sorteiaNumero();
     i = aleat;

     while(aleat >0){
        delay (10*i);       //quanto maior o argumento, maior o delay
        system("cls");
        i=i+2;              //i vai aumentando pra deixar a roleta mais devagar
        aleat--;

    roleta->prim = roleta->prim->prox;

        printf("\t\t        \\/\n");
        printf("\t\t        %d\n", roleta->prim->info);
        printf("\t\t     %d     %d\n",roleta->prim->prox->prox->prox->prox->prox->prox->prox->prox->prox->info,roleta->prim->prox->info);
        printf("\t\t    %d       %d\n",roleta->prim->prox->prox->prox->prox->prox->prox->prox->prox->info,roleta->prim->prox->prox->info);
        printf("\t\t    %d       %d\n",roleta->prim->prox->prox->prox->prox->prox->prox->prox->info,roleta->prim->prox->prox->prox->info);
        printf("\t\t     %d    %d\n",roleta->prim->prox->prox->prox->prox->prox->prox->info,roleta->prim->prox->prox->prox->prox->info);
        printf("\t\t        %d\n",roleta->prim->prox->prox->prox->prox->prox->info);
    }

    printf("\n \n \n \n\t\t O numero sorteado foi %d! \n \n \n \n", roleta->prim->info);
    numSorteado = roleta->prim->info.numero;

    return roleta->prim->info.numero;

}
