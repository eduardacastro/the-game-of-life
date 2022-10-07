#include "jogador_listaEncCircular.h"
#include "roleta_listaEncCircular.h"
#include "tabuleiro_lista_enc_dupla.h"
#include "jogo.h"
#include <stdio.h>
#include <unistd.h>
#include <windows.h>
#include <stdlib.h>

void printTelaInicial(){

    printf("\n==========================================================================================================\n");
    printf("=====    ====    =====      =====    =========       ======  ==========  ====  ==    ==       ======  ====\n");
    printf("======  ====  ==  ===   ==   ===  ==  ========  ====  ====    =========  ====  ===  ===  ====  ====    ===\n");
    printf("======  ===  ====  ==  ====  ==  ====  =======  ====  ===  ==  ========  ====  ===  ===  ====  ===  ==  ==\n");
    printf("======  ===  ====  ==  ========  ====  =======  ====  ==  ====  =======  ====  ===  ===  ====  ==  ====  =\n");
    printf("======  ===  ====  ==  ========  ====  =======  ====  ==  ====  =======   ==   ===  ===  ====  ==  ====  =\n");
    printf("======  ===  ====  ==  ===   ==  ====  =======  ====  ==        ========  ==  ====  ===  ====  ==        =\n");
    printf("=  ===  ===  ====  ==  ====  ==  ====  =======  ====  ==  ====  ========  ==  ====  ===  ====  ==  ====  =\n");
    printf("=  ===  ====  ==  ===   ==   ===  ==  ========  ====  ==  ====  =========    =====  ===  ====  ==  ====  =\n");
    printf("==     ======    =====      =====    =========       ===  ====  ==========  =====    ==       ===  ====  =\n");
    printf("==========================================================================================================\n");

    printf("\n\n\t\t\t\t\t\t----- MENU -----\n\n");
    printf("\t\t\t\t\t1 - Iniciar Jogo \n");
    printf("\t\t\t\t\t2 - Regras do Jogo\n");
    printf("\t\t\t\t\t3 - Sair \n\n");
    printf("\t\t\t\t\t\t----- ---- -----\n");
    printf("\n\t\t\t\t\tInforme uma opcao: ");
}
void telaInicial(){
    int opcao = 0;
    system("cls");
    printTelaInicial();
    scanf("%d", &opcao);

    do{
      switch(opcao){
         case 1:
            printf("Iniciar Jogo \n");
              jogo();
            break;
         case 2:
            printf("Regras do Jogo \n");
              imprimeRegras();
            break;
         case 3:
            printf("Sair do Jogo \n");
            //imprimirNumeroDeVotos(votos,votosInvalidos);
            //system("pause");
            break;
         default:
            printf("\n\nOpcao invalida!\n\n");
            system("pause");
            telaInicial();
      }
   }while(opcao != 3);

}


void jogo(){

    ListaEnc2* tabuleiro;
    tabuleiro = iniciaTabuleiro();              //Inicia o Tabuleiro

    ListaEncCircularJogador* jogadores;
    NodoLEncCircularJogador *jogador;
    jogadores = iniciaJogadores();              //Inicia os Jogadores

    ListaEncCircularRoleta* roleta;
    NodoLEncCircularRoleta* numSorteado;
    roleta = iniciaRoleta();                    //Inicia a Roleta

    jogador = jogadores->prim;                  // Recebe o primeiro Jogador

    do {
        system("cls");
        printf("\-> Saldo dos Jogadores:");
        imprimeJogador(jogadores);
        printf("\n\n\n\t-> Vez do Jogador %d:\n\n", jogador->info.numJogador);     // printa de qual jogador é a vez
        printf("\n-> Girar a Roleta:\n");
        printf("\t");

        if(jogador->info.numJogador == 2){
            sleep(2);
        }else{
            system("pause");
        }


        numSorteado = giraRoleta(roleta);
        printf("-> Vez do Jogador %d:\n\n", jogador->info.numJogador);

        andarCasas(tabuleiro,jogador, numSorteado , roleta);                     // anda no tabuleiro o numero de casas sorteadas

        imprimeJogador(jogadores);                                              // imprime os dados dos jogadores

        if(jogador->info.numJogador == 2){
            sleep(8);
        }else{
            system("pause");
        }

        jogador = jogador->prox;                                                // muda para o proximo jogador


    } while (jogador->info.posicao<80 && jogador->info.dinheiro > 0);

}


//Função que imprime as regras do jogo.
void imprimeRegras(){

    system("cls");

    printf("\t\t\tINICIO \n \n");
    printf("\tO jogador inicia a partida na casa 0, sem emprego definido, com 10000 reais e sem familia, as-\n");
    printf("sim como o computador. Na sua vez de jogar, o jogador deve girar a roleta para descobrir quantas casas\n");
    printf("(de 1 a 10) deve andar no tabuleiro. Cada casa, alem de seu numero correspondente pode ser classifica-\n");
    printf("da em uma das categorias abaixo:\n\n");
    printf("\t\t\tCASAS\n\n");
    printf("1. Casa de profissao: Estabelece uma profissao e um salario para o jogador;\n");
    printf("2. Perde/ganha dinheiro: Devido a um acontecimento, ha uma mudanca no dinheiro guardado pelo jogador;\n");
    printf("3. Dia do pagamento: Ao passar por essa casa (nao necessariamente deve ser a casa final do jogador na\nrodada), recebe-se o salario;\n");
    printf("4. Tira dinheiro dos outros jogadores: Devido a um acontecimento, o jogador recebe dinheiro do outro;\n");
    printf("5. Aumenta a familia: o jogador recebe mais um membro da familia.\n \n");
    printf("\t\t\tFIM DO JOGO \n\n");
    printf("\tCaso algum jogador entre em falencia (isto eh, fique com 0 reais ou devendo), automaticamente\n");
    printf("esta desclassificado e o outro jogador eh o vencedor. Se isso nao acontecer, assim que o primeiro jo-\n");
    printf("gador chega na ultima casa, o outro jogador ainda tem tempo de jogar (caso nao tenha mudado a rodada)\n");
    printf("e entao encerra-se o jogo. Aquele que tiver mais dinheiro quando isso acontece,\n");
    printf("se consagra o vencedor do jogo da vida!\n\n");

    printf("\n\n\nPara voltar para o Menu:\n");
    system("pause");
    system("cls");
    telaInicial();
}
