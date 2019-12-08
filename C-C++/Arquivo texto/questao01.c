#include <stdio.h>

void lervetor(float vet[], int tam);
void escreverArquivo(float vet[], FILE * arq,int tam);

int main(){
	float vet[10];
	lervetor(vet,10);
	FILE *arq;
	escreverArquivo(vet,arq,10);
}

void lervetor(float vet[], int tam){
	int i;
	for(i = 0; i < tam; i++)
	{
		printf("Valor %d:",i+1);
		scanf("%f",&vet[i]);
	}
}

void escreverArquivo(float vet[], FILE * arq,int tam){
	int i;
	arq = fopen("questao01.txt","w");
	for(i = 0; i < tam; i++)
	{
		fprintf(arq,"%.2f\n",vet[i]);
	}
	printf("Arquivo Copiado Com Sucesso...\n");
	fclose(arq);
}