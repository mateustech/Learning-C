#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct retangulo {
	char nome[20];
	float base;
	float altura;
	float area;
};
typedef struct retangulo Ret;

void LerEstrutura(FILE * arq, Ret * ret, int tam);
void EscreverEstrutura(Ret * ret,FILE * arq, int tam);
void insertion(Ret * ret, int tam);

int main(){
	Ret * ret;
	ret = (Ret*) malloc (sizeof(Ret)*5);
	FILE * arq = fopen("retangulos.txt","r");
	if(!arq){
		puts("Error");
		exit(0);
	}
	LerEstrutura(arq,ret,5);
	fclose(arq);
	
	insertion(ret,5);
	
	arq = fopen("retangulosOrdenados.txt","w");
	EscreverEstrutura(ret,arq,5);
	fclose(arq);
}

void LerEstrutura(FILE * arq, Ret * ret, int tam){
	for(int i = 0; i < tam; i++){
		fscanf(arq,"%s",ret[i].nome);
		fscanf(arq," %f",&ret[i].base);
		fscanf(arq," %f",&ret[i].altura);
		ret[i].area = ret[i].base * ret[i].altura;
	}
}
void EscreverEstrutura(Ret * ret,FILE * arq, int tam){
	for(int i = 0; i < tam; i++){
		fprintf(arq,"%s",ret[i].nome);
		fprintf(arq," %.1f",ret[i].base);
		fprintf(arq," %.1f\n",ret[i].altura);
	}
}

void insertion(Ret * ret, int tam){
	int i, j;
	Ret  menor;
	for(i=0;i<tam;i++){
		menor = ret[i];
		j = i - 1;
		while(j>=0 && ret[j].area > menor.area){
			ret[j+1] = ret[j];
			j--;
		}
		
		ret[j+1] = menor;
	}
}










