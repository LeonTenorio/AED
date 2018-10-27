/*TAD Arvore AVL*/

typedef struct Sno *Tno;
typedef struct Sno{
	tipoitem info;
	Tno esq,dir;
	int fb;
}TarvAVL;

Tno TarvAVL_inicia(tipoitem x){
	Tno retorna;
	retorna=(Tno)malloc(sizeof(TarvAVL));
	if(retorna==NULL)
		exit (-1);
	retorna->info=x;
	retorna->fb=0;
	retorna->esq=NULL;
	retorna->dir=NULL;
	return retorna;
}
int TarvAVL_orienta(Tno arvore,tipoitem x){
	if(arvore!=NULL){
		if(x==arvore->info)
			return 0;
		else if(x<arvore->info)
			return -1;
		else
			return 1;
	}
	return 0;
}
int TarvAVL_altura(Tno arvore){
	int hd,he;
	if(arvore==NULL)
		return (-1);
	he=TarvAVL_altura(arvore->esq);
	hd=TarvAVL_altura(arvore->dir);
	if(he>=hd)
		return (1+he);
	return (1+hd);
}
int TarvAVL_fb(Tno arvore){
    if(arvore==NULL)
        return (-1);
    return (TarvAVL_altura(arvore->esq)-TarvAVL_altura(arvore->dir));
}
Tno TarvAVL_rotaciona(Tno arvore,int lado){
    Tno pA=arvore,pB;
    if(lado==-1){
        pB=arvore->dir;
        pA->dir=pB->esq;
        pB->esq=pA;
    }
    else{
        pB=arvore->esq;
        pA->esq=pB->dir;
        pB->dir=pA;
    }
    return pB;
}
Tno TarvAVL_rotacao_RR(Tno arvore){
    arvore=TarvAVL_rotaciona(arvore,-1);
    arvore->dir->fb=TarvAVL_fb(arvore->dir);
    arvore->fb=TarvAVL_fb(arvore);
    return arvore;
}
Tno TarvAVL_rotacao_LL(Tno arvore){
    arvore=TarvAVL_rotaciona(arvore,1);
    arvore->esq->fb=TarvAVL_fb(arvore->esq);
    arvore->fb=TarvAVL_fb(arvore);
    return arvore;
}
Tno TarvAVL_rotacao_RL(Tno arvore){
    arvore->dir=TarvAVL_rotaciona(arvore->dir,1);
    arvore=TarvAVL_rotaciona(arvore,-1);
    arvore->esq->fb=TarvAVL_fb(arvore->esq);
    arvore->dir->fb=TarvAVL_fb(arvore->dir);
    arvore->fb=TarvAVL_fb(arvore);
    return arvore;
}
Tno TarvAVL_rotacao_LR(Tno arvore){
    arvore->esq=TarvAVL_rotaciona(arvore->esq,-1);
    arvore=TarvAVL_rotaciona(arvore,1);
    arvore->esq->fb=TarvAVL_fb(arvore->esq);
    arvore->dir->fb=TarvAVL_fb(arvore->dir);
    arvore->fb=TarvAVL_fb(arvore);
    return arvore;
}
Tno TarvAVL_balanceamento(Tno arvore){
    if(arvore->fb<-1){
        if(arvore->dir->fb<=0)
            arvore=TarvAVL_rotacao_RR(arvore);
        else
            arvore=TarvAVL_rotacao_RL(arvore);
    }
    else if(arvore->fb>1){
        if(arvore->esq->fb>=0)
            arvore=TarvAVL_rotacao_LL(arvore);
        else
            arvore=TarvAVL_rotacao_LR(arvore);
    }
    return arvore;
}
Tno TarvAVL_insere(Tno arvore,tipoitem x){
    if(arvore==NULL){
        arvore=TarvAVL_inicia(x);
        return arvore;
    }
    else if(TarvAVL_orienta(arvore,x)<0)
        arvore->esq=TarvAVL_insere(arvore->esq,x);
    else if(TarvAVL_orienta(arvore,x)>0)
        arvore->dir=TarvAVL_insere(arvore->dir,x);
    else
        return arvore;
    arvore->fb=TarvAVL_fb(arvore);
    if(arvore->fb>1||arvore->fb<-1)
        arvore=TarvAVL_balanceamento(arvore);
    return arvore;
}
Tno TarvAVL_retira_maior(Tno arvore,Tno *substituto){
    if(arvore->dir!=NULL){
        arvore->dir=TarvAVL_retira_maior(arvore->dir,substituto);
        if(arvore->dir==(*substituto)){
            //Desconectar o substituto da arvore
            arvore->dir=(*substituto)->esq;
            (*substituto)->esq=NULL;
        }
        arvore->fb=TarvAVL_fb(arvore);
        if(arvore->fb<-1||arvore->fb>1)
            arvore=TarvAVL_balanceamento(arvore);
    }
    else{
        *substituto=arvore;
    }
    return arvore;
}
Tno TarvAVL_retira_menor(Tno arvore,Tno *substituto){
    if(arvore->esq!=NULL){
        arvore->esq=TarvAVL_retira_menor(arvore->esq,substituto);
        if(arvore->esq==(*substituto)){
            //Desconectar o substituto da arvore
            arvore->esq=(*substituto)->dir;
            (*substituto)->dir=NULL;
        }
        arvore->fb=TarvAVL_fb(arvore);
        if(arvore->fb<-1||arvore->fb>1)
            arvore=TarvAVL_balanceamento(arvore);
    }
    else{
        *substituto=arvore;
    }
    return arvore;
}
Tno TarvAVL_retira(Tno arvore,tipoitem sai,int *flag){
    int aux;
    Tno substituto=NULL;
    if(arvore==NULL)
        return (NULL);
    if(TarvAVL_orienta(arvore,sai)<0){
        if(arvore->esq!=NULL){
            arvore->esq=TarvAVL_retira(arvore->esq,sai,flag);
            if(*flag==1){//Consegui fazer a troca
                arvore->fb=TarvAVL_fb(arvore);
                if(arvore->fb<-1||arvore->fb>1)
                    arvore=TarvAVL_balanceamento(arvore);
            }
        }
        else//o noh nao existe na arvore
            *flag=-1;
    }
    else if(TarvAVL_orienta(arvore,sai)>0){
        if(arvore->dir!=NULL){
            arvore->dir=TarvAVL_retira(arvore->dir,sai,flag);
            if(*flag==1){
                arvore->fb=TarvAVL_fb(arvore);
                if(arvore->fb<-1||arvore->fb>1)
                    arvore=TarvAVL_balanceamento(arvore);
            }
        }
        else//o noh nao existe na arvore
            *flag=-1;
    }
    else{//esse noh sera retirado da arvore
        if(arvore->dir!=NULL){
            arvore->dir=TarvAVL_retira_menor(arvore->dir,&(substituto));
            if(arvore->dir!=substituto)
                substituto->dir=arvore->dir;
            substituto->esq=arvore->esq;
            substituto->fb=TarvAVL_fb(substituto);
            free(arvore);
            *flag=1;
            substituto->fb=TarvAVL_fb(substituto);
            if(substituto->fb<-1||substituto->fb>1)
                substituto=TarvAVL_balanceamento(substituto);
            return substituto;
        }
        else if(arvore->esq!=NULL){
            arvore->esq=TarvAVL_retira_maior(arvore->esq,&(substituto));
            substituto->dir=arvore->dir;
            if(arvore->esq!=substituto)
                substituto->esq=arvore->esq;
            free(arvore);
            *flag=1;
            substituto->fb=TarvAVL_fb(substituto);
            if(substituto->fb<-1||substituto->fb>1)
                substituto=TarvAVL_balanceamento(substituto);
            return substituto;
        }
        else{
            *flag=1;
            free(arvore);
            return (NULL);
        }
    }
    return arvore;
}
Tno TarvAVL_localiza(Tno arvore,Tno *anterior,tipoitem x){
	//funcao que localiza o noh do item x na arvore e carrega na Tno *anterior o pai desse elemento
	Tno aux=arvore;
	int flag=0;
	while(arvore!=NULL){
		if(aux!=NULL){
			if(TarvAVL_orienta(aux,x)<0){
				*anterior=aux;
				aux=aux->esq;
			}
			else if(TarvAVL_orienta(aux,x)>0){
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
int TarvAVL_verifica(Tno arvore){
    int aux;
    if(arvore!=NULL){
        if(arvore->esq!=NULL)
            if(arvore->esq->info>arvore->info)
                return 0;
        if(arvore->dir!=NULL)
            if(arvore->dir->info<arvore->info)
                return 0;
        aux=arvore->fb;
        if(aux>1||aux<-1)
            return 0;
        aux=TarvAVL_verifica(arvore->esq);
        if(aux>1||aux<-1)
            return 0;
        aux=TarvAVL_verifica(arvore->dir);
        if(aux>1||aux<-1)
            return 0;
    }
    return 1;
}
void TarvAVL_imprime_pre(Tno arvore){
	if(arvore!=NULL){
		printf("%d ",arvore->info);
		TarvAVL_imprime_pre(arvore->esq);
		TarvAVL_imprime_pre(arvore->dir);
	}
}
void TarvAVL_imprime_em(Tno arvore){
	if(arvore!=NULL){
		TarvAVL_imprime_em(arvore->esq);
		printf("%d ",arvore->info);
		TarvAVL_imprime_em(arvore->dir);
	}
}
void TarvAVL_imprime_pos(Tno arvore){
	if(arvore!=NULL){
		TarvAVL_imprime_pos(arvore->esq);
		TarvAVL_imprime_pos(arvore->dir);
		printf("%d ",arvore->info);
	}
}
Tno TarvAVL_libera(Tno arvore){
	if(arvore!=NULL){
		arvore->esq=TarvAVL_libera(arvore->esq);
		arvore->dir=TarvAVL_libera(arvore->dir);
		free(arvore);
	}
	return arvore;
}