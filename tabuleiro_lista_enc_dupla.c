#include "jogador_listaEncCircular.h"
#include "roleta_listaEncCircular.h"
#include "tabuleiro_lista_enc_dupla.h"
#include <stdio.h>
//#include <windows.h>
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
    InfoCasa infoCasa10 = {10, 1,"ENGENHEIRO! Salario de R$ 30.000. Ande mais 3 casas!",0, 30000, 1, 3};
    InfoCasa infoCasa11 = {11, 1,"PROFESSOR! Salario de R$ 20.000. Ande mais 2 casas!", 0, 20000, 1, 2};
    InfoCasa infoCasa12 = {12, 1,"Diploma Universitario! Salario de R$ 16.000. Ande mais 1 casa!", 0, 16000, 1, 1};
    InfoCasa infoCasa13 = {13, 3,"Dia do Pagamento!", 0, 0, 0, 0};

    retorno = insereInicioListaTabuleiro(lista, infoCasa1); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa13); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa12); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa11); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa10);
    retorno = insereInicioListaTabuleiro(lista, infoCasa9); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa8); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa7); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa6); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa5);
    retorno = insereInicioListaTabuleiro(lista, infoCasa4); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa3); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa2); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa1);
    
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
   for(aux = lista->prim; aux != NULL; aux = aux->ant)
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

NodoLEnc2* buscaInfoListaTabuleiro(ListaEnc2* lista, int numeroDaCasa){
   NodoLEnc2 *aux;
    aux = lista->prim;
    
    
    for(aux = lista->prim; aux != NULL; aux = aux->prox){
       if (aux->infoCasa.numeroDaCasa == numeroDaCasa){
           return aux;
       }
        
    }
   return NULL;
}

NodoLEnc2* buscaInfoListaInicialTabuleiro(ListaEnc2* lista, NodoLEncCircularJogador *jogador, int casaInicial){
   NodoLEnc2 *aux;
    aux = lista->prim;
    printf("Primeiro: %d | tipo: %d Texto: %s (%d) Dinheiro: %.f %d %.f membroDaFamilia: %d\n\n\n", aux->infoCasa.numeroDaCasa,
                                 aux->infoCasa.tipoDeCasa,
                                 aux->infoCasa.textoDaCasa,
                                 aux->infoCasa.ganhaPerdeDinheiro,
                                 aux->infoCasa.Dinheiro,
                                 aux->infoCasa.andaCasa,
                                 aux->infoCasa.quantasCasas,
                                 aux->infoCasa.membroDaFamilia);
    
    
    for(aux = lista->prim; aux != NULL; aux = aux->prox){
       if (aux->infoCasa.numeroDaCasa == casaInicial){
           printf("\n\nretornando aux: ");
           printf("\n%d | tipo: %d Texto: %s (%d) Dinheiro: %.f %d %.f membroDaFamilia: %d\n\n\n", aux->infoCasa.numeroDaCasa,
                                        aux->infoCasa.tipoDeCasa,
                                        aux->infoCasa.textoDaCasa,
                                        aux->infoCasa.ganhaPerdeDinheiro,
                                        aux->infoCasa.Dinheiro,
                                        aux->infoCasa.andaCasa,
                                        aux->infoCasa.quantasCasas,
                                        aux->infoCasa.membroDaFamilia);
           return aux;
       }
        
    }
   return NULL;
}



