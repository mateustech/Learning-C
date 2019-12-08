#include <stdio.h>

void lervetor(char v[], int tam);
void insertSort(char v[],int tam);
void MostrarVetor(char v[],int tam);
int main(){
	char v[10];
	printf("============= Vetor Desordenado =============\n");
	lervetor(v,10);
	insertSort(v,10);
	printf("============= Vetor    ordenado =============\n");
	MostrarVetor(v,10);
}
void lervetor(char v[], int tam){
	int i;
	for(i = 0; i < tam; i++){
		scanf(" %c",&v[i]);
	}
}

void MostrarVetor(char v[], int tam){
	int i;
	for(i = 0; i < tam; i++){
		printf("%c ",v[i]);
	}
}

void insertSort(char v[], int tam){
	int i, j , menor;
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