#ifndef _LISTA_ENC_H_
#define _LISTA_ENC_H_

#define TAM_MAX_NOME 40


typedef struct{
   char nome[TAM_MAX_NOME];
   int posicao;
   int dinheiro;
   int familia;
} Jogador;

typedef Jogador Info;

typedef struct nodoLEnc{
   Info info;
   struct nodoLEnc *prox;
} NodoLEnc;

typedef struct listaEnc{
   struct nodoLEnc *prim;
} ListaEnc;

// Funcao que cria uma lista
ListaEnc* criaLista();

// Funcao que destroi uma lista
void destroiLista(ListaEnc *lista);

// Funcao que imprime todos os nodos de uma lista
void imprimeLista(ListaEnc *lista);

// Funcao que insere um nodo no inicio de uma lista
int insereInicioLista(ListaEnc *lista, Info info);

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEnc* buscaInfoLista(ListaEnc* lista, int matricula);

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoLista(ListaEnc* lista, int matricula);

#endif