// Funcao que resgata um nodo com uma informacao de uma lista
int buscaInfoListaFinalTabuleiro(ListaEnc2* tabuleiro, NodoLEncCircularJogador *jogador, int numInicial){
    NodoLEnc2 *auxtab;
    int i = 0;
    
    auxtab = buscaInfoListaTabuleiro(tabuleiro, numInicial);
    
    
    while (auxtab->infoCasa.numeroDaCasa != jogador->info.posicao ) {
        auxtab = auxtab->prox;
        
        if(auxtab->infoCasa.tipoDeCasa == 3){
            i ++;
        }
        
    }
      
    return i;
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


// Funcao que realiza o percorrimento do jogador entre as casas
void andarCasas(ListaEnc2* tabuleiro, NodoLEncCircularJogador *jogador, int numeroDeCasas, ListaEncCircularRoleta *roleta){
    int i, casaFinal = 0, novoMembroDaFamilia = 0, casaInicial = 0, resultado = 0, foiFimDeJogo = 0;
    NodoLEncCircularJogador *aux ;                                              // tipo do nodo do jogador
    NodoLEnc2 *auxtab;                                                          // tipo do nodo do tabuleiro
    
    aux = jogador;
    
    casaInicial = aux->info.posicao;                                            // a variavel casaInicial recebe a posicao inicial do jogador
    aux->info.posicao += numeroDeCasas;                                         // faz o jogador ir para a casa em que a roleta sorteou
    casaFinal = aux->info.posicao;                                                    // num recebe a posicao final do jogador
  
    resultado = existeDiaDoPagamentoEntreAsCasas(tabuleiro, aux, casaInicial, casaFinal);  // verifica se entre a casa inicial e final há casas do tipo Dia do Pagamento
    diaDoPagamento(aux, resultado);                                             // realiza o dia do pagamento caso tenha casas entre a inicial e final
    
    //fimDeJogoPorPosicao();
    
    
    auxtab = buscaInfoListaTabuleiro(tabuleiro, casaFinal);                     //Busca as informacoes da Casa final
    imprimeCasaAtual(casaFinal, tabuleiro, jogador);                            //Imprime a casa Final (que se torna a casa Atual do jogador)
    
    switch(auxtab->infoCasa.tipoDeCasa){                                        // Verifica que tipo de casa é a Casa atual do jogador
        case 1:                                                                 // casa de profissao: faz com que o jogador receba um salario
            i = auxtab->infoCasa.Dinheiro;                                      // Recebe a informacao de quanto dinheiro o jogador deve receber
            aux->info.salario = i;                                              // Grava o salario do jogador no ponteiro do jogador
            aux->info.dinheiro += aux->info.salario;                            // Dá o salario para o jogador
            
            if (auxtab->infoCasa.andaCasa != 0){                                // Verifica seénecessario andar casas
                aux->info.posicao += auxtab->infoCasa.quantasCasas;             // Anda as casas
                if (auxtab->infoCasa.quantasCasas < 0) {                        // Verifica se é uma casa de avançar ou retroceder
                    printf("Voce Retrocedeu %.f Casas", auxtab->infoCasa.quantasCasas);
                }else{
                    printf("Voce Avançou %.f Casas", auxtab->infoCasa.quantasCasas);
                }
            }
            break;
            
        case 2:                                                                 // Perde Dinheiro/Ganha Dinheiro
            aux->info.dinheiro += auxtab->infoCasa.Dinheiro;                    // Realiza a soma do Dinheiro
            foiFimDeJogo = fimDeJogoPorDinheiro(aux);
            printf("\n\n\n Dinheiro: %d", aux->info.dinheiro);
            break;
            
        case 3:                                                                 //Dia do Pagamento
            if(aux->info.salario == 0){
                aux->info.salario = 16000;
            }
            diaDoPagamento(aux, 1);
            
            printf("\n\n%d | posicao:%d dinheiro: %d familia: %d\n", aux->info.numJogador,
                                                                   aux->info.posicao,
                                                                   aux->info.dinheiro,
                                                                   aux->info.familia);
            break;
            
        case 5: //Aumentando a familia
            novoMembroDaFamilia = auxtab->infoCasa.membroDaFamilia;
            aux->info.familia += novoMembroDaFamilia;
            break;
    }
}


// Funcao que verifica se ha dia do pagamento entre as casas inicial e final da posicao do jogador
int existeDiaDoPagamentoEntreAsCasas(ListaEnc2* lista, NodoLEncCircularJogador *jogador, int inicioCasa, int fimCasa){
    NodoLEnc2 *aux = lista->prim;
    int i = 0;
    
    while( aux->infoCasa.numeroDaCasa <= inicioCasa){       //Chega até a casa inicial do jogador (casa atual antes da roleta)
       aux = aux->prox;

    }
    while(aux->infoCasa.numeroDaCasa < fimCasa){            //Chega até a casa final do jogador (casa que foi sorteada pela roleta)
        if(aux->infoCasa.tipoDeCasa == 3){
            i++;                                            // soma a quantidades de casa do tipo Dia do Pagamento
        }
        aux = aux->prox;
    }
    return i;                                               // Retorna o numero de casas do Dia do Pagamento
}


// Funcao que realiza o dia do pagamento
void diaDoPagamento(NodoLEncCircularJogador *jogador, int numeroDeCasasDeDiaDoPagamento){
    int i = 0;
    
    if(jogador->info.salario == 0){                 // Caso o jogador ainda nao tenha uma profissao,
        jogador->info.salario = 16000;              // o salario dele passa a ser 16k
    }
    
    for (i = 0; i < numeroDeCasasDeDiaDoPagamento; i++){
        jogador->info.dinheiro += jogador->info.salario;    //Realiza o pagamento do salario
    }
}


// Imprime a casa Atual do jogador
void imprimeCasaAtual(int num, ListaEnc2* tabuleiro, NodoLEncCircularJogador *jogador){
    NodoLEnc2 *auxtab;
    auxtab = buscaInfoListaTabuleiro(tabuleiro, num);

    //system("cls");
    printf("\n\t\t|Casa: %d |\n\n\t\t| %s |\n", auxtab->infoCasa.numeroDaCasa, auxtab->infoCasa.textoDaCasa);

}

int fimDeJogoPorDinheiro(NodoLEncCircularJogador *jogador){
    if (jogador->info.dinheiro == 0){
        return 1;
    }
    return 0;
}


//int fimDeJogoPorPosicao(ListaEncCircularJogador* listaDeJogadores, NodoLEncCircularJogador *jogador){
//    if (listaDeJogadores->fim == jogador->prox){
//        return 1;                                   // Caso em que precisa que o 2 jogador jogue antes de acabar o jogo
//    }else {
//        return 2;                                   // Caso em que nao precisa que o outro jogador jogue, por ser o ultimo a ter jogado
//    }
//    return 0;
//}
