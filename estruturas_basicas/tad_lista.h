/*TAD LISTA*/
typedef struct Scelula *Tapontador;
typedef struct Scelula{
	tipoitem info;
	Tapontador prox;
}Tcelula;
typedef struct{
	int tamanho;
	Tapontador prox;
}Tlista;

void Tlista_inicia(Tlista *lista){
    Tapontador sentinela;
	sentinela=(Tapontador)malloc(sizeof(Tcelula));
	if(sentinela==NULL)
		exit(-1);
	sentinela->prox=NULL;
	lista->prox=sentinela;
    lista->tamanho=0;
	sentinela=NULL;
}
void Tlista_insere(Tlista *lista,Tapontador anterior,tipoitem x){
	Tapontador novo;
	novo=(Tapontador)malloc(sizeof(Tcelula));
	if(novo==NULL)
		exit (-1);
	novo->info=x;
	novo->prox=anterior->prox;
	anterior->prox=novo;
	lista->tamanho++;
}
void Tlista_retira(Tlista *lista,Tapontador anterior,tipoitem *x){
	Tapontador retirar;
	retirar=anterior->prox;
	anterior->prox=retirar->prox;
	*x=retirar->info;
	lista->tamanho--;
	free(retirar);
}
Tapontador Tlista_localiza(Tlista *lista,tipoitem x){
	Tapontador aux;
	aux=lista->prox;
	while(aux->prox->info!=x&&aux->prox!=NULL)
		aux=aux->prox;
	return aux;
}
/*FIM TAD LISTA*/