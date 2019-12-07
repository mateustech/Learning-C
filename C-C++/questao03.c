#include <stdio.h>

void verificarNum(int vet[], int tam, int num);
void lerArquivo(int vet[], FILE * arq,int tam);

int main(){
	FILE *arq;
	int vet[10];
	
	lerArquivo(vet,arq,10);
	
	int num;
	printf("Informe o valor a ser buscado:");
	scanf("%d",&num);
	verificarNum(vet,10,num);
	
	
}

void verificarNum(int vet[], int tam,int num){
	int i,cont=0;
	for(i = 0; i < tam; i++)
	{
		if(vet[i]==num){
			printf("O numero %d esta presente na linha %d\n",num,i+1);
			cont ++;
		}
	}
	if(cont==0){
		printf("O numero nao esta presente!");
	}
}

void lerArquivo(int vet[], FILE * arq,int tam){
	int i;
	arq = fopen("arquivo.txt","r");
	for(i = 0; i < tam; i++)
	{
		fscanf(arq,"%d\n",&vet[i]);
	}
	printf("Leitura Realizada Com Sucesso...\n");
	fclose(arq);
}