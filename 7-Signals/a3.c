#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>
#include<stdlib.h>

int main()
{

	void handler(int sig);
	
	int pid=fork();
	
	if(pid<0)
	{
		printf("Process creation failed. \n");
	}
	else if(pid>0)
	{
		printf("Parent process has started executing\n");
		signal(SIGINT,handler);
		while(1);
		printf("Parent process is now completed\n");
	}
	else
	{
		printf("child process has started executing\n");
		
		sleep(2);
		kill(getppid(),SIGINT);
		printf("Child process is now completed\n");
	}

	return 0;


}


void handler(int sig)
{
	printf("Parent process has received the kill system call from the child function and has executed the signal handler function\n");
}
