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

union semun {
	int val; 						/* used for SETVAL only */
	struct semid_ds *buf; 					/* used for IPC_STAT and IPC_SET */
	int *array; 						/* used for GETALL and SETALL */
}arg;

int main()
{	int i,n;
	key_t key=0210;
	int semid=semget(key,10,0666|IPC_CREAT);
	int arg1[]={21,22,223,24,25};int arg2[5];
	arg.array=arg1;
	int gl=semctl(semid,5,SETALL,arg.array);
	gl=semctl(semid,5,GETALL,arg2);
	for( i=0;i<5;i++)
	{printf("%d  ",arg2[i]);}
	if(gl==-1)
		printf("Semaphore creation becomes unsuccessful...\n");
	else

	semctl(semid,0,IPC_RMID);
	
}
