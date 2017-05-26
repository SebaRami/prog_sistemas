
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encriptadociclico(){
	char palabra[1024]={0}, encriptado[1024]= {0};
	char abecedario[60]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int tamanioAbc, codigo, tamanioP, i, j, validacion;
	tamanioAbc = strlen(abecedario);
	printf("Ingrese el mensaje a codificar: ");
	gets(palabra);
	printf("Ingrese el codigo numerico: ");
	scanf("%d", &codigo);
	tamanioP = strlen(palabra);
	for (i = 0; i < tamanioP; i++){		
		validacion = 0;
		for (j = 0; j < tamanioAbc; j++){
			if(palabra[i] == abecedario[j]){
				if(j > 25- codigo && j < 26 || j > 51-codigo){
					encriptado[i] = abecedario[j+codigo-26];
				}
				else{
					encriptado[i] = abecedario[j+codigo];
				}
				validacion = 1;
			}
		}
		if (validacion == 0){encriptado[i] = palabra[i];}
	}
	printf(encriptado);
}

int main(void){
	encriptadociclico();
}
