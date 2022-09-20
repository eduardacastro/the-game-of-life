#ifndef _LISTA_ENC_H_
#define _LISTA_ENC_H_

#define TAM_MAX_NOME 40

typedef struct{
    int numJogador;
    char nome[TAM_MAX_NOME];
    int posicao;
    int dinheiro;
    int familia;
} Jogador;

typedef struct{
    int numero;
} Roleta;

typedef Jogador Info;

typedef Roleta InfoRoleta;

typedef struct nodoLEnc{
   Info info;
   struct nodoLEnc *prox;
} NodoLEnc;

typedef struct nodoLEncRoleta{
   InfoRoleta info;
   struct nodoLEnc *prox;
} nodoLEncRoleta;

typedef struct listaEnc{
   struct nodoLEnc *prim;
} ListaEnc;


// Funcao que cria uma lista
ListaEnc* criaJogador();

// Funcao que destroi uma lista
void destroiJogador(ListaEnc *lista);

// Funcao que imprime todos os nodos de uma lista
void imprimeJogador(ListaEnc *lista);

// Funcao que insere um nodo no inicio de uma lista
int insereInicioListaJogador(ListaEnc *lista, Info info);

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEnc* buscaInfoJogador(ListaEnc* lista, int matricula);

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoJogador(ListaEnc* lista, int matricula);

int sorteiNumero();


#endif
