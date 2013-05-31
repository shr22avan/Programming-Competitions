#include<stdio.h>
#include<stdlib.h>
#define ull unsigned long long int
#define MAX_SIZE 100000
int a[MAX_SIZE],best,n,c,sum;
int compare(const void *a, const void *b)
{
	return((*(int*)a)- (*(int*)b));
}
int possible(int m)
{
	int i,count=1,s=0;
	for(i=0;i<n-1;i++)
	{
		s+=(a[i+1]-a[i]);
		if(s>=m)
		{
			count++;
			s=0;
		}
	}
	return (count>=c);
}
void binary_search(int low,int high)
{
	int mid;
	while(low<=high)
	 {
		mid=(low+high)/2;
		if(possible(mid))
		{
			best=mid;	
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
}
int main()
{
	int t,i,val;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;best=-1;
		scanf("%d%d",&n,&c);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		qsort(a,n,sizeof(int),compare);
		sum=a[n-1]-a[0];
		binary_search(0,sum);
		printf("%d\n",best);
	}	
	return 0;
}
