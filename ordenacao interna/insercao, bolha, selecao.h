/*ALGORITMOS DE ORDENACAO INTERNA*/
void Troca(int *vetor,int i,int i2){
	int aux;
	aux=vetor[i2];
	vetor[i2]=vetor[i];
	vetor[i]=aux;
}
void ord_Select(int *vetor,int n){
	int i,i2,menor;
	for(i=0;i<n-1;i++){
		menor=i;
		for(i2=i+1;i2<n;i2++)
			if(vetor[i2]<vetor[menor])
				menor=i2;
		if(menor!=i)
			Troca(vetor,i,menor);
	}
}
void ord_Bolha(int *vetor,int n){
	int i,i2,cont;
	for(i=0;i<n-1;i++){
		cont=0;
		for(i2=0;i2<n-i-1;i2++){
			if(vetor[i2]>vetor[i2+1]){
				Troca(vetor,i2,i2+1);
				cont++;
			}
		}
		if(cont==0)
			return;
	}
}
void ord_Insert(int *vetor,int n){
	int i,i2,chave,cont;
	for(i=1;i<n;i++){
		chave=vetor[i];
		for(i2=i-1;i2>=0;i2--){
			if(chave<vetor[i2])
				vetor[i2+1]=vetor[i2];
			else
				vetor[i2+1]=chave;
		}
	}
}