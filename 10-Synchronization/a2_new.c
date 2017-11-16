#include<stdlib.h>
#include<pthread.h>
#include<errno.h>
#include<semaphore.h>

sem_t mutex,full,empty; //semaphore declaration
int count=0;
void *producer()   //producer block
{
	while(1)
	{
		sem_wait(&empty);
		if(count==10)
		{
			sem_wait(&mutex);
		}
		else		
		{
			count++;
			printf("producer No. %d is now using the buffer\n",count);
			//sleep(1);
			sem_post(&mutex);
			sem_post(&full);	
		}	
	}
}


void *consumer()  //consumer block
{
	while(1)
	{
		sem_wait(&full);
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
	}
}



int main()
{    
	sem_init(&mutex,0,1);   //semaphore initialization
	sem_init(&full,0,0);
	sem_init(&empty,0,10);
	pthread_t producer_id, consumer_id;
    	pthread_create(&producer_id, NULL, producer, NULL);
    	pthread_create(&consumer_id, NULL, consumer, NULL);
    	pthread_join(producer_id, NULL);
    	pthread_join(consumer_id, NULL);
	return 0;
}
	
