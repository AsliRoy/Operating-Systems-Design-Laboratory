#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>


int main()
{
	int fd[2];
	
	if(pipe(fd)==-1)
	{
		printf("error in pipe creation\n");
		exit(1);
	}

	pid_t pid=fork();
	
	if(pid<0)
	{
		printf("error in creating fork.\n");
		exit(1);
	}
	else if(pid==0)
	{
		dup2(fd[0],0);
		char s[1000];
		read(0,s,1000);
		int num=wc -l '0';
		printf("%d\n",num);
		
		close(fd[0]);
	}
	else
	{
		dup2(fd[1],1);
		close(fd[0]);
		write(1, system("ls"),100);
	
		close (fd[1]);		

	}

}
