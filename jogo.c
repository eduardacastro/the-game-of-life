#include "jogo.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int sorteiNumero(){
    int i, r;
    srand(time(NULL));

    r = rand() % 21;
    if (r == 0){
        r++;
    }
    return r;
}


int roleta(){
    ListaEnc *roleta;
    roleta = criaJogador();
    int retorno;

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
    retorno = insereInicioLista(roleta, info1);
    retorno = insereInicioLista(roleta, info2);
    retorno = insereInicioLista(roleta, info3);
    retorno = insereInicioLista(roleta, info4);
    retorno = insereInicioLista(roleta, info5);
    retorno = insereInicioLista(roleta, info6);
    retorno = insereInicioLista(roleta, info7);
    retorno = insereInicioLista(roleta, info8);
    retorno = insereInicioLista(roleta, info9);
    retorno = insereInicioLista(roleta, info10);

    imprimeTesteRoleta(roleta);
}


void imprimeTesteRoleta(ListaEnc *roleta){
    nodoLEncRoleta *aux;
   printf("-----------------------------------------\n");
   for(aux = roleta->prim; aux != NULL; aux = aux->prox)
      printf("%d\n", aux->info.numero);
   printf("-----------------------------------------\n");
}

// Funcao que cria uma lista
ListaEnc* criaJogador(){
    ListaEnc *lista = (ListaEnc*)malloc(sizeof(ListaEnc));
    return lista;
}

// Funcao que destroi uma lista
void destroiJogador(ListaEnc *lista){
   NodoLEnc *aux = lista->prim;
   while(aux != NULL){
       NodoLEnc *tmp = aux->prox;
       free(aux); // Cuidar ordem do free
       aux = tmp;
   }
   free(lista);
}

// Funcao que imprime todos os nodos de uma lista
void imprimeJogador(ListaEnc *lista){
   NodoLEnc *aux;
   printf("-----------------------------------------\n");
   for(aux = lista->prim; aux != NULL; aux = aux->prox)
      printf("%s | posicao:%d dinheiro: %d familia: %d\n", aux->info.nome,
                                                           aux->info.posicao,
                                                           aux->info.dinheiro,
                                                           aux->info.familia);
   printf("-----------------------------------------\n");
}


// Funcao que insere um nodo no inicio de uma lista
int insereInicioListaJogador(ListaEnc *lista, Info info){
   NodoLEnc *novo = (NodoLEnc*)malloc(sizeof(NodoLEnc));
   if (novo == NULL) // Nao ha espaco em memoria
      return 0;
   novo->info = info;
   novo->prox = lista-> prim;
   lista->prim = novo;
   return 1;


}

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEnc* buscaInfoJogador(ListaEnc* lista, int numJogador){
   NodoLEnc *aux;


   for(aux = lista->prim; aux != NULL; aux = aux->prox){
     if (aux->info.numJogador == numJogador){
        return aux;
     }
   }
   return NULL;
}

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoJogador(ListaEnc* lista, int numJogador){
   NodoLEnc* ant = NULL;
   NodoLEnc *aux = lista->prim;
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

//int mudaNome(ListaEnc* lista,int numJogador, char name[]){
//    NodoLEnc *aux;
//    for(aux = lista->prim; aux != NULL; aux = aux->prox)
//        if (aux->info.numJogador == numJogador){
////            aux->info.nome = name;
////            return aux;
////        }
//    char nome[40];
//    printf("Escreva seu nome: ");
//    scanf("%s", nome);
//    printf("%s", nome);
//    Info info1 = {"", 1, 10000, 1};
//    NodoLEnc *aux = lista->prim;
//    aux->info.nome = nome;
//    retorno = insereInicioListaJogador(lista, info1);
//    imprimeJogador(lista);
////}







