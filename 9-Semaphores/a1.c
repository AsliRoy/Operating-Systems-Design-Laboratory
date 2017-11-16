#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>


int main()
{
	int j,i=0;
	key_t key=0210;
	int sid[1000];
	for(i=1;i<1000;i++)
	{
		//printf("%d",i);
		int semid=semget(i,10,0666|IPC_CREAT);
		if(semid==-1)
		{printf("Semaphore creation becomes unsuccessful now...\n");break;}
		sid[i-1]=semid;
	}

	printf("Maximum number of semaphore sets available in the system is : %d\n",i-1);
	
	for(j=0;j<i-1;j++)
	{
		printf("%d \n",sid[j]);
		semctl(sid[j],0,IPC_RMID);
	}

}
