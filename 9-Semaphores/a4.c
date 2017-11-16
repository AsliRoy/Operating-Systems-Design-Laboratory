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

	int i,n,val=1;
	key_t key=0210;
	int semid=semget(key,1,0666|IPC_CREAT);  
	semctl(semid,0,SETVAL,1); 
	pid_t pid=fork();

	if (pid==-1)
		printf("Fork creation is unsuccessful...\n");

	if(pid==0)
	{
		int op;
		struct sembuf *sop=(struct sembuf *) malloc(1*sizeof(struct sembuf)); 
		sop[0].sem_num=0;
		sop[0].sem_op=-1;
		op=semop(semid,sop,1);
		sleep(5);
	}
	else
	{
	while(val==1)
	{
		val=semctl(semid,0,GETVAL);
		printf("%d\n",val);
	}
	semctl(semid,0,IPC_RMID);	
	}
}
