#include <stdio.h>

struct aluno{
	char nome[20];
	int mat;
	float notas[3];
};
typedef struct aluno Aluno;

void LerEstrutura(Aluno A[], int n);
void EscreverEstrutura(Aluno A[],int n);

int main(){
	int n;
	printf("Informe a Quantidade de Alunos: ");
	scanf("%d",&n);
	Aluno A[n];
	LerEstrutura(A,n);   	
	EscreverEstrutura(A,n);
	
	
}

void LerEstrutura(Aluno A[], int n){
	int i,j;
	FILE * arq = fopen("binario5.bin","rb");
	fread(A,sizeof(Aluno),n,arq);
	
	fclose(arq);
}

void EscreverEstrutura(Aluno A[],int n){
	int i,j;
	for(i = 0; i < n; i++){
		   printf("\n\nAluno %d\n",i+1);
		   printf("Nome: %s\n",A[i].nome);  	
		   printf("Matricula: %d\n",A[i].mat);
		   printf("Notas:");
		   for(j = 0; j < 3; j++){
				printf(" %.0f",A[i].notas[j]);
		   }
	}
}
















