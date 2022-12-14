#include "jogador_listaEncCircular.h"
#include "tabuleiro_lista_enc_dupla.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

// Funcao que cria uma lista
ListaEnc2* criaListaTabuleiro(){
   ListaEnc2 *lista = (ListaEnc2*)malloc(sizeof(ListaEnc2));
   lista->prim = NULL;
   return lista;
}


void iniciaTabuleiro(){
	int retorno;
   	ListaEnc2 *lista;
   	lista = criaListaTabuleiro();

   	// Aqui seriam chamadas as funcoes de inicializacao de nodos
   	InfoCasa infoCasa1 = {1, 2,"Raspou o carro no estacionamento. Pague R$1000.", 1, -1000, 0,0};
	InfoCasa infoCasa2 = {2, 2,"Inicio das aulas. Pague a matricula R$5000.", 1, -5000, 0,0};
	InfoCasa infoCasa3 = {3, 1,"Voce se tornou YouTuber! Salario de R$ 30000. Ande mais 10 casas.",0,30000,1, 10};
	InfoCasa infoCasa4 = {4, 2,"Entrou na Faculdade. Ganhe R$2000.", 1, 2000, 0,0};
	InfoCasa infoCasa5 = {5, 2,"Comprou um computador novo para a faculdade. Pague R$2000.", 1, 2000, 0,0};
	InfoCasa infoCasa6 = {6, 1,"MEDICO! Salario R$ 50.000. Ande mais 7 casas!",0,50000,1, 7};
	InfoCasa infoCasa7 = {7, 1,"ARTISTA! Salario R$ 24.000. Ande mais 6 casas!",0,24000,1, 6};
	InfoCasa infoCasa8 = {8, 1,"ADVOGADO! Salario R$ 50.000. Ande mais 5 casas!",0,50000, 1, 5};
	InfoCasa infoCasa9 = {9, 2,"Alugou um Apartamento. Pague R$2000.", 1, -2000, 0,0};
	InfoCasa info10 = {10, 1,"ENGENHEIRO! Salario de R$ 30.000. Ande mais 3 casas!",0, 30000, 1, 3};
	InfoCasa infoCasa11 = {11, 1,"PROFESSOR! Salario de R$ 20.000. Ande mais 2 casas!", 0, 20000, 1, 2};
	InfoCasa infoCasa12 = {12, 1,"Diploma Universitario! Salario de R$ 16.000. Ande mais 1 casa!", 0, 16000, 1, 1};
	InfoCasa infoCasa13 = {13, 3,"Dia do Pagamento!", 0, 0, 0, 0};

	retorno = insereInicioListaTabuleiro(lista, infoCasa1); // retorno = 1
	retorno = insereInicioListaTabuleiro(lista, infoCasa2); // retorno = 1
	retorno = insereInicioListaTabuleiro(lista, infoCasa3); // retorno = 1
	retorno = insereInicioListaTabuleiro(lista, infoCasa4); // retorno = 1
	retorno = insereInicioListaTabuleiro(lista, infoCasa5);

	imprimeListaTabuleiro(lista);
}

// Funcao que destroi uma lista
void destroiListaTabuleiro(ListaEnc2 *lista){
   NodoLEnc2 *aux = lista->prim;
   while(aux != NULL){
       NodoLEnc2 *tmp = aux->prox;
       free(aux); // Cuidar ordem do free
       aux = tmp;
   }
   free(lista);
}

// Funcao que imprime todos os nodos de uma lista
void imprimeListaTabuleiro(ListaEnc2 *lista){
   NodoLEnc2 *aux;
   printf("-----------------------------------------\n");
   for(aux = lista->prim; aux != NULL; aux = aux->prox)
      printf("%d | tipo: %d Texto: %s (%d) Dinheiro: %.f %d %.f membroDaFamilia: %d\n", aux->infoCasa.numeroDaCasa,
                               aux->infoCasa.tipoDeCasa,
                               aux->infoCasa.textoDaCasa,
							   aux->infoCasa.ganhaPerdeDinheiro,
							   aux->infoCasa.Dinheiro,
							   aux->infoCasa.andaCasa,
							   aux->infoCasa.quantasCasas,
							   aux->infoCasa.membroDaFamilia);
   printf("-----------------------------------------\n");
}

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEnc2* buscaInfoListaTabuleiro(ListaEnc2* lista, int numeroDaCasa){
   NodoLEnc2 *aux;
   for(aux = lista->prim; aux != NULL; aux = aux->prox)
      if (aux->infoCasa.numeroDaCasa == numeroDaCasa)
         return aux;
   return NULL;
}

