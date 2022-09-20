#ifndef _LISTA_ENC_DUPLA_H_
#define _LISTA_ENC_DUPLA_H_

#define TAM_MAX_TEXTOCASA 100

typedef struct{
   int idCasa;
   int tipoDeCasa;
   char textoDaCasa[TAM_MAX_TEXTOCASA];
   int dinheiro;
} Casa;

typedef Casa Informacao;

typedef struct nodoLEnc2{
   Informacao info;
   struct nodoLEnc2 *ant;
   struct nodoLEnc2 *prox;
} NodoLEnc2;

typedef struct ListaEnc2{
   struct nodoLEnc2 *prim;
} ListaEnc2;

// Funcao que cria uma lista
ListaEnc2* criaLista();

// Funcao que destroi uma lista
void destroiLista(ListaEnc2 *lista);

// Funcao que imprime todos os nodos de uma lista
void imprimeLista(ListaEnc2 *lista);

// Funcao que insere um nodo no inicio de uma lista
int insereInicioLista(ListaEnc2 *lista, Informacao info);

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEnc2* buscaInfoLista(ListaEnc2* lista, int matricula);

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoLista(ListaEnc2* lista, int matricula);

void imprimeRoleta();

void imprimeSlogan();

void adicionaCasasNoTabuleiro();

#endif
