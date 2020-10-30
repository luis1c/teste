/*  Ler um arquivo "entrada.txt" e gerar dois outros arquivos, 
um criptografado com a cífra de César "saida_cript.txt" e outro 
descriptografado "saida_descript.txt"  */

#include <stdio.h> //biblioteca
#include <stdlib.h> //biblioteca

void Cript(char s[]);
void Descript(char s[]);

int main(){
    char frases[999];
    FILE * file;
    file = fopen("entrada.txt","rt");
    if(file == NULL)
        exit(0);
    for(int i = 0; frases[i] != '\0' ; i++)
        fscanf(file, "%[^\n]", &frases[i]);
    Cript(frases); //funcao encriptar
    Descript(frases);
    fclose(file);

    return 0;
}

void Descript(char s[]){ 
    FILE * file;

 	for(int i = 0; s[i] != '\0'; i++){
		if( (s[i] >= 97) && (s[i] <= 99))
			s[i] += 23;
		else if( (s[i] >= 100) && (s[i] <= 122))
			s[i] -= 3;
	}
    file = fopen("saida_descript.txt","wt");
    if(file == NULL)
        exit(-1);
    for(int i = 0; s[i] != '\0' ; i++)
        fprintf(file, "%c", s[i]);

    fclose(file);
}

void Cript(char s[]){
    FILE * file;

	for(int i = 0; s[i] != '\0'; i++){
		if( (s[i] >= 65) && (s[i] <= 90))
			s[i] += 32;
	}

 	for(int i = 0; s[i] != '\0'; i++){
		if( (s[i] > 119) && (s[i] <= 122))
			s[i] -= 23;
		else if( (s[i] >= 97) && (s[i] <= 119))
			s[i] += 3;
	}

    file = fopen("saida_cript.txt","wt");
    if(file == NULL)
        exit(-1);
    for(int i = 0; s[i] != '\0' ; i++)
        fprintf(file, "%c", s[i]);

    fclose(file);
}
