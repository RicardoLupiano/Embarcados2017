#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
	int fp, i;
	char nome[100];
	char idade[100];
	fp = open ("Eu.txt", O_WRONLY | O_CREAT, S_IRWXU);
	if(fp==-1)
	{
		printf ("Erro na abertura do arquivo.\n");
		exit (1);
	}
	write(fp, "Nome: ", 6*sizeof(char)); // Grava a string, caractere a caractere	

	for(i=0; argv[1][i]; i++)	
	 write(fp, &(argv[1][i]), 1); // Grava a string, caractere a caractere	
	write(fp, "\r\n", 2);
	write(fp, "Idade: ", 7*sizeof(char)); // Grava a string, caractere a caractere
	for(i=0; argv[2][i]; i++)	
	write(fp, &(argv[2][i]), 1); // Grava a string, caractere a caractere
	write(fp, " anos", 5);
	close(fp);
	return 0;
}

