/*ORDENACAO QUICKSORT*/
void Troca(int *vetor,int i,int i2){
	int aux;
	aux=vetor[i2];
	vetor[i2]=vetor[i];
	vetor[i]=aux;
}
void Imprime(int *vetor,int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",vetor[i]);
    printf("\n");
}

int Particao(int *vetor,int p,int r){
	int pivo;
	int i=p-1,j=p;
	pivo=vetor[r];
	while(j!=r){
		if((vetor[j]<=pivo)&&(j-1==i)){
			i++;	j++;
		}
		else if((vetor[j]<=pivo)&&(j-1!=i)){
			//deslocar esse vetor[j] para a primeira posicao depois de i
			Troca(vetor,i+1,j);
			i++;	j++;
		}
		else{
			j++;
		}
	}
	//agora depois da posicao "i" até a posicao do pivo sao todos maiores que o pivo
	if(i+1!=r)
		Troca(vetor,i+1,r);
	return (i+1);
}
void ord_Quicksort(int *vetor,int p,int r,int n){
	int q;
	if(p<r){
		q=Particao(vetor,p,r);
		if(q-1-p>=0)
			ord_Quicksort(vetor,p,q-1,n);
		if(r>=q+1)
			ord_Quicksort(vetor,q+1,r,n);
	}
}
/*FIM DA QUICKSORT*/