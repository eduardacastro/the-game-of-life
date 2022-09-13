#include <stdio.h>
#include <stdlib.h>


#define QUANT_PARTIDOS 4

#define TRUE 1
#define FALSE 0

int vencedor(int *votos, int *idxVencedor, float *percentual);
void imprimirPartidos(char partidos[QUANT_PARTIDOS][10], int *numeros);
void imprimirNumeroDeVotos(int *votos, int votosInvalidos);
void printVencedor(int naoEmpate, float percentual, char* partido);
int votar(int *votos, int *numeros);

int main(){

   int opcao, naoEmpate;
   int votosInvalidos = 0;
   int idxVencedor;
   float percentual;
   
   int votos[QUANT_PARTIDOS] = {1,3,3,1};
   int numeros[QUANT_PARTIDOS] = {4, 2, 9, 5};
   char partidos[QUANT_PARTIDOS][10] = {"Partido A", "Partido B", "Partido C", "Partido D"};
   
    do{
   	  //system("cls");
        system("clear");
    
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
        printf("2 -  \n");
        printf("3 - Votos Validos e Invalidos \n");
        printf("4 - Sair \n");
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


