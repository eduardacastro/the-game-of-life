#ifndef jogo_h
#define jogo_h
#include <stdio.h>

// Funcao que imprime a tela inicial do Menu
void printTelaInicial();

// Funcao que direciona de acordo com a opcao escolhida
void telaInicial();

// Funcao que inicia e faz a administracao do jogo
void jogo();

// Funcao que imprime as regras do jogo
void imprimeRegras();

// Funcao que verifica se o jogo terminou por dinheiro
int fimDeJogoPorDinheiro(NodoLEncCircularJogador *jogador);

// Funcao que verifica se o jogo terminou por posicao
int fimDeJogoPorPosicao(ListaEncCircularJogador* listaDeJogadores, NodoLEncCircularJogador *jogador);

#endif /* jogo_h */
