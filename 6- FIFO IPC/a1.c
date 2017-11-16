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
	int fd=open(mypipe, O_RDWR);
	pid_t pid=fork();
	
	if(pid<0)
	{
		printf("error in creating fork.\n");
		exit(1);
	}
	else if(pid==0)
	{	
		char str[]="I am proud to be your child.";
		write(fd,str,strlen(str));
		close(fd);
	}
	else
	{
		sleep(2);
		char s[100];	
		int num=read(fd,s,100);
		s[num]='\0';
		printf("the string that the parent receives from the pipe : %s \n",s);

		close(fd);

		
	}


}

