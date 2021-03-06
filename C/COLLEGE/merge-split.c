#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define MAX_DATA 1000000
#define MAX_THREADS 100
using namespace std;
int data[MAX_DATA],flag=0,flag1=0,odd_even_flags[MAX_THREADS];
pthread_t tid[MAX_THREADS];
pthread_attr_t attr;
int pid=0,n,N;
void *runner(void *param1)
{
	int pid1=*(int*)(param1);
	if(pid<N)
	{
		pid++;
		pthread_create(&tid[pid-1],&attr,runner,&pid);
	}	
	pid1--;
	int l1,u1,l2,u2;
	l1=i*n/N;
	u1=l1+(n/N)-1;
	l2=u1+1;
	u2=l2+(n/N)-1;
	while(!flag);
	qsort(data+l1,data+u1);	
	while(!flag1);
	if(pid1+1<n)
		pthread_join(tid[pid1+1],NULL);
	pthread_exit(0);
}
int main(int argc,char *argv[])
{	
	int flag2=0;
	if(argc<3)
	{
		fprintf(stderr,"Requires 2 parameters <n> and <N>\n");
		return 1;
	}
	int i,j,k,l,m;
	n=atoi(argv[1]),N=atoi(argv[2]);
	srand(time(NULL));
	for(i=0;i<n;i++)
		data[i]=rand();
	pthread_attr_init(&attr);
	pid++;
	pthread_create(&tid[pid-1],&attr,runner,&pid);
	while(pid<N);
	flag=1;
	flag1=1;
	pthread_join(tid[0],NULL);	
	return 0;
}
