#include <stdio.h>
#include <stdlib.h>

int main(){
	int  vet[5],i=0;
	
	for( i = 0; i < 5 ; i++){
		scanf("%d",&vet[i]);
	}
	i=0;
	FILE * fp = fopen("binario1.bin","w+b");
	fwrite(vet,sizeof(int),5,fp);
	fclose(fp);
	
	   	
}