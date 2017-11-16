#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void main()
{
	pid_t p=fork();
	int s,pid;
	if(p==-1)
	{
		printf("Process creation failed.\n");
	}
	else if(p==0)
	{
		pid=wait(&s);
		printf("Child process being executed.....\n");
		printf("Enter the number whose factorial is to be calculated....\n");
		int p, num;		
		scanf("%d", &num);
		p=1;
		while (num!=0)
			{
			p=p*num;
			num=num-1;
			}
		printf("The factorial of the given number is: %d \n",p);

	}
	else
	{
		printf("Parent process being executed....\n");
		printf("Enter the number of terms in the desired fibonacci series...\n");
		int f1,f2,f3,n,i,s;
		scanf("%d", &n);
		f1=0;
		f2=1;
		s=1;
		for(i=0;i<(n-2);i++)
			{
			f3=f1+f2;
			s=s+f3;
			f1=f2;
			f2=f3;
			}
		printf("The sum of the fibonacci series is:%d \n",s);
		
	}
}	
