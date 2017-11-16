#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void main()
{
	int i,n,c=1;
	printf("Enter the number of fork system calls to be given:\n");
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
	pid_t p=fork();
	int s,pid;
	if(p==-1)
	{
		printf("Process creation failed.\n");
		
	}
	else if(p==0)
	{

		printf("Child process being executed....\n");
		printf("Current iD:%d\n",getpid());
		
	}
	else
	{	
			
	}
	c=2*c;
	}
printf("%d",c);
	
}	
