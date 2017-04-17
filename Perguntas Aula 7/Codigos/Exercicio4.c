#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>


int main()
{
    pid_t pid_filho;
    int fd[2];
    char nome[50];
    char nome2[50];
    
    pipe(fd);
    pid_filho = fork();

    // Codigo do filho    
    if(pid_filho == 0)
    {
        
        printf("Digite seu nome: ");
        scanf("%s",nome);

        if(write(fd[1],nome,sizeof(nome))<0)
        {
            printf("Erro na escrita\n");
        }
    }
    
    // Codigo do pai
    else
    {
        if(read(fd[0],nome2,50)<0)
        {
            printf("Erro na leitura\n");
        }
        else
        {
            printf("O nome difitado foi: %s\n",nome2);
        }
    }
    return 0;
}