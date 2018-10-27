/*ALGORITMO MERGESORT*/
void Concatena(int *vetor,int inicio1,int inicio2,int fim2){
	int j=inicio1,i1=inicio1,i2=inicio2,chave1,chave2;
	chave1=vetor[i1];
	chave2=vetor[i2];
	while((i1!=inicio2)&&(i2!=fim2+1){
		if(i1==inicio2){//nao ha mais elementos do trecho do vetor a esquerda a serem inseridos no vetor ordenado
			vetor[j]=vetor[i2];
			j++;	i2++;
		}
		else if(i2==fim2+1){//nao ah mais elementos do trecho do vetor a direita a serem inseridos no vetor ordenado
			vetor[j]=vetor[i1];
			j++;	i1++;
		}
		else if(chave1<=chave2){
			vetor[j]=chave1;
			j++;	i1++;
			chave1=vetor[i1];
		}
		else if(chave2<chave1){
			vetor[j]=chave2;
			j++;	i2++;
			chave2=vetor[i2];
		}
	}
}
void ord_Mergesort(int *vetor,int inicio,int fim){
	int aux;
	if(inicio==fim)
		return;
	else{
		aux=fim-inicio+1-(fim-inicio+1)/2;
		ord_Mergesort(vetor,inicio,aux);
		ord_Mergesort(vetor,aux+inicio,(fim-inicio+1)/2-1);
		Concatena(vetor,inicio,aux+inicio,(fim-inicio+1)-1);
	}
}
/*FIM DO ALGORITMO MERGESORT*/