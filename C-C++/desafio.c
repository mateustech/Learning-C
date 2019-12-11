#include <stdio.h>
#include <stdlib.h>
struct aluno
{
	char nome[20];
	int matricula;
	float notas[3];
};
typedef struct aluno Aluno;
//struct de aluno
void lerEstrutura(Aluno *alunos,int tam,FILE *arq);
int verificaMat(int matricula, Aluno * alunos, int qtd);
void editarAluno(int p, Aluno * alunos);
void escreverArquivo(FILE * arq,int qtd, Aluno * alunos);

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
	
	//Matricula a ser buscada
	int matricula;
	printf("Informe a matricula: ");
	scanf("%d",&matricula);
	
	//editando aluno
	int p = verificaMat(matricula,alunos,qtd);
	if(p!=-1){
		editarAluno(p,alunos);
		//escrevendo arquivo
		escreverArquivo(arq,qtd,alunos);	
	}else{
		printf("Matricula nao encontrada!\n");
	}
	
	
	
	
	
	
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
	fclose(arq);
}

int verificaMat(int matricula, Aluno * alunos, int qtd){
	int i;
	for(i = 0; i < qtd; i++)
	{
		if(matricula == alunos[i].matricula){
			return i;
		}
	}
	return -1;
}

void editarAluno(int p, Aluno * alunos){
	printf("Nome: ");
	scanf("%s",alunos[p].nome);
	printf("Matricula: ");
	scanf("%d",&alunos[p].matricula);
	for(int i = 0; i < 3; i++)
	{
		printf("Nota %d: ",i+1);
		scanf("%f",&alunos[p].notas[i]);	
	}
}

void escreverArquivo(FILE * arq,int qtd, Aluno * alunos){
	int i,j;
	arq=fopen("desafio.txt","w");
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
	fclose(arq);
}
