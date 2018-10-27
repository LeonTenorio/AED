/*TAD Arvore de Busca*/

typedef struct Sno *Tno;
typedef struct Sno{
	tipoitem info;
	Tno esq,dir;
}Tarvbusca;

Tno Tarvbusca_inicia(tipoitem x){
	Tno retorna;
	retorna=(Tno)malloc(sizeof(Tarvbusca));
	if(retorna==NULL)
		exit (-1);
	retorna->info=x;
	retorna->esq=NULL;
	retorna->dir=NULL;
	return retorna;
}

int Tarvbusca_orienta(Tno arvore,tipoitem x){
	if(x==arvore->info)
		return 0;
	else if(x<arvore->info)
		return -1;
	else
		return 1;
}

Tno Tarvbusca_insere(Tno arvore,tipoitem x){
	Tno aux=arvore;
	int flag=0;
	if(aux==NULL){
		aux=Tarvbusca_inicia(x);
		return aux;
	}
	while(flag==0){
		if(Tarvbusca_orienta(aux,x)<0){
			//x eh a esquerda de aux
			if(aux->esq==NULL){
				aux->esq=Tarvbusca_inicia(x);
				flag=1;
			}
			else
				aux=aux->esq;
		}
		else if(Tarvbusca_orienta(aux,x)>0){
			//x eh a direita de aux
			if(aux->dir==NULL){
				aux->dir=Tarvbusca_inicia(x);
				flag=1;
			}
			else
				aux=aux->dir;
		}
		else
			return arvore;
	}
	return arvore;
}
Tno Tarvbusca_retira(Tno arvore){
	Tno aux=NULL,anterior;
	if((arvore->dir==NULL)&&(arvore->esq==NULL)){
		free(arvore);
		return aux;
	}
	//achar o substituto do noh
	if(arvore->dir!=NULL){
		/*Tem substituto a direita*/
		aux=arvore->dir;	anterior=arvore;
		while(aux->esq!=NULL){
			anterior=aux;
			aux=aux->esq;
		}
		if(anterior==arvore){
			/*Retirada do noh arvore*/
			aux->esq=anterior->esq;
			anterior->dir=NULL;	anterior->esq=NULL;
			free(anterior);
			return aux;
		}
		else{
			/*Retirada do noh arvore*/
			anterior->esq=aux->dir;
			aux->dir=NULL;
			aux->dir=arvore->dir;
			aux->esq=arvore->esq;
			free(arvore);
			return aux;
		}
	}
	else{
		/*Tem susbtituto a esquerda*/
		aux=arvore->esq;	anterior=arvore;
		while(aux->dir!=NULL){
			anterior=aux;
			aux=aux->dir;
		}
		if(anterior==arvore){
			/*Retirada do noh arvore*/
			aux->dir=anterior->dir;
			anterior->dir=NULL;	anterior->esq=NULL;
			free(anterior);
			return aux;
		}
		else{
			/*Retirada do noh arvore*/
			anterior->dir=aux->esq;
			aux->esq=NULL;
			aux->esq=arvore->esq;
			aux->dir=arvore->dir;
			free(arvore);
			return aux;
		}
	}
}
Tno Tarvbusca_localiza(Tno arvore,Tno *anterior,tipoitem x){
	//funcao que localiza o noh do item x na arvore e carrega na Tno *anterior o pai desse elemento
	Tno aux=arvore;
	int flag=0;
	while(arvore!=NULL){
		if(aux!=NULL){
			if(Tarvbusca_orienta(aux,x)<0){
				*anterior=aux;
				aux=aux->esq;
			}
			else if(Tarvbusca_orienta(aux,x)>0){
				*anterior=aux;
				aux=aux->dir;
			}
			else
				return aux;
		}
		else
			return aux;
	}
	return arvore;
}
void Tarvbusca_imprime_pre(Tno arvore){
	if(arvore!=NULL){
		printf("%d ",arvore->info);
		Tarvbusca_imprime_pre(arvore->esq);
		Tarvbusca_imprime_pre(arvore->dir);
	}
}
void Tarvbusca_imprime_em(Tno arvore){
	if(arvore!=NULL){
		Tarvbusca_imprime_em(arvore->esq);
		printf("%d ",arvore->info);
		Tarvbusca_imprime_em(arvore->dir);
	}
}
void Tarvbusca_imprime_pos(Tno arvore){
	if(arvore!=NULL){
		Tarvbusca_imprime_pos(arvore->esq);
		Tarvbusca_imprime_pos(arvore->dir);
		printf("%d ",arvore->info);
	}
}