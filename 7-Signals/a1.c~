#include<stdio.h>
#include<stdlib.h>
#include<signal.h>


pid_t p;
void handler(int sig)
{
	printf("The process has now received Ctrl+C hardware interrupt from the user \n");
	p=fork();
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

int main()
{
	int i=1;
	void handler(int sig);
	printf("process started \n");	

	int x=(int)*signal(SIGINT,handler);
	
	while(1);


	return 0;	
			
}
