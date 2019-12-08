#include <stdio.h>

int main(){
	int vet[5], cont=0;
	int i;
	for( i = 0; i < 5; i++)
	{
		scanf("%d",&vet[i]);
	}
	
	for( i = 0; i < 5; i++){
		if(vet[i] < vet[i+1]){
			cont ++;
		}
	}
	if(cont == 4 ){
		printf("C\n");
	}
	else if(cont == 0){
		printf("D\n");
	}
	else{
		printf("N\n");
	}
}