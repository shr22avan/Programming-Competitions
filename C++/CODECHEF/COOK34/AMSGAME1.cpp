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
	int t,n,a[1000],k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		if(n==1)
		{
			printf("%d\n",a[0]);
			continue;
		}
		k=gcd(a[0],a[1]);
		for(int i=2;i<n;i++)
		{
			k=gcd(k,a[i]);
		}
		printf("%d\n",k);
				
	}
	return 0;
}
