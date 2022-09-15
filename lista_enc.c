#include "lista_enc.h"
#include <stdio.h>
#include <stdlib.h>

// Funcao que cria uma lista
ListaEnc* criaLista(){
   ListaEnc *lista = (ListaEnc*)malloc(sizeof(ListaEnc));
   lista->prim = NULL;
   return lista;
}

// Funcao que destroi uma lista
void destroiLista(ListaEnc *lista){
   NodoLEnc *aux = lista->prim;
   while(aux != NULL){
       NodoLEnc *tmp = aux->prox;
       free(aux); // Cuidar ordem do free
       aux = tmp;
   }
   free(lista);
}

// Funcao que imprime todos os nodos de uma lista
void imprimeLista(ListaEnc *lista){
   NodoLEnc *aux;
   printf("-----------------------------------------\n");
   for(aux = lista->prim; aux != NULL; aux = aux->prox)
      printf("%d | %s (%s)\n", aux->info.matricula,
                               aux->info.nome,
                               aux->info.email);
   printf("-----------------------------------------\n");
}

// Funcao que insere um nodo no inicio de uma lista
int insereInicioLista(ListaEnc *lista, Info info){
   NodoLEnc *novo = (NodoLEnc*)malloc(sizeof(NodoLEnc));
   if (novo == NULL) // Nao ha espaco em memoria
      return 0;
   novo->info = info;
   novo->prox = lista-> prim;
   lista->prim = novo;
   return 1;
}

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEnc* buscaInfoLista(ListaEnc* lista, int matricula){
   NodoLEnc *aux;
   for(aux = lista->prim; aux != NULL; aux = aux->prox)
      if (aux->info.matricula == matricula)
         return aux;
   return NULL; 
}

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoLista(ListaEnc* lista, int matricula){
   NodoLEnc* ant = NULL;
   NodoLEnc *aux = lista->prim; 
   while(aux != NULL && aux->info.matricula != matricula){
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

