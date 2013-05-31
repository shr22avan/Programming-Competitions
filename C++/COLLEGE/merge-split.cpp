#include<iostream>
#include<stdio.h>
#include<cmath>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#include<ctime>
#include<algorithm>
#include<vector>
#define MAX_DATA 1000000
#define MAX_THREADS 100
using namespace std;
int flag=0,flag1=0,oeflags[MAX_THREADS];
vector<int> data,data1;
pthread_t tid[MAX_THREADS];
pthread_attr_t attr;
int pid=0,n,N;
void *runner(void *param1)
{
	int l1,u1,l2,u2,old1,old2,pid1=*(int*)(param1);
	if(pid<N)
	{
		pid++;
		pthread_create(&tid[pid-1],&attr,runner,&pid);
	}	
	pid1--;
	l1=pid1*ceil(n/N);
	u1=l1+ceil(n/N)-1;
	if(u1>=n)
		u1=n-1;
	l2=u1+1;
	u2=l2+ceil(n/N)-1;
	if(u2>=n)
		u2=n-1;
	while(!flag);
	sort(data.begin()+l1,data.begin()+u1+1);
//	cout<<"pid:"<<pid1<<endl;
	/*for(int k=0;k<n;k++)
		cout<<data[k]<<" ";
	cout<<endl;*/
	if(pid1==0 || pid1==N-1)
		oeflags[pid1]=N/2;
	else
		oeflags[pid1]=N;
	if(pid1==N-1)
		pthread_exit(0);
	if(pid1%2==0)
		old1=oeflags[pid1]+1,old2=oeflags[pid1+1]+1;
	else
		old1=oeflags[pid1],old2=oeflags[pid1+1];
	do
	{
		if(pid1!=0 && pid1!=N-2)
		{
			while((oeflags[pid1]!=(old1-1) && oeflags[pid1+1]!=(old2-1))){
				cout<<oeflags[pid1]<<"  "<<pid1<<endl;
			}
		}
		else
		{
			if(pid1==0)			
				while(oeflags[pid1+1]!=(old2-1));
			else
				while(oeflags[pid1]!=(old1-1));
		}
		merge(data.begin()+l1,data.begin()+u1,data.begin()+l2,data.begin()+u2,data.begin()+l1+1);
		cout<<pid1<<endl;
		old1=oeflags[pid1]-1;
		old2=oeflags[pid1+1]-1;
		oeflags[pid1]--;
		oeflags[pid1+1]--;
	}
	while(oeflags[pid1]>0 && oeflags[pid1+1]>0);
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
	data.resize(n);
	data1.resize(n);
	srand(time(NULL));
	for(i=0;i<n;i++)
	{
		data[i]=(rand()%100);
		data1[i]=data[i];
	}
	/*cout<<"Input Array:\n";
	for(int i=0;i<n;i++)
		cout<<data[i]<<" ";
	cout<<endl;*/
	pthread_attr_init(&attr);
	pid++;
	pthread_create(&tid[pid-1],&attr,runner,&pid);
	while(pid<N);
	clock_t t=clock();	
	flag=1;
	pthread_join(tid[0],NULL);	
	t=clock()-t;
	//cout<<"time:"<<t/(double)CLOCKS_PER_SEC<<endl;
	t=clock();
	for(i=0;i<n;i++){
		cout<<data[i]<<" ";
	}
//	sort(data1.begin(),data1.begin()+n);	
	t=clock()-t;
	//cout<<"time:"<<t/(double)CLOCKS_PER_SEC<<endl;
	/*for(int i=0;i<n;i++)
		cout<<data[i]<<" ";
	cout<<endl;*/
	return 0;
}
