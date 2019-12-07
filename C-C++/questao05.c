#include <stdio.h>
#include <stdlib.h>
struct aluno
{
	char nome[20];
	int matricula;
	float notas[3];
};
typedef struct aluno Aluno;

void lerEstrutura(Aluno *alunos,int tam,FILE *arq);
void MostrarMedia(int tam, Aluno * alunos);

int main(){
	int qtd=4;
	Aluno * alunos;	
	alunos = (Aluno*)malloc(qtd * sizeof(Aluno));
	if(!alunos){
		puts("Error");
		exit(1);
	}
	//lendo estrutura atravez do arquivo
	FILE * arq;
	arq = fopen("questao04.txt","r");
	lerEstrutura(alunos,qtd,arq);
	
	//Mostrando Media
	MostrarMedia(qtd,alunos);
	
	
	
}
void lerEstrutura(Aluno *alunos,int tam,FILE *arq){
	int i,j;
	for(i = 0; i < tam; i++)
	{
		fscanf(arq,"%s",alunos[i].nome);
		fscanf(arq,"%d",&alunos[i].matricula);
		for(j=0;j<3;j++){
			fscanf(arq,"%f",&alunos[i].notas[j]);
		}
		
	}
}
void MostrarMedia(int tam,Aluno * alunos){
	int i,j,contsucesso=0;
	float media=0;
	for(i = 0; i < tam; i++)
	{
		printf("===========================\n");
		printf("         Aluno %d\n",i+1);
		printf("Nome: %s\n",alunos[i].nome);
		printf("Matricula: %d\n",alunos[i].matricula);
		for(j=0;j<3;j++){
			media+=alunos[i].notas[j];
		}
		printf("Media: %.2f\n",media/3);
		if(media/3>=7.0){
			contsucesso++;
		}
		media=0;
	}
	
	printf("===========================\n");
	printf("%d Alunos obtiveram Sucesso!\n",contsucesso);
}
