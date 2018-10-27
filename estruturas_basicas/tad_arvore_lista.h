#include <stdio.h>
#include <stdlib.h>
 
typedef int tipoitem;
typedef int quantidade;
typedef struct Sarvore *Tno;
typedef struct Scelula *Tapontador;
 
/*TAD Arvore - Uma "Tlista" onde cada elemento da lista aponta para o seu irmao e contem uma subarvore*/
typedef struct Sarvore{
    tipoitem info;
    quantidade filhos;
    Tapontador primeiro,ultimo;
}Tarvore;
typedef struct Scelula{
    Tapontador prox;
    Tno subarvore;
}Tcelula;
 
Tno Tarvore_inicia(tipoitem x){
    /*Inicia e retorna uma arvore para o item x - o pai x*/
    Tapontador sentinela;
    Tno novo;
    novo=(Tno)malloc(sizeof(Tarvore));
    if(novo==NULL)
        exit (-1);
    novo->filhos=0;
    novo->info=x;
    sentinela=(Tapontador)malloc(sizeof(Tcelula));
    if(sentinela==NULL)
        exit (-1);
    sentinela->subarvore=NULL;
    sentinela->prox=NULL;
    novo->primeiro=sentinela;
    novo->ultimo=sentinela;
    sentinela=NULL;
    return (novo);
    novo=NULL;
}
void Tarvore_adiciona(Tno arvore,tipoitem x){
    /*Adiciona na arvore o item x na ultima posicao da lista de arvore*/
    Tapontador anterior=arvore->ultimo;
    Tapontador novo;
    novo=(Tapontador)malloc(sizeof(Tcelula));
    if(novo==NULL)
        exit (-1);
    novo->prox=anterior->prox;
    novo->subarvore=Tarvore_inicia(x);
    arvore->ultimo=novo;
    anterior->prox=novo;
    anterior=NULL;
    novo=NULL;
    arvore->filhos++;
}
Tno Tarvore_localiza(Tno arvore,tipoitem x){
     /*Funcao que localiza em qual posicao esta o item x na arvore por recursividade*/
     Tapontador local;
     Tno aux;
     if(arvore!=NULL){
        /*Se a arvore nao for vazia*/
         if(arvore->info==x)/*Se a subarvore atual ja for o Tno que estamos procurando*/
             return arvore;
         else{
             /*Se a subarvore nao eh o Tno que estamos procurando*/
             local=arvore->primeiro->prox;
            /*Comecar a vascular nas subarvores da lista da arvore ate o fim da lista*/
             while(local!=NULL){
                  aux=Tarvore_localiza(local->subarvore,x);
                  if(aux!=NULL)/*Se os ramos das arvores abaixo da funcao atual conterem o tipoitem x*/
                        return aux;
                  local=local->prox;
             }
          }
     }
     /*Se nao foi encontrado nada na procura atual*/
     aux=NULL;
     return aux;
}