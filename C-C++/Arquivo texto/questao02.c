#include <stdio.h>

void preencheVetor(float vet[], int tam);
void lerArquivo(float vet[], FILE * arq,int tam);

int main(){
	FILE *arq;
	float vet[10];
	
	lerArquivo(vet,arq,10);
	preencheVetor(vet,10);
	
	
}

void preencheVetor(float vet[], int tam){
	int i;
	for(i = 0; i < tam; i++)
	{
		printf("Valor: %.2f \n",vet[i]);
	}
}

void lerArquivo(float vet[], FILE * arq,int tam){
	int i;
	arq = fopen("questao01.txt","r");
	for(i = 0; i < tam; i++)
	{
		fscanf(arq,"%f\n",&vet[i]);
	}
	printf("Leitura Realizada Com Sucesso...\n");
	fclose(arq);
}