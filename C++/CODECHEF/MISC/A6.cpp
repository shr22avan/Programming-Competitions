#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int powers10[10];
int fastpow(int a,int b,int mod)
{
	long long val;
	if(b==0)
	{
		val=1;
	}
	else if(b==1)
	{
		val=a;
	}
	else if(b%2==0)
	{
		val=fastpow(a,b/2,mod);
		val*=val;
	}
	else
	{
		val=fastpow(a,b/2,mod);
		val*=val;
		if(val>=mod)
			val%=mod;
		val*=a;
	}
	if(val>=mod)
		val%=mod;
	return val;

}
int func1(int n,int k)
{
	long long val=n*log10(n);
	val-=k;
	double v1=n*log10(n)-val-1;
	return pow(10.0,v1);
}
int func2(int n,int k)
{
	return fastpow(n,n,powers10[k]);
}
int main()
{
	int t,n,i,k,q,r;
	powers10[0]=1;
	for(i=1;i<10;i++)
		powers10[i]=powers10[i-1]*10;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		q=func1(n,k);
		r=func2(n,k);
		printf("%d %d\n",q,r);
	}
	return 0;
}
