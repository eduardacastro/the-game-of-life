#include "lista_enc.h"
#include "lista_enc_dupla.c"
#include "lista_enc.h"
#include "lista_enc_dupla.h"
#include <stdio.h>
#include <stdlib.h>


int main(){

   int opcao;

    do{
        system("cls");

        printf("==========================================================================================================\n");
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


        printf("----- MENU -----\n");
        printf("1 - Inicie o Jogo \n");
        printf("2 - Regras \n");
        printf("3 - Sair \n");
        printf("----- ---- -----\n");
        printf("Informe uma opcao: ");
        scanf("%d", &opcao);
      switch(opcao){
         case 1:
            printf("Iniciar Jogo \n");
            //votosInvalidos += votar(votos, numeros);	//recebe se há votos inválidos
            break;
         case 2:
            printf("Numeros e Partidos \n");
            //imprimirPartidos(partidos, numeros);
            //system("pause");
            break;
         case 3:
            printf("Votos Validos e Invalidos \n");
			//imprimirNumeroDeVotos(votos,votosInvalidos);
            //system("pause");
            break;
         case 4:
            printf("Encerrar Votacao \n");
            //naoEmpate = vencedor(votos, &idxVencedor, &percentual); //recebe se a empate ou nao
            break;
         default:
            printf("Opcao invalida!");
            //system("pause");
      }
   }while(opcao != 4);

   //printVencedor(naoEmpate, percentual, partidos[idxVencedor]); //printa o vencedor

   return 0;
}


