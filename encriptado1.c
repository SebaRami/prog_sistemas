
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encriptadociclico(int c, char *p){
	
	char encriptado[1024]= {0};
	char abecedario[60]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int tamanioAbc, tamanioP, i, j, validacion;
	tamanioAbc = strlen(abecedario);
	tamanioP = strlen(p);
	for (i = 0; i < tamanioP; i++){		
		validacion = 0;
		for (j = 0; j < tamanioAbc; j++){
			if(p[i] == abecedario[j]){
				if(j > 25- c && j < 26 || j > 51-c){
					encriptado[i] = abecedario[j+c-26];
				}
				else{
					encriptado[i] = abecedario[j+c];
				}
				validacion = 1;
			}
		}
		if (validacion == 0){encriptado[i] = p[i];}
	}
	printf(encriptado);
	encriptadomorse("krod shgur");
}

void encriptadomorse(char p){
	char encriptado[1024] = {0};
	int tamanio, i, j, validacion;
	char vowels[][37] = {
	    {'a', 'b', 'c', 'd', 'e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ',0,1,2,3,4,5,6,7,8,9},
	    {'A', 'B', 'C', 'D', 'E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' ',0,1,2,3,4,5,6,7,8,9},
	};
char morse[60] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","/",".----","..---","...--","....-","-....","--...","---..","----.","-----"};

	tamanio = strlen(p);
	for (i = 0; i < tamanio; i++){
		validacion = 0;
		for(j = 0; j < 37; j++){
			if(p[i] == vowels[0][j] || p[i] == vowels[1][j]){
				encriptado[i] = morse[j];
				validacion = 1;
			}
		}
		if (validacion == 0){encriptado[i] = p[i];}
	}
	printf(encriptado);
}

int main(int argc, char *argv[]){
	char palabra[1024]={0};
	int codigo;
	if(argc == 3){
		codigo = atoi(argv[1]);
		encriptadociclico(codigo,argv[2]);
	}
	else{
		printf("Ingrese el mensaje a codificar: ");
		gets(palabra);
		printf("Ingrese el codigo numerico: ");
		scanf("%d", &codigo);
		encriptadociclico(codigo, palabra);
	}
	return 0;
}
