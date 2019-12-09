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
	for(i = 0; i < n; i++){
		   printf("\n\nAluno %d\n",i+1);
		   printf("Informe o seu nome: ");
		   scanf("%s",A[i].nome);	   	
		   printf("Informe a Matricula: ");
		   scanf("%d",&A[i].mat);
		   for(j = 0; j < 3; j++){
				printf("Nota %d: ",j+1);
				scanf("%f",&A[i].notas[j]);	   
		   }
	}
}

void EscreverEstrutura(Aluno A[],int n){
	FILE * arq = fopen("binario5.bin","w+b");
	fwrite(A,sizeof(Aluno),n,arq);
	fclose(arq);
}
















