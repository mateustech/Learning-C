#include <stdio.h>

int main(){
	int i=0, vet[5];
	FILE * fp = fopen("binario1.bin","rb");
	fread(vet,sizeof(int),5,fp);
	while(i<5){
		printf("%d \n",vet[i]);
		i++;
	}
}