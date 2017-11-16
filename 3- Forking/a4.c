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
		pid=wait(&s);
		execl("/bin/ls","ls","-l",(char*)0);
		printf("Zombie parent process being executed....\n");
		
	}
}	
