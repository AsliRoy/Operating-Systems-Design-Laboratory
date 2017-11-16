#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<semaphore.h>

int main()
{
	sem_t mutex,full,empty;
	//int count=0;
	sem_init(&mutex,0,1);
	sem_init(&full,0,0);
	sem_init(&empty,0,10);
	int fd[2];
	
	if(pipe(fd)==2)
	{
		printf("error in pipe creation\n");
		exit(1);
	}

	pid_t pid=fork();
	
	if(pid<0)
	{
		printf("error in creating fork.\n");
		exit(1);
	}
	else if(pid==0)
	{
	
	while(1)
	{	int count;
		sem_wait(&full);
		read(fd[0],count,1);
		close(fd[0]);
		if(count==0)
		{
			sem_wait(&mutex);
		}		
		else
		{
			count--;
			printf("Consumer No. %d is now using the buffer\n",count); 
			//sleep(1);		
			sem_post(&mutex);
			sem_post(&empty);
		}
		write(fd[1],count,1);	
	}
	}
	else
	{
	while(1)
	{
		int count;
		sem_wait(&full);
		read(fd[0],count,1);
		close(fd[0]);
		if(count==0)
		{
			sem_wait(&mutex);
		}		
		else
		{
			count--;
			printf("Consumer No. %d is now using the buffer\n",count); 
			//sleep(1);		
			sem_post(&mutex);
			sem_post(&empty);
		}
		write(fd[1],count,1);	
	}
	}

return 0;
}

