/*ORDENACAO EM HEAP*/
void Troca(int *vetor,int i,int i2){
	int aux;
	aux=vetor[i2];
	vetor[i2]=vetor[i];
	vetor[i]=aux;
}
int heap(int *vetor,int i_pai,int n){
    /*FUNCAO QUE VERIFICA SE A CONDICAO DE HEAP ESTA ESTABELICIDA PARA UM DETERMINADO INDICE DE UM VETOR*/
    if(2*(i_pai+1)<n){//tem dois filhos
        if(vetor[i_pai]<=vetor[2*(i_pai+1)-1])//filho a esquerda
            return 0;
        if(vetor[i_pai]<=vetor[2*(i_pai+1)])//filho a direita
            return 0;
    }
    else if(2*(i_pai+1)-1<n){//so tem um filho
        if(vetor[i_pai]<=vetor[2*(i_pai+1)-1])//filho a esquerda
            return 0;
    }
    return 1;
}
void Refaz(int *vetor,int inicio,int n){
	int i=inicio;
	while((heap(vetor,i,n)==0)){
		//LOOP QUE REESTABELECE A CONDICAO DE HEAP SE ESSA CONDICAO ESTA SENDO VIOLADA
		if((2*(i+1)<n)&&(vetor[2*(i+1)-1]>vetor[2*(i+1)])){//se tem dois filhos e o filhos e o filho a esquerda eh maior
			Troca(vetor,i,2*(i+1)-1);
			i=2*(i+1)-1;
		}
		else if((2*(i+1)<n)&&(vetor[2*(i+1)-1]<=vetor[2*(i+1)])){//se tem dois filhos e o filho a direita eh maior
			Troca(vetor,i,2*(i+1));
			i=2*(i+1);
		}
		else{//se tem um filho e o filho eh maior
			Troca(vetor,i,2*(i+1)-1);
			i=2*(i+1)-1;
		}
	}
}
void Constroi(int *vetor,int n){
	/*FUNCAO QUE CONSTROI UMA ARVORE NA CONDICAO DE HEAP MANTENDO O "TETO DE N/2" COMO OS NOHs FOLHAS E SUBINDO NA ARVORE PARA ESTABELECER A CONDICAO DE HEAP*/
	int i;
	for(i=n/2-1;i>=0;i--){
		if(heap(vetor,i,n)==0){
			Refaz(vetor,i,n);
		}
	}
}
void ord_Heapsort(int *vetor,int n){
	int restante;
	Constroi(vetor,n);
	restante=n;
	while(restante>1){
		Troca(vetor,0,restante-1);
		Refaz(vetor,0,restante-1);
		restante--;
	}
}
/*FIM DA ORDENACAO EM HEAP*/