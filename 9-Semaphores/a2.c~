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
	int i=0;
	key_t key=0210;
	for(i=1;i<1000;i++)
	{
		int semid=semget(key,i,0666|IPC_CREAT);
		if(semid==-1)
		{
			printf("Semaphore subset creation becomes unsuccessful now....\n");
			break;
		}
		semctl(semid,0,IPC_RMID);
	}

	printf("maximum number of sub-semaphores is : %d\n",i-1);

}
