#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>
#include<stdlib.h>

int main()
{
	
	int fd[2];
	
	if(pipe(fd)==2)
	{
		printf("error in pipe creation\n");
		exit(1);
	}
	void handler(int sig);
	
	int pid=fork();
	
	if(pid<0)
	{
		printf("Process creation failed. \n");
	}
	else if(pid>0)
	{
		char s[100];
		printf("Parent process has started executing\n");
		signal(SIGPIPE,handler);
		close(fd[0]);
		int num=read(fd[0],s,100);
		s[num]='\0';
		printf("the string that the parent receives from the pipe : %s \n",s);
		
		while(1);
		printf("Parent process is now completed\n");
	}
	else
	{
		printf("child process has started executing\n");
		
		sleep(2);
		kill(getppid(),SIGPIPE);
		printf("Child process is now completed\n");
	}

	return 0;


}


void handler(int sig)
{
	printf("Parent process has received the kill system call from the child function and has executed the signal handler function\n");
}
