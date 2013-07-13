#include<iostream>
#include<cstdio>
#include<algorithm>
#define getint(n) scanf("%lld",&n)
using namespace std;
int main()
{
	long long t,n,a[10000],v1,v2,v3;
	getint(t);
	while(t--)
	{
		getint(n);
		v1=v2=v3=0;
		for(int i=0;i<n;i++)
			getint(a[i]);
		sort(a,a+n);
		v3=v1=a[n-1]-a[0];
		v2=v1/5;
		v1%=5;
		v2+=v1/2;
		v1%=2;
		v2+=v1;
		for(int i=n-2;i>=0;i--)
		{
			a[i]+=v3;
			v1=a[i]-a[i+1];
			v3+=v1;
			v2+=v1/5;
			v1%=5;
			v2+=v1/2;
			v1%=2;
			v2+=v1;
		}
		printf("%lld\n",v2);
	}	
	return 0;
}
