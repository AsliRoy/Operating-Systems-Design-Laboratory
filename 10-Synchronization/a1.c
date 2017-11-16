#include<stdlib.h>
#include<pthread.h>
#include<errno.h>
#include<semaphore.h>

sem_t mutex,wsem;	//Semaphore declaration
int rdcount = 0;
void *reader_func(void *id)	//Reader Function
{
	//Entry section
	int i = (int) id;
	sem_wait(&mutex);
	rdcount++;
	if(rdcount == 1)
		sem_wait(&wsem);
	sem_post(&mutex);
	//Critical Section
	printf("\nReader no. %d is now in critical section.\n",i);
	sleep(1);
	printf("\nReader no. %d is leaving critical section.\n",i);

	//Exit Section
	sem_wait(&mutex);
	rdcount--;
	if(rdcount == 0)
		sem_post(&wsem);
	sem_post(&mutex);
}

void *writer_func(void *id)	//Writer Function
{
	//Entry Function
	int i = (int)id;
	sem_wait(&wsem);
	
	//Critical Section
	printf("\nWriter no. %d is now in critical section.\n",i);
	sleep(1);
	printf("\nWriter no. %d is leaving critical section.\n",i);
	
	//Exit Section
	sem_post(&wsem);
}

int main()
{
				
	sem_init(&mutex,0,1);		//Semaphore initialisation
	sem_init(&wsem,0,1);

	int j,k,l,rd=1,wr=1,x;
	pthread_t tid[10];
	for(j=0;j<10;j++)
	{
		l = rand() % 2;
		if(l == 0)
		{
			int x = pthread_create(&tid[j],NULL,reader_func, (void*)rd++);	//Thread creation.
			printf("\nReader is created\n");
			if(x)	//Error checking
				break;
			
		}
		else 
		{
			int x = pthread_create(&tid[j],NULL,writer_func, (void*)wr++);	//Thread Creation
			printf("\nWriter is created\n");
			if(x)	//Error checking
				break;
			
		}
	}
	for(k=0;k<10;k++)
		pthread_join(tid[k],NULL);		//Waiting for other threads
	
}
