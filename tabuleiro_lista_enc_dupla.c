#include "jogador_listaEncCircular.h"
#include "roleta_listaEncCircular.h"
#include "tabuleiro_lista_enc_dupla.h"
#include "jogo.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

// Funcao que cria uma lista
ListaEnc2* criaListaTabuleiro(){
   ListaEnc2 *lista = (ListaEnc2*)malloc(sizeof(ListaEnc2));
   lista->prim = NULL;
   return lista;
}

// Funcao que inicia os tabuleiros
ListaEnc2* iniciaTabuleiro(){
    int retorno;
    ListaEnc2 *lista;
    lista = criaListaTabuleiro();
    

    InfoCasa infoCasa1 = {1, 2,"Raspou o carro no estacionamento. Pague R$1000.", -1000, 0,0,0};
    InfoCasa infoCasa2 = {2, 2,"Inicio das aulas. Pague a matricula R$5000.", -5000, 0,0,0};
    InfoCasa infoCasa3 = {3, 1,"Voce se tornou YouTuber! Salario de R$ 30000. Ande mais 10 casas.",30000,1, 10,0};
    InfoCasa infoCasa4 = {4, 2,"Entrou na Faculdade. Ganhe R$2000.", 2000, 0,0,0};
    InfoCasa infoCasa5 = {5, 2,"Comprou um computador novo para a faculdade. Pague R$2000.", -2000, 0,0,0};
    InfoCasa infoCasa6 = {6, 1,"MEDICO! Salario R$ 50.000. Ande mais 7 casas!",50000,1, 7,0};
    InfoCasa infoCasa7 = {7, 1,"ARTISTA! Salario R$ 24.000. Ande mais 6 casas!",24000,1, 6,0};
    InfoCasa infoCasa8 = {8, 1,"ADVOGADO! Salario R$ 50.000. Ande mais 5 casas!",50000, 1, 5,0};
    InfoCasa infoCasa9 = {9, 2,"Alugou um Apartamento. Pague R$2000.", -2000, 0,0,0};
    InfoCasa infoCasa10 = {10, 1,"ENGENHEIRO! Salario de R$ 30.000. Ande mais 3 casas!", 30000, 1, 3,0};
    InfoCasa infoCasa11 = {11, 1,"PROFESSOR! Salario de R$ 20.000. Ande mais 2 casas!", 20000, 1, 2,0};
    InfoCasa infoCasa12 = {12, 1,"Diploma Universitario! Salario de R$ 16.000. Ande mais 1 casa!", 16000, 1, 1,0};
    InfoCasa infoCasa13 = {13, 3,"Dia do Pagamento!", 0, 0, 0,0};

    InfoCasa infoCasa14 = {14, 2,"Hoje eh seu aniversario! Receba R$ 1.000.", 1000, 0, 0,0};
    InfoCasa infoCasa15 = {15, 2,"Achou Tesouro antigo no quintal. Receba R$ 24.000 .", 24000, 0, 0,0};
    InfoCasa infoCasa16 = {16, 2,"Voce vai abrir um negocio. Pague R$ 30.000 .", -30000, 0, 0,0};
    InfoCasa infoCasa17 = {17, 2,"Heranca! Receba R$ 300.000 .", 300000, 0, 0,0};
    InfoCasa infoCasa18 = {18, 2,"ENCHENTE! Volte 4 casas. Pague R$ 10.000.", -10000, 1, -4,0};
    InfoCasa infoCasa19 = {19, 3,"Dia do Pagamento!", 0, 0, 0,0};

    InfoCasa infoCasa20 ={20, 2,"Seu tio precisa de Ajuda. Pague R$ 2.000 .", -2000, 0, 0,0};
    InfoCasa infoCasa21 ={21, 5,"Dia do seu Casamento! Parabens!", 0, 0, 0,0};
    InfoCasa infoCasa22 ={22, 2, "Viagem de negocios. Pague R$ 3.000.",-3000,0,0,0};
    InfoCasa infoCasa23 ={23, 2, "Encanamento furado. Pague R$ 4000.", -4000,0,0,0};
    InfoCasa infoCasa24 ={24, 2, "Voce bateu o carro! Pague R$ 12.000.", -12000,0,0,0};
    InfoCasa infoCasa25 ={25, 2, "Comprou 2 cavalos. Pague R$ 60.000.",  -60000,0,0,0};
    InfoCasa infoCasa26 ={26, 3,"Dia do Pagamento!", 0, 0, 0,0};

    InfoCasa infoCasa27 ={27, 2, "Ajudou seu sogro. Pague R$ 2.000.", -2000,0,0,0 };
    InfoCasa infoCasa28 ={28, 2, "Ganhou na Loteria! Receba R$ 96.000.",96000,0,0,0};
    InfoCasa infoCasa29 ={29, 2, "Comprouum apartamento. Pague R$ 40.000.",40000,0,0,0};
    InfoCasa infoCasa30 ={30, 5, "Sua filha nasceu!",0,0,0,1};
    InfoCasa infoCasa31 ={31, 2, "Atravessou o Canal da Mancha nadando. Receba R$ 250.000.",250000,0,0,0};
    InfoCasa infoCasa32 ={32, 5, "Seus Gemeos Nasceram!",0,0,0,2};
    InfoCasa infoCasa33 ={33, 3, "Dia do Pagamento!", 0, 0, 0,0};

    InfoCasa infoCasa34 ={34, 2, "Voce deve impostos. Pague R$ 20.000.",-20000,0,0,0};
    InfoCasa infoCasa35 ={35, 5, "Seu filho nasceu!",0,0,0,1};
    InfoCasa infoCasa36 ={36, 2, "Achou pinturas famosas. Recebe R$ 248.000.", 248000,0,0,0};
    InfoCasa infoCasa37 ={37, 2, "Os negocios estao otimos! Receba R$ 100.000.",100000,0,0,0};
    InfoCasa infoCasa38 ={38, 2, "Bateu o carro!. Pague R$ 16.000.", -16000,0,0,0};
    InfoCasa infoCasa39 ={39, 2, "Sua invencaomaluca deu certo! Receba R$ 50.000.", 50000,0,0,0};
    InfoCasa infoCasa40 ={40, 5, "Voce adotou duas filhas!",0,0,0,2};
    InfoCasa infoCasa41 ={41, 3, "Dia do Pagamento!", 0, 0, 0,0};

    InfoCasa infoCasa42 ={42, 2, "Trocou seu apartamento por uma Cobertura! Pague R$ 200.000.",-200000,0,0,0};
    InfoCasa infoCasa43 ={43, 5, "Voce adotou um menino!",0,0,0,1};
    InfoCasa infoCasa44 ={44, 2, "DIA DE SORTE! Receba R$ 20.000.",20000,0,0,0};
    InfoCasa infoCasa45 ={45, 3, "Dia do Pagamento!", 0, 0, 0,0};

    InfoCasa infoCasa46 ={46, 2, "Acoes em Alta! Receba R$ 140.000", 140000, 0, 0,0};
    InfoCasa infoCasa47 ={47, 2, "Ampliou os Negocios. Pague R$ 120.000", -120000, 0, 0,0};
    InfoCasa infoCasa48 ={48, 2, "Acoes em Baixa! Pague R$ 16.000", 16000, 0, 0,0};
    InfoCasa infoCasa49 ={49, 2, "Escalou o Monte Everest. Receba R$ 120.000", 120000, 0, 0,0};
    InfoCasa infoCasa50 ={50, 2, "Chegou em Segundo lugar na competicao de Triathlon. Receba R$ 100.000",100000, 0, 0,0};
    InfoCasa infoCasa51 ={51, 2, "Expedicao ao Polo Norte. Pague R$ 100.000", -100000, 0, 0,0};
    InfoCasa infoCasa52 ={52, 3, "Dia do Pagamento!", 0, 0, 0,0};

    InfoCasa infoCasa53 ={53, 2, "Ganhou processo justicial. Receba R$ 240.000", 240000, 0, 0,0};
    InfoCasa infoCasa54 ={54, 2, "Os negocios estao otimos! Receba R$ 100.000.",100000,0,0,0};
    InfoCasa infoCasa55 ={55, 2, "Assaltado! Pague R$ 10.000.", -10000,0,0,0};
    InfoCasa infoCasa56 ={56, 2, "Herdou um barco do seu Tio! Receba R$ 10.000.", 10000,0,0,0};
    InfoCasa infoCasa57 ={57, 2, "Fez um cruzeiro pelo Mundo! Pague R$ 20.000.", -20000,0,0,0};
    InfoCasa infoCasa58 ={58, 2, "Seu primo foi preso. Pague R$ 2.000.",-2000,0,0,0};
    InfoCasa infoCasa59 ={59, 3, "Dia do Pagamento!", 0, 0, 0,0};

    InfoCasa infoCasa60 ={60, 2, "Escreveu um best-seller. Receba R$ 96.000.", 960000,0,0,0};
    InfoCasa infoCasa61 ={61, 2, "O encanamenti estourou novamente. Pague R$ 10.000.", -10000,0,0,0};
    InfoCasa infoCasa62 ={62, 2, "Comprou um helicoptero. Pague R$ 100.000.", 100000,0,0,0};
    InfoCasa infoCasa63 ={63, 2, "Seu bode comeu orquideas premiadas. Pague R$ 3.000.", -3000,0,0,0};
    InfoCasa infoCasa64 ={64, 2, "Comprou um iate. Pague R$ 80.000.", -80000,0,0,0};
    InfoCasa infoCasa65 ={65, 2, "Voce deve impostos. Pague R$ 20.000.", -20000,0,0,0};
    InfoCasa infoCasa66 ={66, 2, "Doe R$ 10.000 para a caridade.",-10000,0,0,0};
    InfoCasa infoCasa67 ={67, 3, "Dia do Pagamento!", 0, 0, 0,0};

    InfoCasa infoCasa68 ={68, 2, "Acoes em Alta! Receba R$ 140.000", 140000, 0, 0,0};
    InfoCasa infoCasa69 ={69, 2, "Doe R$ 120.000 para um orfanato.", -120000,0,0,0};
    InfoCasa infoCasa70 ={70, 2, "Voce precisa de Dentaduras. Pague R$ 2.000.", -2000,0,0,0};
    InfoCasa infoCasa71 ={71, 2, "Herdou uma fazenda de gados. Receba R$ 240.000.", 240000,0,0,0};
    InfoCasa infoCasa72 ={72, 2, "Comprou um carro de luxo. Pague R$ 80.000.",-80000,0,0,0};
    InfoCasa infoCasa73 ={73, 2, "Ganhou o premio Nobel. Receba R$ 240.000.",240000,0,0,0};
    InfoCasa infoCasa74 ={74, 3, "Dia do Pagamento!", 0, 0, 0,0};

    InfoCasa infoCasa75 ={75, 2, "Viagem a Europa. Pague R$ 20.000.",-20000,0,0,0};
    InfoCasa infoCasa76 ={76, 2, "Cruzeiro pelo Mundo. Pague R$ 70.000.", -70000,0,0,0};
    InfoCasa infoCasa77 ={77, 2, "Vendeu joias de familia. Ganhe R$ 200.000.", 200000,0,0,0};
    InfoCasa infoCasa78 ={78, 3, "Dia do Pagamento!",  0, 0, 0,0};
    InfoCasa infoCasa79 ={79, 2, "Comprou um diamante falso. Pague R$ 20.000.",-20000,0,0,0};
    InfoCasa infoCasa80 ={80, 2, "Acoes em Alta! Receba R$ 140.000", 140000, 0, 0,0};


	retorno = insereInicioListaTabuleiro(lista, infoCasa80); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa79); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa78); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa77); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa76); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa75); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa74); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa73); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa72); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa71); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa70); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa69); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa68); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa67); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa66); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa65); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa64); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa63); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa62); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa61); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa60); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa59); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa58); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa57); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa56); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa55); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa54); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa53); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa52); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa51); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa50); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa49); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa48); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa47); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa46); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa45); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa44); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa43); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa42); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa41); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa40); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa39); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa38); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa37); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa36); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa35); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa34); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa33); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa32); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa31); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa30); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa29); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa28); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa27); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa26); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa25); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa24); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa23); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa22); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa21); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa20); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa19); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa18); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa17); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa16); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa15); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa14); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa13); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa12); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa11); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa10); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa9); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa8); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa7); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa6); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa5); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa4); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa3); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa2); // retorno = 1
    retorno = insereInicioListaTabuleiro(lista, infoCasa1); // retorno = 1

    return  lista;  // retorna o tabuleiro

}

