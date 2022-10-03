#include "roleta_listaEncCircular.h"
#include "jogador_listaEncCircular.h"
#include "tabuleiro_lista_enc_dupla.h"
#include <stdio.h>
#include <stdlib.h>


int main(){

    int retorno;
   	ListaEnc2 *tabuleiro;
   	tabuleiro = criaListaTabuleiro();

   	// Aqui seriam chamadas as funcoes de inicializacao de nodos
   	InfoCasa infoCasa1 = {1, 2,"Raspou o carro no estacionamento. Pague R$1000.", 1, -1000, 0,0,0};
	InfoCasa infoCasa2 = {2, 3,"Dia do Pagamento!", 1, -5000, 0,0,0};
	InfoCasa infoCasa3 = {3, 3,"Dia do Pagamento.",0,30000,1, 10,0};
    InfoCasa infoCasa4 = {4, 3,"Dia do Pagamento!", 1, -5000, 0,0,0};
	InfoCasa infoCasa5 = {5, 2,"Comprou um computador novo para a faculdade. Pague R$2000.", 1, 2000, 0,0,0};
	InfoCasa infoCasa6 = {6, 1,"MEDICO! Salario R$ 50.000. Ande mais 7 casas!",0,50000,1, 7,0};
	InfoCasa infoCasa7 = {7, 1,"ARTISTA! Salario R$ 24.000. Ande mais 6 casas!",0,24000,1, 6,0};
	InfoCasa infoCasa8 = {8, 1,"ADVOGADO! Salario R$ 50.000. Ande mais 5 casas!",0,50000, 1, 5,0};
	InfoCasa infoCasa9 = {9, 2,"Alugou um Apartamento. Pague R$2000.", 1, -2000, 0,0,0};
	InfoCasa infoCasa10 = {10, 1,"ENGENHEIRO! Salario de R$ 30.000. Ande mais 3 casas!",0, 30000, 1, 3,0};
	InfoCasa infoCasa11 = {11, 1,"PROFESSOR! Salario de R$ 20.000. Ande mais 2 casas!", 0, 20000, 1, 2,0};
	InfoCasa infoCasa12 = {12, 1,"Diploma Universitario! Salario de R$ 16.000. Ande mais 1 casa!", 0, 16000, 1, 1,0};
	InfoCasa infoCasa13 = {13, 3,"Dia do Pagamento!", 0, 0, 0, 0,0};

	retorno = insereInicioListaTabuleiro(tabuleiro, infoCasa13); // retorno = 1
	retorno = insereInicioListaTabuleiro(tabuleiro, infoCasa12); // retorno = 1
	retorno = insereInicioListaTabuleiro(tabuleiro, infoCasa11); // retorno = 1
	retorno = insereInicioListaTabuleiro(tabuleiro, infoCasa10); // retorno = 1
	retorno = insereInicioListaTabuleiro(tabuleiro, infoCasa9);
    retorno = insereInicioListaTabuleiro(tabuleiro, infoCasa8);
    retorno = insereInicioListaTabuleiro(tabuleiro, infoCasa7);
    retorno = insereInicioListaTabuleiro(tabuleiro, infoCasa6);
    retorno = insereInicioListaTabuleiro(tabuleiro, infoCasa5);
    retorno = insereInicioListaTabuleiro(tabuleiro, infoCasa4);
    retorno = insereInicioListaTabuleiro(tabuleiro, infoCasa3);
    retorno = insereInicioListaTabuleiro(tabuleiro, infoCasa2);
    retorno = insereInicioListaTabuleiro(tabuleiro, infoCasa1);

    int  numJogadores;
	ListaEncCircularJogador *jogadores;
	jogadores = criaJogador();

	InfoJogador info1 = {1,0,0,10000,1};
	InfoJogador info2 = {2,0,0,10000,1};

    printf("Quantos jogadores iram jogar?"); //apagar
    scanf("%d", &numJogadores); //apagar

    switch (numJogadores) //apagar 
    {
    case 1:
        retorno = insereInicioListaJogador(jogadores, info2);
        retorno = insereInicioListaJogador(jogadores, info1);
        //imprimeJogador(jogador);
	     // retorno = 1
	    //imprimeJogador(jogador);
        break;
    default:
        printf("\n\n\t\tVoce deve escolher um numero de jogadores entre 1 e 4!\n");
        break;
    }
    ListaEncCircularRoleta* roleta;
    NodoLEncCircularRoleta* numSorteado;
    
    roleta = iniciaRoleta();
    
    NodoLEncCircularJogador *jogador;
    
    jogador = jogadores->prim;
    
    //do{
        //system("cls");
        numSorteado = rodaRoleta(roleta);
        printf("\n\n\n\tJogador %d\n\n", jogador->info.numJogador);
        //printf("\tNumero Sorteado: %d\n\n", numSorteado->info.numero);
    
        
        //IniciaAndaCasas(tabuleiro,jogador, numSorteado->info.numero);
    
        andarCasas(tabuleiro,jogador, 5, roleta);
      
        jogador = jogador->prox;
        
        imprimeJogador(jogadores);
        //system("pause");
    
//    switch (<#expression#>) {
//        case 1:
//            <#statements#>
//            break;
//        case 2:
//            
//            break;
//        case 3:
//            break;
//        default:
//            break;
//    }
        
   //}while(jogador->info.posicao != 80);


   return 0;
}


