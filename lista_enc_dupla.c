#include "lista_enc_dupla.h"
#include <stdio.h>
#include <stdlib.h>

// Funcao que cria uma lista
ListaEnc2* criaLista(){
   ListaEnc2 *lista = (ListaEnc2*)malloc(sizeof(ListaEnc2));
   lista->prim = NULL;
   return lista;
}

// Funcao que destroi uma lista
void destroiLista(ListaEnc2 *lista){
   NodoLEnc2 *aux = lista->prim;
   while(aux != NULL){
       NodoLEnc2 *tmp = aux->prox;
       free(aux); // Cuidar ordem do free
       aux = tmp;
   }
   free(lista);
}

// Funcao que imprime todos os nodos de uma lista
void imprimeLista(ListaEnc2 *lista){
   NodoLEnc2 *aux;
   printf("-----------------------------------------\n");
   for(aux = lista->prim; aux != NULL; aux = aux->prox)
      printf("%d | %s (%s)\n", aux->info.matricula,
                               aux->info.nome,
                               aux->info.email);
   printf("-----------------------------------------\n");
}

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEnc2* buscaInfoLista(ListaEnc2* lista, int matricula){
   NodoLEnc2 *aux;
   for(aux = lista->prim; aux != NULL; aux = aux->prox)
      if (aux->info.matricula == matricula)
         return aux;
   return NULL; 
}

// Funcao que insere um nodo no inicio de uma lista
int insereInicioLista(ListaEnc2 *lista, Info info){
   NodoLEnc2 *novo = (NodoLEnc2*)malloc(sizeof(NodoLEnc2));
   novo->info = info;
   novo->ant = NULL;
   novo->prox = lista->prim;
   if (lista->prim != NULL)
      lista->prim->ant = novo;
   lista->prim = novo;
   return 1;
}

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoLista(ListaEnc2* lista, int matricula){
   NodoLEnc2 *aux = lista->prim; 
   while(aux != NULL && aux->info.matricula != matricula){
      aux = aux->prox;
   }
   if (aux != NULL){
      if (aux->ant == NULL){
         lista->prim = aux->prox;
         if (aux->prox != NULL)
            aux->prox->ant = NULL;   
      }else{
         aux->ant->prox = aux->prox;
         if (aux->prox != NULL)
            aux->prox->ant = aux->ant;            
      }
      free(aux);
      return 1;
   }
   return 0; // Nao encontrou
}

