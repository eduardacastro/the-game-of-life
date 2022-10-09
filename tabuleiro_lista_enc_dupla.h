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

// Funcao que destroi uma lista
void destroiListaTabuleiro(ListaEnc2 *lista);

// Funcao que imprime todos os nodos de uma lista
void imprimeListaTabuleiro(ListaEnc2 *lista);

// Funcao que insere um nodo no inicio de uma lista
int insereInicioListaTabuleiro(ListaEnc2 *lista, InfoCasa infoCasa);

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEnc2* buscaInfoListaTabuleiro(ListaEnc2* lista, int numeroDaCasa);

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoListaTabuleiro(ListaEnc2* lista, int matricula);

void imprimeCasaAtual(int num, ListaEnc2* tabuleiro, NodoLEncCircularJogador *jogador);

void andarCasas(ListaEnc2* tabuleiro, NodoLEncCircularJogador *jogador, int numeroDeCasas, ListaEncCircularRoleta* roleta);

int buscaInfoListaFinalTabuleiro(ListaEnc2* tabuleiro, NodoLEncCircularJogador *jogador, int numInicial);

NodoLEnc2* buscaInfoListaInicialTabuleiro(ListaEnc2* lista, NodoLEncCircularJogador *jogador, int casaInicial);

NodoLEncCircularJogador* novoMembroDaFamilia(NodoLEncCircularJogador *jogador, int numeroDeMembros);

int existeDiaDoPagamentoEntreAsCasas(ListaEnc2* lista, NodoLEncCircularJogador *jogador, int inicioCasa, int fimCasa);

void diaDoPagamento(NodoLEncCircularJogador *jogador, int numeroDeCasasDeDiaDoPagamento);

int fimDeJogoPorDinheiro(NodoLEncCircularJogador *jogador);

ListaEnc2* iniciaTabuleiro();

int fimDeJogoPorDinheiro(NodoLEncCircularJogador *jogador);

int fimDeJogoPorPosicao(ListaEncCircularJogador* listaDeJogadores, NodoLEncCircularJogador *jogador);

#endif
