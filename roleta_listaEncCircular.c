#include "roleta_listaEncCircular.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	    //printf("%d\n", novo->info.numero);
	    return 1;
   }

	novo->info = info;
	novo->prox = lista->prim;
	lista->prim = novo;
	lista->fim->prox = lista->prim;
	//printf("%d\n", novo->info.numero);
	return 1;
}

int sorteiaNumero(){
    int r;
    srand(time(NULL));

    r = rand() % 21;
    if (r == 0){
        r++;
    }
    // printf("%d\n\n", r);   //print para veridicar o num aleatorio
    return r;
}

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEncCircularRoleta* buscaInfoListaRoleta(ListaEncCircularRoleta* lista, int num){
   NodoLEncCircularRoleta *aux;
   int i = 0;
   aux = lista->prim;
   for(i = 1; i <= num; i++){
        aux = aux->prox;
       //        printf("%d\n", i);
       //        printf("num %d \n", aux->info.numero);  // prints para veridicar se a roleta esta funcionando
   }
    return aux;
}

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

NodoLEncCircularRoleta* rodaRoleta(ListaEncCircularRoleta *lista){

    NodoLEncCircularRoleta *aux;

    aux = buscaInfoListaRoleta(lista, sorteiaNumero());
    return  aux;
}


// Funcao que destroi uma lista
void destroiLista(ListaEncCircularRoleta *lista){
   NodoLEncCircularRoleta *aux = lista->prim;
   while(aux != NULL){
       NodoLEncCircularRoleta *tmp = aux->prox;
       free(aux); // Cuidar ordem do free
       aux = tmp;
   }
   free(lista);
}

// Funcao que imprime todos os nodos de uma lista
//void imprimeLista(ListaEncCircular *lista){
//   NodoLEncCircular *aux;
//   printf("-----------------------------------------\n");
//   for(aux = lista->prim; aux != NULL; aux = aux->prox)
//      printf("%d\n", aux->info.numero);
//   printf("-----------------------------------------\n");
//}


// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoListaRoleta(ListaEncCircularRoleta* lista, int numero){
   NodoLEncCircularRoleta* ant = NULL;
   NodoLEncCircularRoleta *aux = lista->prim;
   while(aux != NULL && aux->info.numero != numero){
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


// Função para dar um delay entre os prints da roleta
void delay(int ms)
{
    int tempo;
    tempo = clock();

    while (clock() < tempo+ms);
}


//função que gira a roleta (ta com O(n2), mas ficou legal visualmente)
int giraRoleta (ListaEncCircularRoleta *roleta){
     int aleat, numSorteado, i = 0;

     aleat = sorteiaNumero();
     i = aleat;

     while(aleat >0){
        delay (10*i); //quanto maior o argumento, maior o delay
        system("cls");
        i=i+2; //i vai aumentando pra deixar a roleta mais devagar
        aleat--;

    roleta->prim = roleta->prim->prox;

        printf("        \\/\n");
        printf("        %d\n", roleta->prim->info);
        printf("     %d     %d\n",roleta->prim->prox->prox->prox->prox->prox->prox->prox->prox->prox->info,roleta->prim->prox->info);
        printf("    %d       %d\n",roleta->prim->prox->prox->prox->prox->prox->prox->prox->prox->info,roleta->prim->prox->prox->info);
        printf("    %d       %d\n",roleta->prim->prox->prox->prox->prox->prox->prox->prox->info,roleta->prim->prox->prox->prox->info);
        printf("     %d    %d\n",roleta->prim->prox->prox->prox->prox->prox->prox->info,roleta->prim->prox->prox->prox->prox->info);
        printf("        %d\n",roleta->prim->prox->prox->prox->prox->prox->info);
    }


     //aqui tem um print e um pause só pra testar se tá tudo funcionando mesmo, podemos tirar


    printf("\n \n \n \n O numero sorteado foi %d! \n \n \n \n", roleta->prim->info);
    numSorteado = roleta->prim->info.numero;

    //system("pause");
    return numSorteado;

}




//void fimRoleta(){
//	//destroiLista(lista);
//}

