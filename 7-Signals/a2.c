#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>
#include<stdlib.h>

int main()
{

	void handler(int sig);
	signal(SIGINT,handler);
		
	int pid=fork();
	
	if(pid<0)
	{
		printf("Process creation failed. \n");
	}
	else if(pid==0)
	{
		printf("Child process has started executing\n");
		while(1);
		printf("Child process has completed executing\n");
	}
	else
	{
		printf("Parent process has started executing\n");
		
		sleep(2);
		kill(pid,SIGINT);
		wait(NULL);
		printf("Parent process has completed executing\n");
	}

	return 0;


}


void handler(int sig)
{
	printf("Child process has received the kill system call from the parent function and has executed the signal handler function \n");
}
