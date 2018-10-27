#include <stdio.h>
#include <stdlib.h>
 
typedef struct{
    int **matriz;
    int tam;
}Tadjacencia;
 
void Tadjacencia_inicia(Tadjacencia *adjacencia,int n){
    int i,j;
    //Alocacao da matriz;
    adjacencia->matriz=(tipoitem**)malloc(n*sizeof(tipoitem*));
    for(i=0;i<n;i++){
        adjacencia->matriz[i]=(tipoitem*)malloc(n*sizeof(tipoitem));
        for(j=0;j<n;j++)
            adjacencia->matriz[i][j]=0;
    }
    adjacencia->tam=0;
}
void Tadjacencia_insere(Tadjacencia *adjacencia,int i,int j){
    if(i!=j){
        adjacencia->matriz[i][j]++;
        adjacencia->matriz[j][i]++;
    }
    else
        adjacencia->matriz[i][j]++;
    adjacencia->tam++;
}
void Tadjacencia_retira(Tadjacencia *adjacencia,int i,int j){
    if(i!=j){
        adjacencia->matriz[i][j]--;
        adjacencia->matriz[j][i]--;
    }
    else
        adjacencia->matriz[i][j]--;
    adjacencia->tam--;
}
void Tadjacencia_libera(Tadjacencia *adjacencia,int n){
	int i;
	for(i=n-;i>=0;i--)
		free(adjacencia->matriz[i]);
	free(adjacencia->matriz);
	adjacencia->tam=0;
}