/*TAD LISTA CIRCULAR*/
typedef struct Scelula *Tapontador;
typedef struct Scelula{
	tipoitem info;
	Tapontador prox;
}Tcelula;
typedef struct{
	int tamanho;
	Tapontador ultimo;
}Tlista;

void Tlista_inicia(Tlista *lista){
    Tapontador sentinela;
	sentinela=(Tapontador)malloc(sizeof(Tcelula));
	if(sentinela==NULL)
		exit (-1);
	sentinela->prox=sentinela;
	lista->ultimo=sentinela;
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
	if(anterior==lista->ultimo)
		lista->ultimo=novo;
	lista->tamanho++;
	novo=NULL;
}
void Tlista_retira(Tlista *lista,Tapontador anterior,tipoitem *x){
	Tapontador retirar;
	retirar=anterior->prox;
	anterior->prox=retirar->prox;
	*x=retirar->info;
	if(retirar==lista->ultimo)
		lista->ultimo=anterior;
	lista->tamanho--;
	free(retirar);
}
Tapontador Tlista_localiza(Tlista *lista,tipoitem x){
	Tapontador aux;
	aux=lista->ultimo->prox;
	while(aux->prox->info!=x&&aux->prox!=lista->ultimo->prox)
		aux=aux->prox;
	return aux;
}
/*FIM TAD LISTA*/