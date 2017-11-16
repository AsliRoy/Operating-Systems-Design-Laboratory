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
	char *mypipe= "/tmp/mypipe";
	mkfifo(mypipe, 0666);

	pid_t pid=fork();
	
	if(pid<0)
	{
		printf("error in creating fork.\n");
		exit(1);
	}
	else if(pid==0)
	{
		//sleep(2);
		int fd = open(mypipe, O_RDONLY);
		dup2(fd,0);
		execlp("wc","wc","-l",(char*)0);
		close(0);
	}
	else
	{
		int fd = open(mypipe, O_WRONLY);	
		dup2(fd,1);		
		execlp("ls","ls",(char *)0);
		close(1);

	}

}
