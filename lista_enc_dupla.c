#include "lista_enc_dupla.h"
#include <stdio.h>
#include <stdlib.h>


void imprimeRoleta(){
    printf("        , - ~ ~ ~ - ,\n");
    printf("    ,'       10       ,\n");
    printf("  ,  9              1   ,\n");
    printf(" ,                        ,\n");
    printf(",  8                    2  ,\n");
    printf(",                          ,\n");
    printf(",  7                     3 ,\n");
    printf(" ,                         ,\n");
    printf("  , 6                  4  ,\n");
    printf("    ,         5        , '\n");
    printf("      ' - , _ _ _ , '\n");
}


//funcao que imprime o Slogan do Jogo
void imprimeSlogan(){
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
}


// Funcao que cria uma lista
ListaEnc2* criaLista(){
   ListaEnc2 *lista = (ListaEnc2*)malloc(sizeof(ListaEnc2));
   lista->prim = NULL;
   return lista;
}

// Funcao que destroi uma lista
void destroiLista(ListaEnc2 *lista){
   NodoLEnc2 *aux = lista->prim;
   while(aux != NULL){
       NodoLEnc2 *tmp = aux->prox;
       free(aux); // Cuidar ordem do free
       aux = tmp;
   }
   free(lista);
}

void adicionaCasasNoTabuleiro(){

    int retorno;
    ListaEnc2 *lista;
    lista = criaLista();


    Informacao info1 = {1, 1,"Voce se tornou Medico",50000};
    Informacao info2 = {2, 1,"Voce se tornou Advogado",50000};
    Informacao info3 = {3, 1,"Voce se tornou Engenheiro",30000};
    Informacao info4 = {4, 1,"Voce se tornou Professor",20000};
    Informacao info5 = {5, 1,"Voce se tornou Artista",24000};
    Informacao info6 = {6, 1,"Voce se tornou Tecnico de TI",16000};
    Informacao info7 = {7, 1,"Voce se tornou Tecnico de Enfermagem",12000};
    Informacao info8 = {8, 1,"Voce se tornou YouTuber",10000};
    retorno = insereInicioLista(lista, info1);
    retorno = insereInicioLista(lista, info2);
    retorno = insereInicioLista(lista, info3);
    retorno = insereInicioLista(lista, info4);
    retorno = insereInicioLista(lista, info5);
    retorno = insereInicioLista(lista, info6);
    retorno = insereInicioLista(lista, info7);
    retorno = insereInicioLista(lista, info8);
    imprimeTesteRoleta(lista);
}






// Funcao que imprime todos os nodos de uma lista
void imprimeLista(ListaEnc2 *lista){
   NodoLEnc2 *aux;
   printf("-----------------------------------------\n");
   for(aux = lista->prim; aux != NULL; aux = aux->prox)
      printf("id: %d tipo: %d texto: %s dinheiro: %d\n", aux->info.idCasa,
                                                           aux->info.tipoDeCasa,
                                                           aux->info.textoDaCasa,
                                                           aux->info.dinheiro);
   printf("-----------------------------------------\n");
}

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEnc2* buscaInfoLista(ListaEnc2* lista, int idCasa){
   NodoLEnc2 *aux;
   for(aux = lista->prim; aux != NULL; aux = aux->prox)
      if (aux->info.idCasa == idCasa)
         return aux;
   return NULL;
}

// Funcao que insere um nodo no inicio de uma lista
int insereInicioLista(ListaEnc2 *lista, Informacao info){
   NodoLEnc2 *novo = (NodoLEnc2*)malloc(sizeof(NodoLEnc2));
   novo->info = info;
   novo->ant = NULL;
   novo->prox = lista->prim;
   if (lista->prim != NULL)
      lista->prim->ant = novo;
   lista->prim = novo;
   return 1;
}

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoLista(ListaEnc2* lista, int idCasa){
   NodoLEnc2 *aux = lista->prim;
   while(aux != NULL && aux->info.idCasa != idCasa){
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


