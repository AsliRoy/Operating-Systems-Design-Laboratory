#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

void main()
	{
	int ch;
	printf(".....MENU-DRIVEN PROGRAM TO DISPLAY FAMILY OF EXEC SYSTEM CALLS.....\n");
	printf("1-EXEC VP \n");
	printf("2-EXEC L \n");
	printf("3-EXEC V \n");
	printf("Enter your choice:\n");
	scanf("%d", &ch);
	if(ch==1)
	{
	char *args[]={"./SAMPLE",NULL};
	execvp(args[0],args);
	printf("The program that should actually be implemented...\n");
	}
	if(ch==2)
	{
	printf("Before Exec()");
	execl("/bin/ls","ls","-l",(char*)0);
	printf("After");
	}
	if(ch==3)
	{
	char *args[]={"./SAMPLE",NULL};
	execv(args[0],args);
	printf("The program that should actually be implemented...\n");
	}
	}
