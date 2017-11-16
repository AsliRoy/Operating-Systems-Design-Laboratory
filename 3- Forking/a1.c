#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void main()
{
	pid_t p=fork();
	int s,pid;
	if(p==-1)
	{
		printf("Process creation failed.\n");
	}
	else if(p==0)
	{
		printf("Child process being executed.....\n");
		printf("Child iD:%d\nParent ID:%d\n",getpid(),getppid());
	}
	else
	{
		printf("Current iD:%d\n",getpid());
		printf("Parent process being executed....\n");
	}
}	
