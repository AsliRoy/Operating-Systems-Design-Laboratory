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
		printf("Error in creating a fork.\n");
		exit(1);
	}
	else if(pid==0)
	{
		sleep(2);
		char s[100];
		int n=read(fd,s,100);
		s[n]='\0';
		printf("string read from pipe by the child : %s\n",s);
		int i=0;		
		while(s[i]!='\0')
		{s[i]=toupper(s[i]);i++;}
		printf("string sent to pipe by the child : %s\n",s);
		write(fd,s,strlen(s));
		close(fd);		
	}
	else
	{
		
		char str[]="this is a string.";
		printf("string sent to pipe by the parent : %s\n",str);
		write(fd,str,strlen(str));
		wait();
		char s[100];
		int n=read(fd,s,100);
		s[n]='\0';
		printf("string read from pipe by the parent : %s\n",s);
		close(fd);
	}



}
