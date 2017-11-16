#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>

void main()
{       
        int buf[40]; 
	int fd= open("a.txt", O_WRONLY);
	int fd1=open("b1.txt", O_CREAT | O_WRONLY);
	read(fd, buf, 40);
	printf("%s", buf);
	pid_t p=fork();
	int s,pid;
	if(p==-1)
	{
		printf("Process creation failed.\n");
	}
	else if(p==0)
	{
		
		printf("Child process being executed.....\n");
		write(fd1,buf,40);
	}
	else
	{
		
		printf("Parent process being executed....\n");
		//write(fd1,buf,40);
	}
close(fd);
close(fd1);
}	
