#include<iostream>
#include<stdio.h>
#include<cmath>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#include<ctime>
#include<algorithm>
#include<atomic>
using namespace std;

#define MAX_DATA 2000000
#define MAX_THREADS 1000

atomic_int initComplete;			//Checks for initialization of N threads
atomic_int isQsortComplete;			//Checks for completion of Step 1 (qsort of N segments)
atomic_int timeToLive[MAX_THREADS];		//No. of iterations pending for each segment
atomic_int threads;				//Maximum number of threads created so far

pthread_t tid[MAX_THREADS];			//Holds the thread ID of every thread created
pthread_attr_t attr;				//Thread attributes set to default

int n,uflag,tflag;						//Size of the data set
int N;						//Number of processors
int data[MAX_DATA];				//Input data set


int compare(const void *a, const void *b);
int issorted(int lo, int hi);
void merge(int lo, int mid, int hi);
void *runner(void *param1);

int main(int argc,char *argv[])
{
	int i;
	
	//Verify proper command line usage
	if(argc<3){
		fprintf(stderr,"Requires 2 parameters <n> and <N>\n");
		return 1;
	}
	
	//Initializing flags to zero
	isQsortComplete=0;
	threads.store(0);
	initComplete.store(0);
	
	//Getting the number of processors and data set size from command line
	n=atoi(argv[1]);
	N=atoi(argv[2]);
	
	//Initialize random generator
	srand(time(NULL));
	for(i=0;i<n;i++){
		//Filling the data set with random values in the range [0,1000)
		data[i]=(rand()%50);
	}
	
	//Initializing pthread attributes and creation of first thread
	pthread_attr_init(&attr);
	threads++;
	pthread_create(&tid[threads.load()-1],&attr,runner,&threads);
	
	//Polling until all threads are created and update the initComplete flag
	while(threads.load()<N);
	initComplete.store(1);
	
	//Join the first thread back to main()
	pthread_join(tid[0],NULL);
	
	//Verify if the array is sorted
	issorted(0,n-1);
	return 0;
}

int compare(const void * a,const void * b){
	/* 
	 * function compare()
	 * Compare 2 generic pointers
	 * arg1 : void * generic pointer a
	 * arg2 : void * generic pointer b 
	 */
	 
	return (*((atomic_int*)a) - (*(atomic_int*)b));
}
int issorted(int lo,int hi){
	/*
	 * function issorted()
	 * Verify if the input data set is sorted
	 * arg1: Lower limit of the array 
	 * arg2: Upper limit of the array
	 */
	 
	bool flag=0;
	for(int i=lo+1;i<=hi;i++){
		if(data[i-1]>data[i])
			flag=1;	
	}
	//if(flag)cout<<"Not Sorted"<<endl;
	//else	cout<<"Sorted"<<endl;
}
void merge(int lo,int mid,int hi){
	/*
	 * function merge()
	 * Merges two consecutive segments of the array
	 * arg1: Lower limit of the first segment
	 * arg2: Upper limit of the first segment
	 * arg3: Upper limit of the second segment
	 */
	
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
void display()
{
	if(uflag)
	{
	if(tflag)
		cout<<",\n";
	else
		tflag=1;
	cout<<"[";
	for(int i=0;i<n;i++)
	{
		if(i==0)
			cout<<data[i];
		else
			cout<<","<<data[i];
	}
	cout<<"]";}
}
void *runner(void *param1)
{
	/*
	 * function runner()
	 * Functional part of every thread
	 * arg1: The 1-indexed thread id of the current thread
	 */
	 
	int l1,u1,l2,u2;
	int currentThread = (*(int*)param1-1);	//Get index of current thread from the parameter of runner
	if(threads.load()<N){
		//Spawn the next thread until N threads are created in total
		threads++;
		pthread_create(&tid[threads.load()-1],&attr,runner,&threads);
	}
	if(currentThread==0)
	{
	cout<<"data=[";
	uflag=1;
	}
	//Assigning lower and upper bounds of array segments on which each thread will work on
	l1 = currentThread * ceil(n/N);
	u1 = l1 + ceil(n/N) -1;
	if(u1>=n)	u1=n-1;
	l2 = u1 + 1;
	if(l2>=n)	l2=n-1;
	u2 = l2 + ceil(n/N) -1;
	if(u2>=n)	u2=n-1;
	if(currentThread==N-1)	u1=n-1;
	if(currentThread==N-2)	u2=n-1;
	
	//Fix the number of iterations to be performed by the current thread
	timeToLive[currentThread]=ceil(N/2);

	//Polling until all the threads are created
	while(initComplete.load()==0);

	//Perform Quick sort on the segment assigned to the threads and update the semaphore isQsortComplete
	qsort(data+l1, u1-l1+1, sizeof(int), compare);
	isQsortComplete++;
	
	//The last thread is killed after performing Step-1 (Quick Sort)
	if(currentThread==N-1)	pthread_exit(0);

	//Polling until all the threads finish Step-1 (Quick Sort)
	while(isQsortComplete!=N);
	
	do{
		//Determine which segments should be sequentially merged (Segment ranges are stored in the threads as l1,u1,l2,u2)
		if(currentThread!=0 && currentThread!=N-2){
			if(currentThread%2==0)
				while( timeToLive[currentThread].load() != timeToLive[currentThread-1].load()
						|| timeToLive[currentThread].load() != timeToLive[currentThread+1].load() );

			else
				while( timeToLive[currentThread].load()-1 != timeToLive[currentThread-1].load()
					|| timeToLive[currentThread].load()-1!=timeToLive[currentThread+1].load() );
		}	
		else{
			if(currentThread!=0 && currentThread%2==0)
				while( timeToLive[currentThread].load() != timeToLive[currentThread-1].load() );
			else if(currentThread!=0)
				while( timeToLive[currentThread].load() != timeToLive[currentThread-1].load()+1 );
			else
				while( N!=2 && timeToLive[0].load() != timeToLive[1].load());
		}
		
		//Merge the chosen segments and decrement the no. of iterations left for the current thread
		merge(l1,u1,u2);
		timeToLive[currentThread]--;

	}while(timeToLive[currentThread].load()>0); //Repeat until the thread has no iterations left
	cout<<"]\n";
	//Join current thread with its next thread and exit
	pthread_join(tid[currentThread+1],NULL);
	pthread_exit(0);
}
