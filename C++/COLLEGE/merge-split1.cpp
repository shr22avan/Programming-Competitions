#include<iostream>
#include<stdio.h>
#include<signal.h>
#include<cmath>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#include<ctime>
#include<algorithm>
#include<vector>
#include<atomic>
#define MAX_DATA 1000000
#define MAX_THREADS 1000
using namespace std;
atomic_int flag,flag1;
atomic_int oeflags[MAX_THREADS];
int data[MAX_DATA];
int data1[MAX_DATA];
pthread_t tid[MAX_THREADS];
pthread_attr_t attr;
int n,N,ctr;
atomic_int pid,semaphores[MAX_DATA];
int compare (const void * a, const void * b)
{
    return ( *((atomic_int*)a) - (*(atomic_int*)b) );
}
int dataLoss(){
	int freq[110]={0},freq2[110]={0};
	for(int i=0;i<n;i++)	freq[data1[i]]++;
	for(int i=0;i<n;i++)	freq2[data[i]]++;
	for(int i=0;i<110;i++)
		if(freq[i]!=freq2[i])
			return 1;
	return 0;
}
int issorted(int lo,int hi){
	bool flag=0;
	for(int i=lo+1;i<=hi;i++){
		if(data[i-1]>data[i])
			flag=1;			
	}
	if(flag)
		cout<<"False"<<endl;
	else
		cout<<"True"<<endl;
	ctr++;
}
void merge(int lo,int mid,int hi){
	int temp[MAX_DATA];
	int i=lo,j=mid+1,k=lo;
	while(i<=mid && j<=hi){
		if(data[i] <= data[j])
			temp[k++]=data[i++];
		else	temp[k++]=data[j++];
	}
	while(i<=mid)	temp[k++]=data[i++];
	while(j<=hi)	temp[k++]=data[j++];
	for(i=lo;i<=hi;i++)
		data[i]=temp[i];
}
void *runner(void *param1)
{
	int l1,u1,l2,u2,x;
	int pid1=(*(int*)param1-1);
	if(pid.load()<N)
	{
		pid++;		
		pthread_create(&tid[pid.load()-1],&attr,runner,&pid);
	}	
	l1=pid1*ceil(n/N);
	u1=l1+ceil(n/N)-1;
	if(u1>=n)
		u1=n-1;
	l2=u1+1;
	if(l2>=n)
		l2=n-1;
	u2=l2+ceil(n/N)-1;
	if(u2>=n)
		u2=n-1;
	if(pid1==N-1)
		u1=n-1;
	if(pid1==N-2)
		u2=n-1;
	oeflags[pid1]=ceil(N/2);		
	while(flag.load()==0);	
	semaphores[pid1].store(0);
	qsort(data+l1, u1-l1+1, sizeof(int), compare);
	flag1++;
	semaphores[pid1].store(1);
	//issorted(l1,u1);
	if(pid1==N-1)
		pthread_exit(0);
	while(flag1!=N);		
	do
	{
		if(pid1!=0 && pid1!=N-2)
		{
			while(semaphores[pid1-1].load()==0);
			while(semaphores[pid1+1].load()==0);
			if(pid1%2==0)
				while(((oeflags[pid1].load()!=oeflags[pid1-1].load())||(oeflags[pid1].load()!=oeflags[pid1+1].load())))
					;
					
			else{
				while(((oeflags[pid1].load()-1!=oeflags[pid1-1].load())||(oeflags[pid1].load()-1!=oeflags[pid1+1].load())))
					;				
			}
		}		
		else
		{
			if(pid1!=0 && pid1%2==0)
			{
				while(semaphores[pid1-1].load()==0);
				while(oeflags[pid1].load()!=oeflags[pid1-1].load())
				;
			}	
			else if(pid1!=0)
			{
				while(semaphores[pid1-1].load()==0);
				while(oeflags[pid1].load()!=oeflags[pid1-1].load()+1)
					;
			}
			else
			{
				while(semaphores[1].load()==0);
				while((N!=2 && (oeflags[0].load()!=oeflags[1].load())));				
			}
		}
		merge(l1,u1,u2);
//		cout<<oeflags[pid1]<<" "<<endl;		
		oeflags[pid1]--;
	}
	while(oeflags[pid1].load()>=0);
	pthread_join(tid[pid1+1],NULL);
	pthread_exit(0);
}
int main(int argc,char *argv[])
{	
	flag1=0;
	int flag2=0,i,j,k,l,m=0;	
	pid.store(0);
	flag.store(0);
	m=1;
	if(argc<3)
	{
		fprintf(stderr,"Requires 2 parameters <n> and <N>\n");
		return 1;
	}
	n=atoi(argv[1]),N=atoi(argv[2]);
	srand(time(NULL));
	for(i=0;i<n;i++)
	{
		data[i]=(rand()%100);
		data1[i]=(int)data[i];
	}
	pthread_attr_init(&attr);
	pid++;
	pthread_create(&tid[pid.load()-1],&attr,runner,&pid);
	while(pid.load()<N);
	clock_t t=clock();	
	flag.store(1);
	pthread_join(tid[0],NULL);	
	issorted(0,n-1);
	if(dataLoss()){
		puts("Aiyo Pocheeee");
	}
/*	for(i=0;i<n;i++){
		cout<<data[i]<<" ";
	}*/
//	cout<<endl<<endl;	
	/*t=clock()-t;
	t=clock();
	int x=data[0];
	bool flag=0;
	for(i=1;i<n;i++){
//		cout<<data[i]<<" ";
		if(data[i]<data[i-1])
			flag=1;
	}
//	cout<<endl;
	if(flag) cout<<"False"<<endl;
	else cout<<"True"<<endl;
	t=clock()-t;*/
//	cout<<ctr<<endl;
	return 0;
}
