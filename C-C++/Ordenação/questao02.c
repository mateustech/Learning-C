#include <stdio.h>

void lervetor(float v[], int tam);
void insertSort(float v[],int tam);
void escreverVetor(float v[],int tam);

int main(){
	float v[8];
	printf("============= Lendo Arquivo =============\n");
	lervetor(v,8);
	insertSort(v,8);
	printf("============= Vetor    ordenado =============\n");
	escreverVetor(v,8);
}
void lervetor(float v[], int tam){
	int i;
	FILE * arq = fopen("q02.txt","r");
	for(i = 0; i < tam; i++){
		fscanf(arq, "%f",&v[i]);
	}
	fclose(arq);
}

void escreverVetor(float v[], int tam){
	int i;
	FILE * arq = fopen("q02.txt","w");
	for(i = 0; i < tam; i++){
		fprintf(arq,"%.1f\n",v[i]);
	}
	fclose(arq);
}

void insertSort(float v[], int tam){
	int i, j ;
	float menor;
	for(i = 0; i < tam; i++){
		menor = v[i];
		j=i-1;
		while(j>=0 && v[j]> menor){
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = menor;
	}
}