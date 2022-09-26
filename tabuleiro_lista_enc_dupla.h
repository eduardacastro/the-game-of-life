#include "jogador_listaEncCircular.h"

#ifndef _TABULEIRO_LISTA_ENC_DUPLA_H_
#define _TABULEIRO_LISTA_ENC_DUPLA_H_

#define TAM_MAX_TEXTO 80

typedef struct{
   int numeroDaCasa;
   int tipoDeCasa;
   char textoDaCasa[TAM_MAX_TEXTO];
   int ganhaPerdeDinheiro;
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
NodoLEnc2* buscaInfoListaTabuleiro(ListaEnc2* lista, int matricula);

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoListaTabuleiro(ListaEnc2* lista, int matricula);

void IniciaAndaCasas(ListaEnc2* tabuleiro, ListaEncCircularJogador *jogador, int numeroDeCasas);

void imprimeCasaAtual(int num, ListaEnc2* tabuleiro)

#endif
