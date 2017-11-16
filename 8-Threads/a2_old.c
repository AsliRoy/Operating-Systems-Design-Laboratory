#include<stdio.h>
#include<pthread.h>

void *matadd(void *p)
{
	int param= (int)p;
	printf("%d",param[0]);
	int i,j;
	//int *m=param[0];
	//int *n=param[1];
	//int k= param[2];
	//int l= param[3];
	//for(i=0;i<k;i++)
	//	for(j=0;j<l;j++)
	//		m[i][j]=m[i][j]+n[i][j];
			
}

int main()
{
	int i,j;
	int m[20][20],n[20][20];
	int a,b,c,d;
	printf("Enter the number of rows in the first array: \n");
	scanf("%d", &a);
	printf("Enter the number of columns in the first array: \n");
	scanf("%d", &b);
	printf("Enter the number of rows in the second array: \n");
	scanf("%d", &c);
	printf("Enter the number of columns in the second array: \n");
	scanf("%d", &d);
	if(a==c)
	{
		if(c==d)
			printf("Matrix addition is possible \n");
	}	
	else
		exit(1);
	printf("Enter the elements of first matrix: \n");
	for(i=0;i<a;i++)
		for(j=0;j<b;j++)
			scanf("%d",&m[i][j]);
	printf("Enter the elements of second matrix: \n");
	for(i=0;i<a;i++)
		for(j=0;j<b;j++)		
			scanf("%d",&n[i][j]);
	int p[4];
	p[0]=&m;
	p[1]=&n;
	p[2]=a;
	p[3]=b;
	pthread_t t;
	pthread_create(&t,NULL,matadd,&p);
	pthread_join(t,NULL);
	sleep(5);
	printf("The matrix after addition is:\n");
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
			printf("%d\t",m[i][j]);
		printf("\n");
	}
	return 0;
}
