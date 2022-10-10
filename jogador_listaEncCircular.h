#ifndef _JOGADOR_LISTAENCCIRCULAR_H_
#define _JOGADOR_LISTAENCCIRCULAR_H_

typedef struct{
   int numJogador;
   int posicao;
   int salario;
   int dinheiro;
   int familia;
} Jogador;

typedef Jogador InfoJogador;

typedef struct NodoLEncCircularJogador{
   InfoJogador info;
   struct NodoLEncCircularJogador *prox;
} NodoLEncCircularJogador;

typedef struct ListaEncCircularJogador{
   struct NodoLEncCircularJogador *prim;
   struct NodoLEncCircularJogador *fim;
} ListaEncCircularJogador;

// Funcao que cria uma lista
ListaEncCircularJogador* criaJogador();

// Funcao que inicia os Jogadores
ListaEncCircularJogador* iniciaJogadores();

// Funcao que destroi uma lista
void destroiListaCircularJogador(ListaEncCircularJogador *lista);

// Funcao que imprime todos os nodos de uma lista
void imprimeJogador(ListaEncCircularJogador *jogadores);

// Funcao que insere um nodo no inicio de uma lista
int insereInicioListaJogador(ListaEncCircularJogador *lista, InfoJogador info);

#endif
