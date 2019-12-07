#include <stdio.h>
#include <stdlib.h>
struct aluno
{
	char nome[20];
	int matricula;
	float notas[3];
};
typedef struct aluno Aluno;

void lerEstrutura(Aluno *alunos,int qtd);
void escreverArquivo(FILE * arq,int qtd, Aluno * alunos);

int main(){
	int qtd;
	Aluno * alunos;
	
	printf("Informe a Qtd de Alunos:");
	scanf("%d",&qtd);
	
	alunos = (Aluno*)malloc(qtd * sizeof(Aluno));
	if(!alunos){
		puts("Error");
		exit(1);
	}
	lerEstrutura(alunos,qtd);
	//escrevendo dados no arquivo
	FILE * arq;
	escreverArquivo(arq,qtd,alunos);
	
	
	
}

void lerEstrutura(Aluno *alunos,int qtd){
	int i,j;
	for(i = 0; i < qtd; i++)
	{
		printf("===========================\n");
		printf("         Aluno %d\n",i+1);
		printf("Nome: ");
		scanf("%s",alunos[i].nome);
		printf("Matricula: ");
		scanf("%d",&alunos[i].matricula);
		for(j=0;j<3;j++){
			printf("Nota %d: ",j+1);
			scanf("%f",&alunos[i].notas[j]);
		}
		
	}
	printf("===========================\n");
}

void escreverArquivo(FILE * arq,int qtd, Aluno * alunos){
	int i,j;
	arq=fopen("questao04.txt","w");
	fprintf(arq,"%d\n",qtd);
	for(i = 0; i < qtd; i++)
	{
		fprintf(arq,"%s %d",alunos[i].nome,alunos[i].matricula);
		for(j=0;j<3;j++){
			   fprintf(arq," %.2f",alunos[i].notas[j]);	
		}
		fprintf(arq,"\n");
	}
	printf("Alunos inseridos com Sucesso!\n");
}






