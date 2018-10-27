/*TAD FILA*/
typedef struct Scelula *Tapontador;
typedef struct Scelula{
	tipoitem info;
    Tapontador prox;
}Tcelula;
typedef struct{
    int tamanho;
    Tapontador comeco;
    Tapontador fim;
}Tfila;
 
void Tfila_inicia(Tfila *fila){
    fila->tamanho=0;
    fila->comeco=NULL;
    fila->fim=NULL;
}
void Tfila_retira(Tfila *fila,tipoitem *x){
    Tapontador aux;
    aux=fila->comeco;
    fila->comeco=fila->comeco->prox;
	*x=aux->info;
    fila->tamanho--;
    free(aux);
}
void Tfila_insere(Tfila *fila,tipoitem x){
    Tapontador novo;
    novo=(Tapontador)malloc(sizeof(Tcelula));
    if(novo!=NULL){
		novo->info=x;
		if(fila->tamanho!=0){
            fila->fim->prox=novo;
            fila->fim=novo;
            novo->prox=NULL;
            fila->tamanho++;
        }
        else{
            fila->comeco=novo;
            fila->fim=novo;
            fila->comeco->prox=NULL;
            fila->tamanho++;
        }
		novo=NULL;
    }
    else
        Tfila_insere(fila,x);
}
/*FIM DO TAD FILA*/