#ifndef _ROLETA_LISTAENCCIRCULAR_H_
#define _ROLETA_LISTAENCCIRCULA_H_

typedef struct{
   int numero;
} Roleta;

typedef Roleta Info;

typedef struct NodoLEncCircularRoleta{
   Info info;
   struct NodoLEncCircularRoleta *prox;
} NodoLEncCircularRoleta;

typedef struct ListaEncCircularRoleta{
   struct NodoLEncCircular *prim;
   struct NodoLEncCircular *fim;
} ListaEncCircularRoleta;

// Funcao que cria uma lista
ListaEncCircularRoleta* criaLista();

// Funcao que destroi uma lista
void destroiListaRoleta(ListaEncCircularRoleta *lista);

// Funcao que imprime todos os nodos de uma lista
void imprimeListaRoleta(ListaEncCircularRoleta *lista);

// Funcao que insere um nodo no inicio de uma lista
int insereInicioListaRoleta(ListaEncCircularRoleta *lista, Info info);

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEncCircularRoleta* buscaInfoListaRoleta(ListaEncCircularRoleta* lista, int numero);

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoListaRoleta(ListaEncCircularRoleta* lista, int numero);

void iniciaRoleta();

int sorteiaNumero();

void rodaRoleta(ListaEncCircularRoleta *lista);

#endif
