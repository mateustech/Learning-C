#include <stdio.h>


void lervetor(int vet[], int tam);

int merge(int vet[],int ini, int fim);
int mistura(int vet[], int ini, int meio, int fim);

int main(){
	int tam;
	scanf("%d",&tam);
	
	while(tam != 0 ){
		   int vet[tam];
		   lervetor(vet, tam);
		   int c = merge(vet,0,tam-1);
		   if(c%2 == 0){
			   printf("Carlos\n");
		   }else{
			   printf("Marcelo\n");
		   }
		   printf("%d\n",c);
		   scanf("%d",&tam);	
	}
	
	
	
}

void lervetor(int vet[], int tam){
	int i;
	for( i = 0; i < tam; i++)
	{
		scanf("%d",&vet[i]);
	}
}


int merge(int vet[],int ini, int fim){  
   	if(fim > ini){
		   int m = (ini + fim ) / 2;
		   int x = merge(vet,ini, m);
		   int y = merge(vet,m+ 1, fim);
		   int z = mistura(vet,ini,m+1,fim);
		   return x + y + z;
	}else{
		return 0;
	}       
            
} 
int mistura(int vet[], int ini, int meio, int fim){
	int i = ini,j= meio,k=0,cont=0;
	int tem[(fim -  ini) + 1];
 	
	while((i < meio)&& (j <= fim)){
		if(vet[i] <= vet[j]){
			tem[k++] = vet[i++];
		}else{
			tem[k++] = vet[j++];
			cont += (meio-i);
			
		}
	}
	while(i < meio)
	{
		tem[k++] = vet[i++];
	}
	while(j <= fim)
	{
		tem[k++] = vet[j++];
	}
	for( i = ini; i <= fim ; i++){
		vet[i] = tem[i - ini];
	}
	return cont;
}