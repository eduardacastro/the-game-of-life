#include "jogador_listaEncCircular.h"
#include "jogo.h"
#ifndef _TABULEIRO_LISTA_ENC_DUPLA_H_
#define _TABULEIRO_LISTA_ENC_DUPLA_H_

#define TAM_MAX_TEXTO 80

typedef struct{
   int numeroDaCasa;
   int tipoDeCasa;
   char textoDaCasa[TAM_MAX_TEXTO];
   float Dinheiro;
   int andaCasa;
   float quantasCasas;
   int membroDaFamilia;
} Casa;

typedef Casa InfoCasa;

typedef struct nodoLEnc2{
   InfoCasa infoCasa;
   struct nodoLEnc2 *ant;
   struct nodoLEnc2 *prox;
} NodoLEnc2;

typedef struct ListaEnc2{
   struct nodoLEnc2 *prim;
} ListaEnc2;

// Funcao que cria uma lista
ListaEnc2* criaListaTabuleiro();

// Funcao que inicia os tabuleiros
ListaEnc2* iniciaTabuleiro();

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEnc2* buscaInfoListaTabuleiro(ListaEnc2* lista, int numeroDaCasa);

// Funcao que destroi uma lista
void destroiListaTabuleiro(ListaEnc2 *lista);

// Funcao que insere um nodo no inicio de uma lista
int insereInicioListaTabuleiro(ListaEnc2 *lista, InfoCasa infoCasa);

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoListaTabuleiro(ListaEnc2* lista, int matricula);

// Imprime a casa Atual do jogador
void imprimeCasaAtual(int num, ListaEnc2* tabuleiro, NodoLEncCircularJogador *jogador);

// Funcao que realiza o percorrimento do jogador entre as casas
int andarCasas(ListaEnc2* tabuleiro, NodoLEncCircularJogador *jogador, int numeroDeCasas, ListaEncCircularJogador* jogadores);

// Funcao que verifica se ha dia do pagamento entre as casas inicial e final da posicao do jogador
int existeDiaDoPagamentoEntreAsCasas(ListaEnc2* lista, NodoLEncCircularJogador *jogador, int inicioCasa, int fimCasa);

// Funcao que realiza o dia do pagamento
void diaDoPagamento(NodoLEncCircularJogador *jogador, int numeroDeCasasDeDiaDoPagamento);

#endif
