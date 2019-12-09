#include <stdio.h>
#include <stdlib.h>

int main(){
	int i=0, vet[10];
	for(i = 0; i < 10; i++){
		vet[i] = rand() % 100;
	}
		
	FILE * fp = fopen("binario3.bin","w+b");
	fwrite(vet,sizeof(int),10,fp);
	fclose(fp);
	puts("Gravados com Sucesso\n");
	
	FILE * fp1 = fopen("binario3.bin","rb");
	int vet1[10],j=0;
	fread(vet1,sizeof(int),10,fp1);
	
	while(j<10){
		printf("%d \n",vet1[j]);
		j++;
	}
}