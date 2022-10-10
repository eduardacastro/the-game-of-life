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

// Funcao que inicia a roleta
ListaEncCircularRoleta* iniciaRoleta();

// Funcao que recebe o numero sorteado e printa a roleta
int giraRoleta (ListaEncCircularRoleta *roleta);

// Funcao que destroi uma lista
void destroiListaRoleta(ListaEncCircularRoleta *lista);

// Funcao que imprime todos os nodos de uma lista
void imprimeListaRoleta(ListaEncCircularRoleta *lista);

// Funcao que insere um nodo no inicio de uma lista
int insereInicioListaRoleta(ListaEncCircularRoleta *lista, InfoRoleta info);

// Funcao que sorteia o numero randomicamente
int sorteiaNumero();

// Funcao de delay para fazer a roleta rodar mais devagar
void delay(int ms);

#endif
