#include "jogador_listaEncCircular.h"
#include "roleta_listaEncCircular.h"
#include "tabuleiro_lista_enc_dupla.h"
#include "jogo.h"
#include <stdio.h>
#include <unistd.h>
#include <windows.h>
#include <stdlib.h>

// Funcao que imprime a tela inicial do Menu
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

// Funcao que direciona de acordo com a opcao escolhida
void telaInicial(){
    int opcao = 0;
    system("cls");
    printTelaInicial();     // printa a tela inicial
    scanf("%d", &opcao);    // recebe a opcao escolhida

    do{
      switch(opcao){
         case 1:
            printf("Iniciar Jogo \n");
            jogo();         // inicia o jogo
            break;
         case 2:
            printf("Regras do Jogo \n");
            imprimeRegras();        // imprime as regras do jogo
            break;
         case 3:
            printf("Sair do Jogo \n");  // sai do jogo
            break;
         default:
            printf("\n\nOpcao invalida!\n\n");
            system("pause");
            telaInicial();      // chaa a tela inicial
      }
   }while(opcao != 3);

}

// Funcao que inicia e faz a administracao do jogo
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

    int houveFimDeJogoPorPosicao = 0, foiFimDeJogoPorDinheiro = 0;

    do {

        system("cls");
        printf("\-> Saldo dos Jogadores:");
        imprimeJogador(jogadores);
        printf("\n\n\n\t-> Vez do Jogador %d:\n\n", jogador->info.numJogador);     // printa de qual jogador é a vez
        printf("\n-> Girar a Roleta:\n");
        printf("\t");

        if(jogador->info.numJogador == 2){      // Verifica qual eh o jogador para que se for o computador ele rodar automaticamente depois de um tempo
            sleep(2);
        }else{
            system("pause");
        }


        numSorteado = giraRoleta(roleta);   // recebe o numero sorteado
        printf("\n");
        printf("\-> Saldo dos Jogadores:");
        imprimeJogador(jogadores);          // imprime os jogadores e suas infos
        printf("-> Vez do Jogador %d:\n\n", jogador->info.numJogador);
        andarCasas(tabuleiro,jogador, numSorteado , roleta);                     // anda no tabuleiro o numero de casas sorteadas

        imprimeJogador(jogadores);  // imprime os dados dos jogadores

        if(jogador->info.numJogador == 2){// Verifica qual eh o jogador para que se for o computador ele rodar automaticamente depois de um tempo
            sleep(12);
        }else{
            system("pause");
        }

        houveFimDeJogoPorPosicao = fimDeJogoPorPosicao(tabuleiro,jogador);  //Verifica se foi fim de jogo por posicao (chegou no fim do tabuleiro, casa 80)
        foiFimDeJogoPorDinheiro = fimDeJogoPorDinheiro(jogador);    // Verifica se foi fim de jogo por dinheiro, ou seja, se alguem faliu

        jogador = jogador->prox;    // muda para o proximo jogador


    } while(houveFimDeJogoPorPosicao == 0 && foiFimDeJogoPorDinheiro == 0);

    system("pause");
    destroiListaRoleta(roleta);
    destroiListaTabuleiro(tabuleiro);
    destroiListaCircularJogador(jogadores);
    telaInicial();

}


// Função que imprime as regras do jogo.
void imprimeRegras(){

    system("cls");

    printf("\t\t\tINICIO \n \n");
    printf("\tO jogador inicia a partida na casa 0, sem emprego definido, com 10000 reais e com um membro na familia (que representa\n");
    printf("ele mesmo), assim como o computador. Na sua vez de jogar, o jogador deve girar a roleta para descobrir quantas casas\n");
    printf("(de 1 a 10) deve andar no tabuleiro. Cada casa, alem de seu numero correspondente pode ser classifica-\n");
    printf("da em uma das categorias abaixo:\n\n");
    printf("\t\t\tCASAS\n\n");
    printf("1. Casa de profissao: Estabelece uma profissao e um salario para o jogador;\n");
    printf("2. Perde/ganha dinheiro: Devido a um acontecimento, ha uma mudanca no dinheiro guardado pelo jogador;\n");
    printf("3. Dia do pagamento: Ao passar por essa casa (nao necessariamente deve ser a casa final do jogador na\nrodada), recebe-se o salario;\n");
    printf("4. Aumenta a familia: o jogador recebe mais um membro da familia.\n \n");
    printf("\t\t\tFIM DO JOGO \n\n");
    printf("\tCaso algum jogador entre em falencia (isto eh, fique com 0 reais ou devendo), automaticamente\n");
    printf("esta desclassificado e o outro jogador eh o vencedor. Se isso nao acontecer, assim que o primeiro jo-\n");
    printf("gador chega na ultima casa encerra-se o jogo. Aquele que tiver mais dinheiro quando isso acontece,\n");
    printf("se consagra o vencedor do jogo da vida!\n\n");

    printf("\n\n\nPara voltar para o Menu:\n");
    system("pause");
    system("cls");
    telaInicial();
}

// Funcao que verifica se o jogo terminou por dinheiro
int fimDeJogoPorDinheiro(NodoLEncCircularJogador *jogador){
    if (jogador->info.dinheiro <= 0){   // Caso o dinheiro do jogador seja menor que zero, ele entrou em falencia, e o jogo termina.
            printf("\nO jogador %d entrou em falencia! \n\nParabens, jogador %d, voce eh o vencedor do jogo da vida, com um caixa de $%d!\n\n", jogador->info.numJogador, (jogador->info.numJogador%2+1), jogador->prox->info.dinheiro);
        return 1;
    }else
    return 0;
}

// Funcao que verifica se o jogo terminou por posicao
int fimDeJogoPorPosicao(ListaEncCircularJogador* listaDeJogadores, NodoLEncCircularJogador *jogador){
    
    if(jogador->info.posicao >= 80){ // verifica se a posicao do jogador eh maior que 80
        jogador->info.dinheiro=jogador->info.dinheiro+(jogador->info.familia-1)*5000;
        jogador->prox->info.dinheiro=jogador->prox->info.dinheiro+(jogador->prox->info.familia-1)*5000;

        if(jogador ->info.dinheiro > jogador->prox->info.dinheiro)
            printf("O jogador %d ganhou! Alguem chegou no fim do tabuleiro e ele tinha mais dinheiro.\n\nJogador 1: $%d\nJogador 2: $%d \n", jogador->info.numJogador, listaDeJogadores->prim->info.dinheiro, listaDeJogadores->prim->prox->info.dinheiro);

            else if(jogador ->info.dinheiro < jogador->prox->info.dinheiro)
            printf("O jogador %d ganhou! Alguem chegou no fim do tabuleiro e ele tinha mais dinheiro.\n\nJogador 1: $%d\nJogador 2: $%d \n", jogador->prox->info.numJogador, listaDeJogadores->prim->info.dinheiro, listaDeJogadores->prim->prox->info.dinheiro);

            else printf("Empate! Ambos os jogadores acabaram com $%d", jogador->info.dinheiro);

            return 1;
    }
    return 0;
}
