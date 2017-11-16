#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void main()
{
	int c=0;
	while(1)
	{
	pid_t p=fork();
	int s,pid;
	if(p==-1)
	{
		printf("Process creation failed.\n");
		break;
	}
	else if(p==0)
	{
		
		c++;
	}
	else
	{
		printf("Parent process being executed....\n");
	}
	}
	printf("The number of child processes created are: %d \n ",c);
}	
