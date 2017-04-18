#include <stdio.h>	
#include <fcntl.h>	


#include <unistd.h>	


#include <stdlib.h>

int main(int argc, const char * argv[])
{
	
int fp;
	
	
fp = open("exemplo.bin", O_RDWR);
	
if(fp==-1)
	
{
		
 printf("Erro na abertura do arquivo.\n");

 exit(-1);	
}

close(fp);

	
return 0;

}