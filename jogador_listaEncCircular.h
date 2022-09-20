#ifndef _JOGADOR_LISTAENCCIRCULAR_H_
#define _JOGADOR_LISTAENCCIRCULA_H_

typedef struct{
   int numJogador;
   int posicao;
   int dinheiro;
   int familia;
} Jogador;

typedef Jogador Info;

typedef struct NodoLEncCircular{
   Info info;
   struct NodoLEncCircular *prox;
} NodoLEncCircular;

typedef struct ListaEncCircular{
   struct NodoLEncCircular *prim;
   struct NodoLEncCircular *fim;
} ListaEncCircular;

// Funcao que cria uma lista
ListaEncCircular* criaJogador();

// Funcao que destroi uma lista
void destroiLista(ListaEncCircular *lista);

// Funcao que imprime todos os nodos de uma lista
void imprimeListaDeJogadores(ListaEncCircular *lista);

// Funcao que insere um nodo no inicio de uma lista
int insereInicioLista(ListaEncCircular *lista, Info info);

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEncCircular* buscaInfoLista(ListaEncCircular* lista, int numJogador);

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoLista(ListaEncCircular* lista, int numJogador);

#endif