// Funcao que insere um nodo no inicio de uma lista
int insereInicioListaTabuleiro(ListaEnc2 *lista, InfoCasa infoCasa){
   NodoLEnc2 *novo = (NodoLEnc2*)malloc(sizeof(NodoLEnc2));
   novo->infoCasa = infoCasa;
   novo->ant = NULL;
   novo->prox = lista->prim;
   if (lista->prim != NULL)
      lista->prim->ant = novo;
   lista->prim = novo;
   return 1;
}

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoListaTabuleiro(ListaEnc2* lista, int numeroDaCasa){
   NodoLEnc2 *aux = lista->prim;
   while(aux != NULL && aux->infoCasa.numeroDaCasa != numeroDaCasa){
      aux = aux->prox;
   }
   if (aux != NULL){
      if (aux->ant == NULL){
         lista->prim = aux->prox;
         if (aux->prox != NULL)
            aux->prox->ant = NULL;
      }else{
         aux->ant->prox = aux->prox;
         if (aux->prox != NULL)
            aux->prox->ant = aux->ant;
      }
      free(aux);
      return 1;
   }
   return 0; // Nao encontrou
}
 //(tabuleiro,jogador1,8)
void IniciaAndaCasas(ListaEnc2* tabuleiro, ListaEncCircularJogador *jogadores, int numeroDeCasas){
	NodoLEncCircularJogador *aux ;
	NodoLEnc2 *auxtab;

	aux = jogadores->prim;

	int flag = 0, num = 0;

	printf("\ndinheiro antes: %d", aux->info.dinheiro);


	printf("\n\n%d | posicao:%d dinheiro: %d familia: %d\n", aux->info.numJogador,
                                                           aux->info.posicao,
                                                           aux->info.dinheiro,
                                                           aux->info.familia);

	aux->info.posicao += numeroDeCasas;
	num = aux->info.posicao;

	//imprimeCasaAtual(num, tabuleiro);
	auxtab = buscaInfoListaTabuleiro(tabuleiro, num);



	int i;
	//int novoMembroDaFamilia;

	switch(auxtab->infoCasa.tipoDeCasa){
		case 1: // casa de profiss???o
			printf("\n\nentrou no case 1");
			i = auxtab->infoCasa.Dinheiro;
			printf("\ndinheiro: %d", i);
			aux->info.salario = i;
			printf("\n\n\n Salario: %d",aux->info.salario);
			aux->info.dinheiro += aux->info.salario;
			printf("\n\n\n Salario: %d\n\nDinheiro: %d",aux->info.salario, aux->info.dinheiro );

//			if( auxtab->infoCasa.andaCasa != 0){
//				aux->info.posicao += auxtab->infoCasa.quantasCasas;
//			}
			printf("\n\n%d | posicao:%d dinheiro: %d familia: %d\n", aux->info.numJogador,
                                                           aux->info.posicao,
                                                           aux->info.dinheiro,
                                                           aux->info.familia);
			
	}
}

void AcaoDaCasa(ListaEnc2 *casa, ListaEncCircularJogador *jogador){
   
  
	switch(casa->prim->infoCasa.tipoDeCasa){
		case 1: // casa de profiss??o
			jogador->fim->info.salario = casa->prim->infoCasa.Dinheiro;
			printf("\n\n\n Salario: %d",jogador->fim->info.salario);

			break;
		case 2: //Perde Dinheiro/Ganho de Dinheiro
			aux->info.dinheiro += auxtab->infoCasa.Dinheiro;
			printf("\n\n\n Salario: %d\n\nDinheiro: %d",aux->info.salario, aux->info.dinheiro );
			break;
		case 3: //Dia do Pagamento
			if (aux->info.salario == 0 ){
				aux->info.salario = 16000;
			}
			aux->info.dinheiro += aux->info.salario;
			printf("\n\n\n Salario: %d\n\nDinheiro: %d",aux->info.salario, aux->info.dinheiro );
			break;
		//case 4: //

//		case 5: //Aumentando a familia
//			novoMembroDaFamilia = auxtab->infoCasa.membroDaFamilia;
//			aux->info.familia += novoMembroDaFamilia;
//			break;
	}

   printf("\n\n%d | posicao:%d dinheiro: %d familia: %d\n", aux->info.numJogador,
                                                           aux->info.posicao,
                                                           aux->info.dinheiro,
                                                           aux->info.familia);
}


void imprimeCasaAtual(int num, ListaEnc2* tabuleiro){
	NodoLEnc2 *auxtab;
	auxtab = buscaInfoListaTabuleiro(tabuleiro, num);

	//system("cls");
	printf("\nCasa: %d \n\n\t|Texto: %s\n", auxtab->infoCasa.numeroDaCasa, auxtab->infoCasa.textoDaCasa);

    return auxtab;
}

