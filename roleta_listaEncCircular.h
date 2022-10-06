#ifndef _ROLETA_LISTAENCCIRCULAR_H_
#define _ROLETA_LISTAENCCIRCULAR_H_

typedef struct{
   int numero;
} Roleta;

typedef Roleta InfoRoleta;

typedef struct NodoLEncCircularRoleta{
   InfoRoleta info;
   struct NodoLEncCircularRoleta *prox;
} NodoLEncCircularRoleta;

typedef struct ListaEncCircularRoleta{
   struct NodoLEncCircularRoleta *prim;
   struct NodoLEncCircularRoleta *fim;
} ListaEncCircularRoleta;

// Funcao que cria uma lista
ListaEncCircularRoleta* criaLista();

// Funcao que destroi uma lista
void destroiListaRoleta(ListaEncCircularRoleta *lista);

// Funcao que imprime todos os nodos de uma lista
void imprimeListaRoleta(ListaEncCircularRoleta *lista);

// Funcao que insere um nodo no inicio de uma lista
int insereInicioListaRoleta(ListaEncCircularRoleta *lista, InfoRoleta info);

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEncCircularRoleta* buscaInfoListaRoleta(ListaEncCircularRoleta* lista, int numero);

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoListaRoleta(ListaEncCircularRoleta* lista, int numero);

ListaEncCircularRoleta* iniciaRoleta();

int sorteiaNumero();

NodoLEncCircularRoleta* rodaRoleta(ListaEncCircularRoleta *lista);

void giraRoleta (ListaEncCircularRoleta *roleta);

void delay(int ms);

#endif
