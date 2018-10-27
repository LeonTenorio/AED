/*TAD PILHA*/
typedef struct SCelula *Tapontador;
typedef struct SCelula{
    tipoitem info;
    Tapontador prox;
}Tcelula;
typedef struct{
    int tam;
    Tapontador topo;
}Tpilha;
 
void Tpilha_empilha(Tpilha *pilha,tipoitem x){
    Tapontador novo;
    novo=(Tapontador)malloc(sizeof(Tcelula));
    novo->prox=NULL;
    novo->info=x;
    novo->prox=pilha->topo;
    pilha->topo=novo;
    pilha->tam++;
    novo=NULL;
}
void Tpilha_desempilha(Tpilha *pilha, tipoitem *x){
    Tapontador aux;
    aux=(Tapontador)malloc(sizeof(Tcelula));
    aux=pilha->topo;
    pilha->topo=aux->prox;
    *x=aux->info;
    free(aux);
    pilha->tam--;
}
void Tpilha_inicia(Tpilha *pilha){
    pilha->topo=NULL;
    pilha->tam=0;
}
/*FIM DO TAD PILHA*/