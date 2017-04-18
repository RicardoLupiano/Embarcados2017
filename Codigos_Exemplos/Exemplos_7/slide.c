#include <signal.h>
#include <unistd.h>
#include <stdio.h>
void int_trata_alarme(int sig) { /* rotina executada na recepcao
de SIGALRM */
 printf("recepcaao do sinal %d :SIGALRM\n",sig);
}
int main() {
 unsigned sec;
 signal(SIGALRM,int_trata_alarme); /* interceptacao do sinal */
 printf("Fazendo alarm(5)\n");
 //printf("Valor retornado por alarm: %d\n",sec) ;
 printf("Principal em loop infinito (CTRL+c para acabar)\n") ;
 while(1) {
 alarm(1);
 sleep(2);
 }
}