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
	InfoCasa infoCasa2 = {2, 2,"Inicio das aulas. Pague a matricula R$5000.", 1, -5000, 0,0,0};
	InfoCasa infoCasa3 = {3, 1,"Voce se tornou YouTuber! Salario de R$ 30000. Ande mais 10 casas.",0,30000,1, 10,0};
	InfoCasa infoCasa4 = {4, 2,"Entrou na Faculdade. Ganhe R$2000.", 1, 2000, 0,0,0};
	InfoCasa infoCasa5 = {5, 2,"Comprou um computador novo para a faculdade. Pague R$2000.", 1, 2000, 0,0,0};
	InfoCasa infoCasa6 = {6, 1,"MEDICO! Salario R$ 50.000. Ande mais 7 casas!",0,50000,1, 7,0};
	InfoCasa infoCasa7 = {7, 1,"ARTISTA! Salario R$ 24.000. Ande mais 6 casas!",0,24000,1, 6,0};
	InfoCasa infoCasa8 = {8, 1,"ADVOGADO! Salario R$ 50.000. Ande mais 5 casas!",0,50000, 1, 5,0};
	InfoCasa infoCasa9 = {9, 2,"Alugou um Apartamento. Pague R$2000.", 1, -2000, 0,0,0};
	InfoCasa infoCasa10 = {10, 1,"ENGENHEIRO! Salario de R$ 30.000. Ande mais 3 casas!",0, 30000, 1, 3,0};
	InfoCasa infoCasa11 = {11, 1,"PROFESSOR! Salario de R$ 20.000. Ande mais 2 casas!", 0, 20000, 1, 2,0};
	InfoCasa infoCasa12 = {12, 1,"Diploma Universitario! Salario de R$ 16.000. Ande mais 1 casa!", 0, 16000, 1, 1,0};
	InfoCasa infoCasa13 = {13, 3,"Dia do Pagamento!", 0, 0, 0, 0,0};

	retorno = insereInicioListaTabuleiro(tabuleiro, infoCasa1); // retorno = 1
	retorno = insereInicioListaTabuleiro(tabuleiro, infoCasa2); // retorno = 1
	retorno = insereInicioListaTabuleiro(tabuleiro, infoCasa3); // retorno = 1
	retorno = insereInicioListaTabuleiro(tabuleiro, infoCasa4); // retorno = 1
	retorno = insereInicioListaTabuleiro(tabuleiro, infoCasa5);
    retorno = insereInicioListaTabuleiro(tabuleiro, infoCasa6);
    retorno = insereInicioListaTabuleiro(tabuleiro, infoCasa7);
    retorno = insereInicioListaTabuleiro(tabuleiro, infoCasa8);
    retorno = insereInicioListaTabuleiro(tabuleiro, infoCasa9);
    retorno = insereInicioListaTabuleiro(tabuleiro, infoCasa10);
    retorno = insereInicioListaTabuleiro(tabuleiro, infoCasa11);
    retorno = insereInicioListaTabuleiro(tabuleiro, infoCasa12);
    retorno = insereInicioListaTabuleiro(tabuleiro, infoCasa13);

    int  numJogadores;
	ListaEncCircularJogador *jogador;
	jogador = criaJogador();

	InfoJogador info1 = {1,0,0,10000,1};
	InfoJogador info2 = {2,0,0,10000,1};
	InfoJogador info3 = {3,0,0,10000,1};
	InfoJogador info4 = {4,0,0,10000,1};

    printf("Quantos jogadores iram jogar?");
    scanf("%d", &numJogadores);

    switch (numJogadores)
    {
    case 1:
        retorno = insereInicioListaJogador(jogador, info1);
        imprimeJogador(jogador);
        break;
    case 2:
        retorno = insereInicioListaJogador(jogador, info2); // retorno = 1
	    retorno = insereInicioListaJogador(jogador, info1); // retorno = 1
	    imprimeJogador(jogador);
        break;
//    case 3:
//    	retorno = insereInicioListaJogador(lista, info3); // retorno = 1
//        retorno = insereInicioListaJogador(lista, info2); // retorno = 1
//        retorno = insereInicioListaJogador(lista, info1); // retorno = 1
//        imprimeJogador(lista);
//        break;
//    case 4:
//        retorno = insereInicioListaJogador(lista, info4); // retorno = 1
//        retorno = insereInicioListaJogador(lista, info3); // retorno = 1
//        retorno = insereInicioListaJogador(lista, info2); // retorno = 1
//        retorno = insereInicioListaJogador(lista, info1); // retorno = 1
//        imprimeJogador(lista);
//        break;
    default:
        printf("\n\n\t\tVoce deve escolher um numero de jogadores entre 1 e 4!\n");
        break;
    }

    IniciaAndaCasas(tabuleiro, jogador, 13);


//   int opcao;
//
//    do{
//        system("cls");
//
//        imprimeRoleta();
//        imprimeSlogan();
//        adicionaCasasNoTabuleiro();
//
//        printf("----- MENU -----\n");
//        printf("1 - Inicie o Jogo \n");
//        printf("2 - Regras \n");
//        printf("3 - Sair \n");
//        printf("----- ---- -----\n");
//        printf("Informe uma opcao: ");
//        scanf("%d", &opcao);
//      switch(opcao){
//         case 1:
//            printf("Iniciar Jogo \n");
//            //votosInvalidos += votar(votos, numeros);	//recebe se há votos inválidos
//            break;
//         case 2:
//            printf("Numeros e Partidos \n");
//            //imprimirPartidos(partidos, numeros);
//            //system("pause");
//            break;
//         case 3:
//            printf("Votos Validos e Invalidos \n");
//			//imprimirNumeroDeVotos(votos,votosInvalidos);
//            //system("pause");
//            break;
//         case 4:
//            printf("Encerrar Votacao \n");
//            //naoEmpate = vencedor(votos, &idxVencedor, &percentual); //recebe se a empate ou nao
//            break;
//         default:
//            printf("Opcao invalida!");
//            //system("pause");
//      }
//
//   }while(opcao != 4);
//

   return 0;
}


