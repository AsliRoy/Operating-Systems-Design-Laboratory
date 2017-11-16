#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
void main()
{
	char str[20];
	strcpy(str,"ps -l");
	system(str);
}
  
