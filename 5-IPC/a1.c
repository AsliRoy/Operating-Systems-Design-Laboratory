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
	
	if(pipe(fd)==2)
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
		close(fd[0]);
		char str[]="I am proud to be your child";
		write(fd[1],str,strlen(str));
		close(fd[1]);
	}
	else
	{
		char s[100];
		close(fd[1]);
		int num=read(fd[0],s,100);
		s[num]='\0';
		printf("the string that the parent receives from the pipe : %s \n",s);

		close(fd[0]);

		
	}


}