// Funcao que destroi uma lista
void destroiListaTabuleiro(ListaEnc2 *lista){
   NodoLEnc2 *aux = lista->prim;
   while(aux != NULL){
       NodoLEnc2 *tmp = aux->prox;
       free(aux);
       aux = tmp;
   }
   free(lista);
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
    int i, casaFinal = 0, novoMembroDaFamilia = 0, casaInicial = 0, resultado = 0;
    NodoLEncCircularJogador *aux ;      // tipo do nodo do jogador
    NodoLEnc2 *auxtab;                  // tipo do nodo do tabuleiro

    aux = jogador;

    casaInicial = aux->info.posicao;    // a variavel casaInicial recebe a posicao inicial do jogador
    aux->info.posicao += numeroDeCasas; // faz o jogador ir para a casa em que a roleta sorteou
    casaFinal = aux->info.posicao;      // num recebe a posicao final do jogador

    resultado = existeDiaDoPagamentoEntreAsCasas(tabuleiro, aux, casaInicial, casaFinal);  // verifica se entre a casa inicial e final há casas do tipo Dia do Pagamento
    diaDoPagamento(aux, resultado);     // realiza o dia do pagamento caso tenha casas entre a inicial e final

    auxtab = buscaInfoListaTabuleiro(tabuleiro, casaFinal);     //Busca as informacoes da Casa final
    imprimeCasaAtual(casaFinal, tabuleiro, jogador);            //Imprime a casa Final (que se torna a casa Atual do jogador)

    switch(auxtab->infoCasa.tipoDeCasa){                        // Verifica que tipo de casa é a Casa atual do jogador
        case 1:                                                 // casa de profissao: faz com que o jogador receba um salario
            i = auxtab->infoCasa.Dinheiro;                      // Recebe a informacao de quanto dinheiro o jogador deve receber
            aux->info.salario = i;                              // Grava o salario do jogador no ponteiro do jogador
            aux->info.dinheiro += aux->info.salario;            // Dá o salario para o jogador

            if (auxtab->infoCasa.andaCasa != 0){                                // Verifica se énecessario andar casas
                aux->info.posicao += auxtab->infoCasa.quantasCasas;             // Anda as casas
                if (auxtab->infoCasa.quantasCasas < 0) {                        // Verifica se é uma casa de avançar ou retroceder
                    printf("\t\tVoce Retrocedeu %.f Casas\n\n", auxtab->infoCasa.quantasCasas);
                }else{
                    printf("\t\tVoce Avancou %.f Casas\n\n", auxtab->infoCasa.quantasCasas);
                }
            }
            break;

        case 2:                                                                 // Perde Dinheiro/Ganha Dinheiro
            aux->info.dinheiro += auxtab->infoCasa.Dinheiro;                    // Realiza a soma do Dinheiro
            break;

        case 3:                                                                 //Dia do Pagamento
            if(aux->info.salario == 0){
                aux->info.salario = 16000;
            }
            diaDoPagamento(aux, 1);
            break;

        case 5:                                                                 //Aumentando a familia
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
    if ( i > 0){
        printf("\n\tVoce passou por %d casa(s) do pagamento.\n\tSeu saldo eh: %d\n\n", i, jogador->info.dinheiro);
    }
}


// Imprime a casa Atual do jogador
void imprimeCasaAtual(int num, ListaEnc2* tabuleiro, NodoLEncCircularJogador *jogador){
    NodoLEnc2 *auxtab;
    auxtab = buscaInfoListaTabuleiro(tabuleiro, num);

    //system("cls");
    printf("\n\t|Casa: %d |\n\n\t| %s |\n\n", auxtab->infoCasa.numeroDaCasa, auxtab->infoCasa.textoDaCasa);

}
