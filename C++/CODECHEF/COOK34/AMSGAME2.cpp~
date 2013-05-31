#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int gcd(int a,int b)
{
	if(a==0)
		return b;
	if(b==0)
		return a;
	if(a==b)
		return a;
	if(a==1 || b==1)
		return 1;
	if(a>b)
		return gcd(a%b,b);
	if(b>a)
		return gcd(a,b%a);
}
int main()
{
	int t,n,a[1000],k,l;
	unsigned long long int count;
	scanf("%d",&t);
	while(t--)
	{
		count=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		if(n==1)
		{
			if(a[0]==1)
				printf("1\n");
			else
				printf("0\n");
			continue;
		}
		sort(a,a+n);
		for(int i=0;i<n;i++)
		{
			k=l=0;
			for(int j=i+1;j<n;j++)
			{
				if(gcd(a[i],a[j])==1)
					k++;
				else
					l++;
			}
			count+=((1<<k)-1)*(1<<l);	
		}
		printf("%lld\n",count);
				
	}
	return 0;
}
