#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

	int a[1000];
	int sum=0;
	int n=0;
	void * add(void * arg)

	{
		for(int i=0;i<100;i++)
		{
			sum+=a[n];
			n++;
		}
	}
int main()
{
	
	for(int j=0;j<1000;j++)
	{
		a[j]=j;
	}
	
	pthread_t thread[10];
	
	for(int j=0;j<10;j++)
	{
		//P thread Create Four Paramete 1.Pointer to thread,2.specific attribute,3.Function,4.Argument to thread
		pthread_create(&thread[j],NULL,add,NULL);
	}
	
	for(int j=0;j<10;j++)
	{
		pthread_join(thread[j],NULL);
	}
	
	printf("The Sum %d",sum);
	return 0;	
}
