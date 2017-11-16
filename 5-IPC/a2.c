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

	int fd1[2],fd2[2];

	if(pipe(fd1)==-1||pipe(fd2)==-1)
	{
		printf("error in pipe creation.\n");
		exit(1);
	}

	pid_t pid=fork();
	
	if(pid<0)
	{
		printf("Error in creating a fork.\n");
		exit(1);
	}
	else if(pid==0)
	{
		sleep(2);
		close(fd1[0]);
		close(fd2[1]);
		char s[100];
		int n=read(fd2[0],s,100);
		s[n]='\0';
		printf("string read from pipe by the child : %s\n",s);
		int i=0;		
		while(s[i]!='\0')
		{s[i]=toupper(s[i]);i++;}
		printf("string sent to pipe by the child : %s\n",s);
		write(fd1[1],s,strlen(s));
		close(fd1[1]);
		close(fd2[0]);		
	}
	else
	{
		close(fd1[1]);
		close(fd2[0]);
		char str[]="this is a string.";
		printf("string sent to pipe by the parent : %s\n",str);
		write(fd2[1],str,strlen(str));
		wait();
		char s[100];
		int n=read(fd1[0],s,100);
		s[n]='\0';
		printf("string read from pipe by the parent : %s\n",s);
	}



}
