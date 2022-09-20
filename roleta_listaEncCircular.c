#include "roleta_listaEncCircular.h"
#include <stdio.h>
#include <stdlib.h>

ListaEncCircular* criaLista(){
   ListaEncCircular *lista = (ListaEncCircular*)malloc(sizeof(ListaEncCircular));
   lista->prim = NULL;
   return lista;
}

// Funcao que insere um nodo no inicio de uma lista
int insereInicioLista(ListaEncCircular *lista, Info info){
   NodoLEncCircular *novo = (NodoLEncCircular*)malloc(sizeof(NodoLEncCircular));
   
	if (lista->prim == NULL){
		novo->info = info;
    	lista->prim = novo;
    	lista->fim = novo;
	    novo->prox = lista->prim;
	    //printf("%d\n", novo->info.numero);
	    return;
   }
   
	novo->info = info;
	novo->prox = lista->prim;
	lista->prim = novo;
	lista->fim->prox = lista->prim;
	//printf("%d\n", novo->info.numero);
	return 1;
}

int sorteiaNumero(){
    int i, r;
    srand(time(NULL));

    r = rand() % 21;
    if (r == 0){
        r++;
    }
    printf("%d\n\n", r);
    return r;
}

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEncCircular* buscaInfoLista(ListaEncCircular* lista, int num){
   NodoLEncCircular *aux;
   int i = 0;
   aux = lista->prim;
   for(i = 1; i <= num; i++){
		printf("%d\n", i);
		printf("num %d \n", aux->info.numero);
        	aux = aux->prox;
   }
  
   return NULL; 
}

void iniciaRoleta(){
	int retorno, sorteioDeNumero;
	ListaEncCircular *lista;
	lista = criaLista();
   
	Info info1 = {1};
	Info info2 = {2};
	Info info3 = {3};
	Info info4 = {4};
	Info info5 = {5};
	
	retorno = insereInicioLista(lista, info5); // retorno = 1
	retorno = insereInicioLista(lista, info4); // retorno = 1
	retorno = insereInicioLista(lista, info3); // retorno = 1
    retorno = insereInicioLista(lista, info2); // retorno = 1
	retorno = insereInicioLista(lista, info1); // retorno = 1

	rodaRoleta(lista); 
}

void rodaRoleta(ListaEncCircular *lista){
	buscaInfoLista(lista, sorteiaNumero());
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
//void imprimeLista(ListaEncCircular *lista){
//   NodoLEncCircular *aux;
//   printf("-----------------------------------------\n");
//   for(aux = lista->prim; aux != NULL; aux = aux->prox)
//      printf("%d\n", aux->info.numero);
//   printf("-----------------------------------------\n");
//}


// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoLista(ListaEncCircular* lista, int numero){
   NodoLEncCircular* ant = NULL;
   NodoLEncCircular *aux = lista->prim; 
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


void fimRoleta(){
	//destroiLista(lista);
}

