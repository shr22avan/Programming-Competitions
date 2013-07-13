#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#define MAXI 1000000001
#define LIMIT1 100000
#define LIMIT2 20
#define LIMIT3 3*LIMIT2
#define getint(n) scanf("%d",&n)
#define putintn(n) printf("%d\n",n)
#define putintc(a) printf("%d,",a);
using namespace std;
struct range
{
	int s,e;
}ranges[LIMIT1];
int times[LIMIT2];
int binary_search(int l,int u, int k)
{
	int mid;
	while(l<=u)
	{
		mid=(l+u)/2;
		if(times[mid]==k)
			return mid;
		if(times[mid]<k)
			l=mid+1;
		else
			u=mid-1;
	}
	return mid;
}
int main()
{
	int n,s,e,q,k,count=0,t;
	getint(n);
	for(int i=0;i<n;i++)
	{
		getint(s);
		getint(e);
		ranges[i].s=s;
		ranges[i].e=e;
	}
	getint(q);
	for(int i=0;i<q;i++)
	{
		count=0;
		getint(k);
		for(int j=0;j<k;j++)
		{
			getint(times[j]);
		}
		sort(times,times+k);
		for(int j=0;j<n;j++)
		{
			s=binary_search(0,k-1,ranges[j].s);
			if(times[s]>=ranges[j].s && times[s]<=ranges[j].e)
				count++;
			else if(times[s]>ranges[j].e)
			{
				if(s-1>=0 && (times[s-1]>=ranges[j].s && times[s-1]<=ranges[j].e))
					count++;
			}
			else if(times[s]<ranges[j].s)
			{
				if(s+1<k && (times[s+1]>=ranges[j].s && times[s+1]<=ranges[j].e))
					count++;
			}
		}
		putintn(count);
	}
	return 0;
}
