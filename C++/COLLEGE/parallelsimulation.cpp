#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<time.h>
#define MAX_DATA 1000000
#define MAX_THREADS 1000000
#define INSTRUCTIONS_PER_TIME 10
int uflag=0,tflag=0;
struct object
{
int lo,hi;
}limits[MAX_THREADS];
using namespace std;
int data[MAX_DATA],n,N,t,count,count1,data1[MAX_DATA],counter,gcount;
void merge(int lo,int mid,int hi);
void mergesort(int lo,int hi);
void display();
void increase_count(int v);
void parallel_sim();
int main(int argc,char *argv[])
{
	int count2,time2;
	if(argc<2)
	{
		fprintf(stderr,"Usage: <n> <N>\n");
		return 1;
	}
	srand(time(NULL));
	n=atoi(argv[1]);
	N=atoi(argv[2]);
//	cout<<"Sequential Merge Sort:\n";
	for(int i=0;i<n;i++)
	/*{
		data1[i]=data[i]=50-i;
	}
	for(int i=50;i<100;i++)
	{
		data1[i]=data[i]=100-i;
	}*/	
//		data1[i]=data[i]=(rand()%50);
	count=count1=0;
	t=0;
//	mergesort(0,n-1);
	count2=count1;	
	time2=t;
//	cout<<"no. of instructions:"<<count1<<" time:"<<t<<endl;
	for(int i=0;i<n;i++)
		data[i]=data1[i]=rand()%50;
	count=count1=0;
	t=0;
	cout<<"data=[";
	uflag=1;
//	cout<<"Simulation of Parallel Merge-Split on "<<N<<" processors:"<<endl;
	parallel_sim();
	cout<<"]\n";
//	cout<<"no. of instructions:"<<count1<<"  "<<count2<<" time:"<<t<<"  "<<time2<<endl;
	return 0;
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
void increase_count(int v)
{
	count+=v;
	count1+=v;
	if(count>INSTRUCTIONS_PER_TIME)
	{
		count%=INSTRUCTIONS_PER_TIME;
		t++;
	//	display();
	}
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
	increase_count(3);
	while(i<=mid && j<=hi){
	display();
		if(data[i] <= data[j])
			temp[k++]=data[i++];
		else
			temp[k++]=data[j++];
		increase_count(5);
	}
	while(i<=mid){	temp[k++]=data[i++],increase_count(4);};
	while(j<=hi){	temp[k++]=data[j++],increase_count(4);};
	for(i=lo,increase_count(1);i<=hi;i++,increase_count(3))
		data[i]=temp[i];
}
void merge_without_count(int lo,int mid,int hi){
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
	//display();
		if(data[i] <= data[j])
			temp[k++]=data[i++];
		else
			temp[k++]=data[j++];
	}
	while(i<=mid){temp[k++]=data[i++];};
	while(j<=hi){	temp[k++]=data[j++];};
	for(i=lo;i<=hi;i++)
		data[i]=temp[i];
}

void mergesort(int lo,int hi)
{ 
	if(lo<hi)
	{
		int mid=(lo+hi)/2;
		increase_count(2);
		mergesort(lo,mid);
		mergesort(mid+1,hi);
		merge(lo,mid,hi);
	}
}	
void quick_sort(int left,int right)
{
	int pivot, l_hold, r_hold;

	l_hold = left;
	r_hold = right;
	pivot = data[left];
	while (left < right){
		while ((data[right] >= pivot) && (left < right))
			right--;
		if (left != right){
			data[left] = data[right];
			left++;
		}
		while ((data[left] <= pivot) && (left < right))
			left++;
		if (left != right){
			data[right] = data[left];
			right--;
		}
	}
	data[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot)
		quick_sort(left, pivot-1);
	if (right > pivot)
		quick_sort(pivot+1, right);
}
void quick_sort_with_count(int lo,int hi) {
	int pivot, l_hold, r_hold;
	l_hold = lo;
	r_hold = hi;
	pivot = data[lo];
	increase_count(3);
	while (lo < hi){
		while ((data[hi] >= pivot) && (lo < hi))
		hi--,increase_count(3);
		if (lo != hi){
			data[lo] = data[hi];
			lo++;
			increase_count(3);
		}
		while ((data[lo] <= pivot) && (lo < hi))
			lo++,increase_count(3);
		if (lo != hi){
			data[hi] = data[lo];
			hi--;
			increase_count(3);
		}
	}
	data[lo] = pivot;
	pivot = lo;
	lo = l_hold;
	hi = r_hold;
	increase_count(4);
	increase_count(1);	
	if(lo < pivot)
		quick_sort_with_count(lo, pivot-1);
	if(hi > pivot)
		quick_sort_with_count(pivot+1, hi);
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
		//cout<<data[i]<<"  ";
		if(data[i-1]>data[i])
			flag=1;	
	}
//	if(flag)cout<<"Not Sorted"<<endl;
//	else	cout<<"Sorted"<<endl;
}

void parallel_sim()
{
	int l1=0,u1=ceil(n/N)-1,u2;
	//Step 1
	counter=0;
	display();
	for(int i=0;i<=N-1;i++)
	{
		limits[counter].lo=l1;
		limits[counter].hi=u1;
		if(i==N-1)
			quick_sort_with_count(l1,u1);
		else
			quick_sort(l1,u1);
		l1=u1+1;
		u1=l1+floor(n/N)-1;
		if(u1>n)
			u1=n-1;
		counter++;
//		cout<<"l1:"<<l1<<" u1:"<<u1<<endl;
	}
	limits[counter].lo=l1;
	limits[counter].hi=n-1;
	quick_sort_with_count(l1,u1);
//	cout<<"Sorted:"<<endl;
	//display();
	//Step 2
	for(int i=0;i<=(N/2)+1;i++)
	{
		display();
		for(int j=1;j<=N-1;j+=2)
		{
			if(j==N-1)
				merge(limits[j-1].lo,limits[j-1].hi,limits[j].hi);
			else
				merge_without_count(limits[j-1].lo,limits[j-1].hi,limits[j].hi);					
//			cout<<j<<":"<<limits[j-1].lo<<":"<<limits[j-1].hi<<":"<<limits[j].hi<<endl;
		}
		display();
		for(int j=2;j<=N-1;j+=2)
		{
			if(j==N-1)
				merge(limits[j-1].lo,limits[j-1].hi,limits[j].hi);
			else
				merge_without_count(limits[j-1].lo,limits[j-1].hi,limits[j].hi);
//			cout<<j<<":"<<limits[j-1].lo<<":"<<limits[j-1].hi<<":"<<limits[j].hi<<endl;			
		}
	}	
	display();
	issorted(0,n-1);
}
