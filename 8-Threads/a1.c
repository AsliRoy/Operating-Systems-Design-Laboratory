#include<stdio.h>
#include<pthread.h>
int z;
void *thread1()
{
	int z=pthread_self();
	printf("The current thread ID is:%d \n",z);
	int i=5,j=20;
	while(j!=0)
		j=j-1;
}


int main()
{

	pthread_t t1,t2;
	int c1,c2;
	c1=pthread_create(&t1,NULL,thread1,NULL);
	c2=pthread_create(&t2,NULL,thread1,NULL);
	sleep(2);
	int a= pthread_equal(t1,t2);
	if(a==0)
		printf("The current thread ID is :%d \n",z);
	else  
		printf("The current thread ID is different \n");
	return 0;

}
