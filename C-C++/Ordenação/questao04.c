#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario F;
struct funcionario
{
	char nome[81];
	float valor_hora;
	int horas_mes;
	float salario;
};

void lerArquivo(FILE  *arq, F * func, int tam);
void insertion(F * func , int tam);
void ImprimirStruct(F * func , int tam);

int main(){
	FILE * arq = fopen("funcionarios.txt","r");
	F * func = (F*) malloc(5 * sizeof(F));
	lerArquivo(arq,func,5);
	fclose(arq);
	insertion(func,5);
	ImprimirStruct(func,3);
}


void lerArquivo(FILE  *arq, F * func, int tam){
	int i;
	for(i = 0; i < tam; i++)
	{
		fscanf(arq,"%s ",func[i].nome);
		fscanf(arq," %f",&func[i].valor_hora);
		fscanf(arq," %d",&func[i].horas_mes);
		func[i].salario = func[i].valor_hora * func[i].horas_mes;
	}
}
void insertion(F * func , int tam){
	int i, j;
	F menor;
	for(i = 0; i < tam; i++){
		menor = func[i];
		j = i - 1;
		while(j>=0 && func[j].salario < menor.salario)
		{
			func[j+1] = func[j];
			j--;
		}
		func[j+1] = menor;
	}
}

void ImprimirStruct(F * func, int tam){
	int i;
	for(i = 0; i < tam; i++)
	{
		printf("Funcionario: %s\n",func[i].nome);
		printf("Valor ganho: %.2f\n",func[i].salario);
		printf("===========================\n");
	}
}

